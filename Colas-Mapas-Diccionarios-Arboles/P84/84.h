#include <stdexcept>
#include<iostream>

#include "queue_eda.h"


template <class T>

class ListaEnlazada : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
public:
	// mostrar por pantalla los elementos de la lista duplicada
	void print(std::ostream & o = std::cout) const {

		Nodo *actual = this->prim;
		while (actual != nullptr) {

			o << actual->elem << " ";
			actual = actual->sig;
		}

	}


	void invertir_segmento(int p, int l) {
		if (l == this->nelems) {
			this->invertir();
			return;
		}
		Nodo *act = this->prim;
		Nodo *ult = this->prim;
		Nodo *ant = this->prim;
		Nodo *inv = nullptr;
		for (int i = 0; i < l + p - 1; i++) {
			if (i<p - 2)
				ant = ant->sig;
			if (i < p - 1)
				act = act->sig;

			ult = ult->sig;
		}

		inv = ult;

		for (int e = 0; e < l&&act != nullptr; e++) {
			Nodo *a_mover = act;
			act = act->sig;
			a_mover->sig = inv;
			inv = a_mover;

		}
		if (p != 1) {
			ant->sig = inv;
		}
		else {
			this->prim = inv;
		}
	}
	void duplica() {
		Nodo *actual = this->prim;


		while (actual != nullptr) {
			Nodo *duplica = actual;
			actual = actual->sig;
			T elem = duplica->elem;

			Nodo *nuevo = new Nodo(elem);
			duplica->sig = nuevo;
			nuevo->sig = actual;
		}

	}




	void invertir() {
		Nodo *inv = nullptr;
		Nodo *actual = this->prim;

		while (actual != nullptr) {
			Nodo *a_mover = actual;
			actual = actual->sig;
			a_mover->sig = inv;
			inv = a_mover;

		}
		this->ult = this->prim;
		this->prim = inv;

	}

};


