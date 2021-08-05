#pragma once
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


	void eliminar() {
		Nodo * actual = this->prim;
		Nodo * aux1 = this->prim->sig;
		Nodo * aux2 = this->prim->sig;
		int a = 0;
		int N = this->nelems;
		if (N == 1) {

		}
		else if (N == 2) {
			if (actual->elem > aux1->elem) {
				actual->sig = nullptr;
				this->ult = this->prim;
				this->nelems = 1;
			}
			else {
				this->nelems = 2;
			}
		}
		else {
			// el fallo esta aqui
			for (int i = 1; i<N; i++) {
				if (actual->elem > aux2->elem) {
					if (i == N - 1) {
						actual->sig = nullptr;
						this->ult = actual;
						a++;
					}
					else {
						aux2 = aux1->sig;
						aux1->sig = nullptr;
						actual->sig = aux2;
						aux1 = aux2;
						a++;
					}
				}
				else {
					if (i == N - 1) {
						actual = actual->sig;
						this->ult = actual;
					}
					else {
						actual = actual->sig;
						aux2 = aux2->sig;
						aux1 = aux1->sig;
					}
				}
			}
			this->nelems = N - a;
		}
	}
	 // ESTE NOSE PORQUE ME DA ERROR SI LO HAGO CON HORAS PERO EL ALGORITMO ESTA BIEN
	void elimDec() {
		Nodo*actual = this->prim;
		int cont = 0;
		Nodo*aux1 = nullptr;
		Nodo*aux2 = nullptr;
		Nodo*aux3 = nullptr;
		while (actual != nullptr && actual->sig!=nullptr) {
			aux3 = actual->sig;
			if (actual->elem <= aux3->elem) {
				actual = actual->sig;
			}
			else {
				aux1 = actual;
				actual = actual->sig;
				aux2 = actual->sig;
				aux1->sig = aux2;
				actual = aux1;
				cont++;
			}
		}
		this->nelems = this->nelems - cont;
		this->ult = aux1;
	}

};


