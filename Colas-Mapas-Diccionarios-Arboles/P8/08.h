#include <stdexcept>
#include<iostream>

#include "queue_eda.h"



template <class T>

class ListaDuplica : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
public:
	// mostrar por pantalla los elementos de la lista duplicada
	void print(std::ostream & o = std::cout) const {

		Nodo *actual = this->prim;
		while (actual != nullptr) {
			o << actual->elem << " ";
			actual = actual->sig; // mrar si sale bien o hay que poner this
		}

	}

	void duplica() {
		Nodo * actual = this->prim; // nodo actual
		while (actual != nullptr) {
			Nodo * nuevo = new Nodo(actual->elem, actual->sig);  // nuevo nodo repetido
			actual->sig = nuevo;
			actual = nuevo->sig;
		}
	}

};