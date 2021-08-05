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

bool resuelveCaso(const bintree<int> &arbol, int &edad, int &gen) {
	if (arbol.empty()) {
		gen = 0;
		return true;
	}
	else if (arbol.left().empty() && !arbol.right().empty()) {
		gen = 0;
		return false;
	}
	else if (arbol.left().empty() && arbol.right().empty()) {
		gen = 1;
		edad = arbol.root();
		return true;
	}
	else {
		int eI, eD, gI, gD;
		bool sI, sD;
		sI = resuelveCaso(arbol.left(), eI, gI);
		sD = resuelveCaso(arbol.right(), eD, gD);
		edad = arbol.root();
		if (sI) {
			gI++;
		}
		if (sD) {
			gD++;
		}
		gen = max(gD, gI);
		if (sI && sD) {
			if (arbol.right().empty()) {
				if (edad >= eI + 18) {
					gen = max(gD, gI);
					return true;
				}
				else {
					return false;
				}
			}
			else {
				if (edad >= eI + 18 && edad >= eD + 18 && eI >= eD + 2) {
					gen = max(gD, gI);
					return true;
				}
				else {
					return false;
				}
			}
		}
		else {
			return false;
		}
	}
}

// 90 60 31 -1 -1 30 11 -1 -1 8 -1 -1 57 39 15 -1 -1 -1 28 10 -1 -1 6 -1 -1
// 90 60 35 -1 -1 30 11 -1 -1 8 -1 -1 57 39 26 -1 -1 -1 28 10 -1 -1 6 -1 -1

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		bool vale;
		bintree<int> arbol;
		int raiz = -1;
		arbol = leerArbol(raiz);
		int a = 0;
		int g = 0;
		vale = resuelveCaso(arbol, a, g);
		if (vale == true) {
			cout << "SI " << g << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}