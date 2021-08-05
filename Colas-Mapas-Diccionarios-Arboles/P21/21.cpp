#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

#include"21.h"
#include"bintree_eda.h"

template <class T>
T menor(bintree<T> arbol) {
	if (arbol.left().empty() && arbol.right().empty()) {
		return arbol.root();
	}
	else {
		T m = arbol.root();
		if (!arbol.left().empty()) {
			m = min(m, menor(arbol.left()));
		}
		if (!arbol.right().empty()) {
			m = min(m, menor(arbol.right()));
		}
		return m;
	}
}

// ESTA HECHO TANTO EN LA CLASE EXTENDIDA COMO AQUI

bool resuelveCaso() {
	char c;
	cin >> c;
	if (!cin) return false;
	if (c == 'N') {
		bintree<int> arbol;
		int raiz = -1;
		arbol = leerArbol(raiz);
		cout << menor(arbol) << endl;
	}
	else if(c=='P') {
		bintree<string> arbol;
		string raiz = "#";
		arbol = leerArbol(raiz);
		cout << menor(arbol) << endl;
	}
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}
