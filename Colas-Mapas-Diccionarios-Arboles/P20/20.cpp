#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

#include"20.h"
#include"bintree_eda.h"

void frontera(bintree<int> arbol, vector<int> &v) {
	if (arbol.empty()) return;
	else if (arbol.right().empty() && arbol.left().empty()) {
		v.push_back(arbol.root());
	}
	else {
		frontera(arbol.left(), v);
		frontera(arbol.right(), v);
	}
}
 // ESTA HECHO DE LAS DOS FORMAS TANTO EN LA EXTENDIDA COMO AQUI
void resuelveCaso() {
	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		bintree<int> arbol;
		int raiz = -1;
		arbol = leerArbol_ext(raiz);
		vector<int> f;
		frontera(arbol, f);
		for (int i : f) {
			cout << i << " ";
		}
		cout << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}