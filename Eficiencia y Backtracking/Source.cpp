#include<iostream>
#include<string>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<sstream>

using namespace std;

const int M = 10000;

void numDist(int v[], int ini, int fin, int & cont) {
	int h = (fin + ini) / 2;
	if (fin - ini == 1) cont++;
	else if (fin - ini == 2) {
		if (v[ini] == v[fin - 1]) cont++;
		else if (v[ini] != v[fin - 1]) cont += 2;
	}
	else {
		numDist(v, ini, h, cont);
		numDist(v, h, fin, cont);
		if (v[h] == v[h - 1]) cont--;
	}
}

int numDistAux(int v[], int k) {
	if (k == 1) return 1;
	if (k == 2) {
		if (v[0] == v[1]) return 1;
		else return 2;
	}
	else {
		int cont = 0;
		numDist(v, 0, k, cont);
		return cont;
	}
}

void resuelveCaso() {
	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		int k, v[M];
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> v[j];
		}
	}
}

int main() {
	resuelveCaso();
	return 0;
}