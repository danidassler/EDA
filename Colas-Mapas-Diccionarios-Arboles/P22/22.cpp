#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

#include"bintree_eda.h"

int diametro(bintree<char> arbol, int &altura) {
	if (arbol.empty()) {
		altura = 0;
		return 0;
	}
	else if (arbol.left().empty() && arbol.right().empty()) {
		altura = 1;
		return 1;
	}
	else {
		int altI, altD, dI, dD;
		dI = diametro(arbol.left(), altI);
		dD = diametro(arbol.right(), altD);
		altura = 1 + max(altI , altD);
		return max(altI + altD + 1, max(dI, dD));
	}
}

void resuelveCaso() {
	int c, alt = 0;
	cin >> c;
	for (int i = 0; i < c; i++) {
		bintree<char> arbol;
		char raiz = '.';
		arbol = leerArbol(raiz);
		cout << diametro(arbol, alt) << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}

