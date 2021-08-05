#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

#include"bintree_eda.h"

template <class T>

class bintree_ext : public bintree<T> {

	using Link = typename bintree<T>::Link;

public:

	bintree_ext() : bintree<T>() {}

	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}

	size_t alt() const {
		return altura(this->raiz);
	}

	size_t hojas() const {
		return num_hojas(this->raiz);
	}

	size_t nodos() const {
		return num_nodos(this->raiz);
	}

	void front() {
		frontera(this->raiz);
		cout << endl;
	}

private:

	static size_t num_hojas(Link r) {
		if (r == nullptr) return 0;
		if (r->left == nullptr && r->right == nullptr) {
			return 1;
		}
		else {
			return (num_hojas(r->left) + num_hojas(r->right));
		}
	}

	static size_t num_nodos(Link r) {
		if (r == nullptr) return 0;
		else {
			return 1 + (num_nodos(r->left) + num_nodos(r->right));
		}
	}

	static size_t altura(Link r) {
		if (r == nullptr) {
			return 0;
		}
		else {
			return 1 + max(altura(r->left), altura(r->right));
		}
	}

	void frontera(Link r) {
		if (r == nullptr) {
			return;
		}
		else if (r->left == nullptr && r->right == nullptr) {
			cout << r->elem << " ";
		}
		else {
			frontera(r->left);
			frontera(r->right);
		}

	}
};

// lee un árbol binario de la entrada estándar

template <typename T>

bintree_ext<T> leerArbol_ext(T vacio) {

	T raiz;

	std::cin >> raiz;

	if (raiz == vacio) { // es un árbol vacío

		return {};

	}
	else { // leer recursivamente los hijos

		auto iz = leerArbol_ext(vacio);

		auto dr = leerArbol_ext(vacio);

		return { iz, raiz, dr };

	}

}