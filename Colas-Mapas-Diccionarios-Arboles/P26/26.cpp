#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

#include"bintree_eda.h"

bool busqueda(bintree<int> arbol, int min, int max) {
	if (arbol.empty()) return true;
	else {
		bool okD, okI;
		okI = busqueda(arbol.left(), min, arbol.root());
		okD = busqueda(arbol.right(), arbol.root(), max);
		if (okI&&okD) {
			if (arbol.root() > min && arbol.root() < max) return true;
			else return false;
		}
		else return false;
	}
}

void resuelveCaso() {
	int c, alt = 0;
	cin >> c;
	for (int i = 0; i < c; i++) {
		bintree<int> arbol;
		bool ok = true;
		int raiz = -1;
		arbol = leerArbol(raiz);
		ok = busqueda(arbol, -1, 1000000);
		if (ok) cout << "SI" << endl;
		else cout << "NO" << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}