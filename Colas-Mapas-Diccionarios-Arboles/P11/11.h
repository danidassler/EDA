#pragma once
#pragma once
#pragma once
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

	void invertir() {
		Nodo*actual = this->prim;
		Nodo*inverso = nullptr;
		while (actual != nullptr) {
			Nodo*mover = actual;
			actual = actual->sig;
			mover->sig = inverso;
			inverso = mover;
		}
		this->ult = this->prim;
		this->prim = inverso;
	}

	void insertar(ListaDuplica<int> &cola2, int p) {
		if (p == 0) {
			cola2.ult->sig = this->prim;
			this->prim = cola2.prim;
		}
		else if (p == this->nelems) {
			this->ult->sig = cola2.prim;
			this->ult = cola2.ult;
		}
		else {
			Nodo*actual = this->prim;
			int cont = 1;
			while (cont < p) {
				actual = actual->sig;
				cont++;
			}
			Nodo*aux = actual->sig;
			actual->sig = cola2.prim;
			cola2.ult->sig = aux;
		}
		this->nelems = this->nelems + cola2.nelems;
		cola2.prim = nullptr;
		cola2.ult = nullptr;
	}

	void insertarOrdenado(ListaDuplica<int> &cola2) {
	    if (cola2.empty()) {
			return;
		}
		else if (this->empty()) {
			this->prim = cola2.prim;
			this->ult = cola2.ult;
		}
		else if (cola2.prim->elem >= this->ult->elem) {
			this->ult->sig = cola2.prim;
			this->ult = cola2.ult;
		}
		else if (cola2.ult->elem <= this->prim->elem) {
			cola2.ult->sig = this->prim;
			this->prim = cola2.prim;
		}
		else if(cola2.empty()){
			return;
		}
		else if (this->empty()) {
			this->prim = cola2.prim;
			this->ult = cola2.ult;
		}
		else {
			Nodo * actual_l1 = this->prim;
			Nodo * actual_l2 = cola2.prim;
			Nodo * aux = this->prim;
			if (this->prim->elem > cola2.prim->elem) { // si el primero de la lista1 es mayor que el primero de la lista 2
				actual_l1 = cola2.prim;
				actual_l2 = this->prim;
				aux = actual_l1;
				this->prim = cola2.prim;
			}
			else if (this->prim->elem <= cola2.prim->elem) {// si el primero de la lista1 es menor que el primero de la lista 2
				actual_l1 = this->prim;
				actual_l2 = cola2.prim;
				aux = this->prim;
			}
			actual_l1 = actual_l1->sig; // el actual_l1 va a ser el mas pequeño de las 2 filas
			while (actual_l1 != nullptr) {
				if (actual_l2 == nullptr) {
					aux->sig = actual_l1;
					aux = aux->sig;
					actual_l1 = actual_l1->sig;
				}
				else if (actual_l1->elem <= actual_l2->elem) {
					aux->sig = actual_l1;
					aux = aux->sig;
					actual_l1 = actual_l1->sig;
				}
				else {
					aux->sig = actual_l2;
					aux = aux->sig;
					actual_l2 = actual_l2->sig;

				}

			}
			aux->sig = actual_l2;
			while (aux->sig != nullptr) {
				aux = aux->sig;
			}
			this->ult = aux;
		}
		this->nelems = this->nelems + cola2.nelems;
		cola2.prim = nullptr;
		cola2.ult = nullptr;
		cola2.nelems = 0;
	}
};