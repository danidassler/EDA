#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

#include"19.h"
#include"bintree_eda.h"

void resuelveCaso() {
	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		int altura, nodos, hojas;
		char raiz = '.';
		bintree_ext<char> arbol;
		arbol=leerArbol_ext(raiz);
		altura = arbol.alt();
		nodos = arbol.nodos();
		hojas = arbol.hojas();
		cout << nodos <<" "<< hojas << " " << altura << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}