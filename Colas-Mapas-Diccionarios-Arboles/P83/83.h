#include<iostream>
#include <stdexcept>
#include "deque_eda.h"



template <class T>

class ListaEnlazada : public deque<T> {
	using Nodo = typename deque<T>::Nodo; // para poder usar Nodo aquí
public:
	// mostrar por pantalla los elementos de la lista duplicada
	void print(std::ostream & o = std::cout) const {

		Nodo *actual = this->fantasma;
		actual = actual->sig;
		while (actual != this->fantasma) {
			o << actual->elem << " ";
			actual = actual->sig; // mrar si sale bien o hay que poner this
		}
		this->fantasma->sig = this->fantasma;
		this->fantasma->ant = this->fantasma;
	}

	void libera2() {

		this->libera();
	}

	void engordar(ListaEnlazada<int> &lista2) {
		int n = 0;
		Nodo *fantasma1 = this->fantasma;
		Nodo *actual2 = lista2.fantasma->sig;
		Nodo *aux1delante = this->fantasma->sig;
		Nodo *aux1detras = this->fantasma->ant;
		Nodo *aux2;
		while (actual2 != lista2.fantasma) {
			if (n % 2 == 0) {
				aux2 = actual2;
				actual2 = actual2->sig;
				if (this->nelems == 0 && n == 0) {
					aux1delante = aux2;
					aux1detras = aux2;
					aux1delante->ant = fantasma1;
					aux1delante->sig = fantasma1;
					aux1detras->sig = fantasma1;
					aux1detras->ant = fantasma1;
					fantasma1->sig = aux2;
				}
				else {
					aux1delante->ant = aux2;
					fantasma1->sig = aux2;
					aux2->ant = fantasma1;
					aux2->sig = aux1delante;
					aux1delante = aux2;
				}
			}
			else {
				aux2 = actual2;
				actual2 = actual2->sig;
				aux1detras->sig = aux2;
				fantasma1->ant = aux2;
				aux2->sig = fantasma1;
				aux2->ant = aux1detras;
				aux1detras = aux2;
			}
			n++;
		}
		this->nelems = this->nelems + lista2.nelems;
		lista2.fantasma->sig = nullptr;
		n = 0;

	}
	

};