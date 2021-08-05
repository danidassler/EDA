#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

#include"bintree_eda.h"

bool esPrimo(int n) {
	int div = 0;
	for (int i = 1; i < (n + 1); i++) {
		if (n%i == 0) {
			div++;
		}
	}
	if (div != 2) return false;
	else return true;
}

int primos(bintree<int> arbol, int alt, int & mi) {
	if (arbol.empty() || esPrimo(arbol.root())) {
		mi = alt;
		return 0;
	}
	else if (arbol.root() % 7 == 0) {
		mi = alt;
		return arbol.root();
	}
	else {
		int minI, minD;
		int izquierda = primos(arbol.left(), alt + 1, minI);
		int derecha = primos(arbol.right(), alt + 1, minD);
		if (izquierda != 0 && derecha != 0) {
			if (minD < minI) {
				mi = minD;
				return derecha;
			}
			else {
				mi = minI;
				return izquierda;
			}
		}
		else {
			if (izquierda != 0) { mi = minI; return izquierda; }
			if (derecha != 0) { mi = minD; return derecha; }
			else return 0;
		}
	}
}

void resuelveCaso() {
	int c, alt = 0;
	cin >> c;
	for (int i = 0; i < c; i++) {
		int min = -1;
		bintree<int> arbol;
		int raiz = -1;
		arbol = leerArbol(raiz);
		int val = primos(arbol, 1, min);
		if (val == 0) cout << "NO HAY" << endl;
		else {
			cout << val << " " << min << endl;
		}
	}
}

int main() {
	resuelveCaso();
	return 0;
}