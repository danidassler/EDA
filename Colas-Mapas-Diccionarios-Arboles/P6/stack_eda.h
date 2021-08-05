#pragma once
#pragma once
/*Decimos que una secuencia de caracteres que, entre otros caracteres, contiene par´entesis, llaves y
corchetes abiertos y cerrados, est´a equilibrada si de cada uno de ellos tiene tantos abiertos como cerrados
y si cada vez que aparece uno cerrado, el ´ultimo que apareci´o a´un no emparejado fue su correspondiente
abierto*/
#ifndef parentesis_h
#define parentesis_h

#include <stdexcept>  // std::domain_error
#include <utility>    // std::move

template <class T>
class stack {
protected:
	static const int TAM_INICIAL = 10; // tamaño inicial del array dinámico

									   // número de elementos en la pila
	int nelems;

	// tamaño del array
	int capacidad;

	// puntero al array que contiene los datos (redimensionable)
	T * array;

public:

	// constructor: pila vacía
	stack() : nelems(0), capacidad(TAM_INICIAL), array(new T[capacidad]) {}

	// destructor
	~stack() {
		libera();
	}

	// constructor por copia
	stack(stack<T> const& other) {
		copia(other);
	}

	// operador de asignación
	stack<T> & operator=(stack<T> const& other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	// apilar un elemento
	void push(T const& elem) {
		if (nelems == capacidad)
			amplia();
		array[nelems] = elem;
		++nelems;
	}

	// consultar la cima
	T const& top() const {
		if (empty())
			throw std::domain_error("la pila vacia no tiene cima");
		return array[nelems - 1];
	}

	// desapilar el elemento en la cima
	void pop() {
		if (empty())
			throw std::domain_error("desapilando de la pila vacia");
		--nelems;
	}

	// consultar si la pila está vacía
	bool empty() const {
		return nelems == 0;
	}

	// consultar el tamaño de la pila
	int size() const {
		return nelems;
	}

protected:

	void libera() {
		delete[] array;
	}

	// this está sin inicializar
	void copia(stack const& other) {
		capacidad = other.nelems + TAM_INICIAL;
		nelems = other.nelems;
		array = new T[capacidad];
		for (int i = 0; i < nelems; ++i)
			array[i] = other.array[i];
	}

	void amplia() {
		T * viejo = array;
		capacidad *= 2;
		array = new T[capacidad];
		for (int i = 0; i < nelems; ++i)
			array[i] = std::move(viejo[i]);
		delete[] viejo;
	}
};

#endif // stack_eda_h
