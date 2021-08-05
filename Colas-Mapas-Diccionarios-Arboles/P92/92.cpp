//DANIEL SANZ MAYO

#include <iostream>
#include <cmath>
#include <iomanip>
#include <istream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include "bintree_eda.h"

bool zurdo(bintree<char> arbol, int & des) {
	if (arbol.empty()) {
		des = 0;
		return true;
	}
	else if (arbol.left().empty() && arbol.right().empty()) {
		des = 1;
		return true;
	}
	else {
		int desI, desD;
		bool okI, okD;
		okI = zurdo(arbol.left(), desI);
		okD = zurdo(arbol.right(), desD);
		int aux1 = (desI + desD);
		int aux2 = (desI + desD) / 2; // total descendientes /2
		if (okD&&okI) {
			if (desI > aux2) {
				des = aux1+ 1;
				return true;
			}
			else {
				des = des + 1;
				return false;
			}
		}
		else {
			return false;
		}
	}
}

void resuelveCaso() {
	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		char raiz = '.';
		int des = 0;
		bintree<char> arbol;
		arbol = leerArbol(raiz);
		bool ok = zurdo(arbol, des);
		if (ok) cout << "SI" << endl;
		else cout << "NO" << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}