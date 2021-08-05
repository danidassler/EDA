#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

const int a = 1000, b = 1000;
/*
int degradado(int v[], int i, int j, bool &ok, int sumI, int sumD) {
	int mitad = i + j / 2;
	if (j - i == 1) {
		return v[i];
	}
	else {
		if (ok) {
			sumI = degradado(v, i, mitad, ok, sumI, sumD);
			sumD = degradado(v, mitad, j, ok, sumI, sumD);
			if (sumI > sumD) {
				ok = false;
			}
			else {
				return sumI + sumD;
			}
		}
		else {
			return -1;
		}
	}
}

bool resuelveCaso() {
	int n, m;
	cin >> n >> m;
	bool valido = true;
	if (!cin) {
		return false;
	}
	for (int i = 0; i < n; i++) {
		int v[a];
		int izd = 0, der = 0;
		for (int j = 0; j < m; j++) {
			cin >> v[j];
		}
		degradado(v, 0, m, valido, izd, der);
	}
	if (!valido) cout << "NO" << endl;
	else cout << "SI" << endl;
	return true;

}

int main() {
while (resuelveCaso());
return 0;
}

*/

const int M = 1000;

int degradadoG(int V[], int i, int j, bool& correct, int izq, int dcha) {
	int h = (i + j) / 2;

	if (j - i == 1) return V[i];
	else {
		if (correct) {
			izq = degradadoG(V, i, h, correct, izq, dcha);
			dcha = degradadoG(V, h, j, correct, izq, dcha);
			if (izq > dcha) correct = false;
			else return izq + dcha;
		}
		else return -1;
	}
}

void resuelveCaso() {
	int F, C;
	while (cin >> F >> C) {
		int V[C]; // aqui sale error pero en el juez esta bien asi
		bool correct = true;
		for (int i = 0; i < F; i++) {
			int izq = 0, dcha = 0;
			for (int j = 0; j < C; j++) cin >> V[j];
			degradadoG(V, 0, C, correct, izq, dcha);
		}
		if (!correct) cout << "NO" << endl;
		else cout << "SI" << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}
