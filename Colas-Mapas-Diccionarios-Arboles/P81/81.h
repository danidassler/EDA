
// DANIEL SANZ MAYO
#include <stdexcept>
#include<iostream>

#include "queue_eda.h"



template <class T>

class ListaEnlazada : public queue<T> { // herencia de queue
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
public:
	// mostrar por pantalla los elementos de la lista 
	void print(std::ostream & o = std::cout) const {

		Nodo *actual = this->prim;
		while (actual != nullptr) {
			o << actual->elem << " ";
			actual = actual->sig;
		}

	}

	void libera2() {

		this->libera();
	}

	void elim() {
		int cont = 0;
		Nodo*actual = this->prim;
		Nodo*aux1 = nullptr;
		Nodo*aux2 = nullptr;
		while (actual != nullptr) {
			if (cont % 2 == 0) {
				aux1 = actual;
				actual = actual->sig;
			}
			else {
				aux2 = actual->sig;
				aux1->sig = aux2;
				actual = aux2;
			}
			cont++;
		}
		this->ult = aux1;
		this->nelems = this->nelems - (this->nelems / 2);
	}

};