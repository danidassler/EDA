#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

#include"bintree_eda.h"

int excursionistas(bintree<int> arbol, int &ex) {
	if (arbol.empty()) {
		ex = 0;
		return 0;
	}
	else {
		int gD, gI, exD, exI;
		gI = excursionistas(arbol.left(), exI);
		gD = excursionistas(arbol.right(), exD);
		ex = arbol.root() + max(exD, exI);
		int n = gI + gD;
		if (n == 0) {
			if (arbol.root() > 0) return 1;
			else return 0;
		}
		else {
			return n;
		}
	}
}

void resuelveCaso() {
	int c, sol, m = 0;
	cin >> c;
	for (int i = 0; i < c; i++) {
		int raiz = -1;
		bintree<int> arbol;
		arbol = leerArbol(raiz);
		sol = excursionistas(arbol, m);
		cout << sol << " " << m << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}