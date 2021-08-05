#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

const int M = 1000;

void printSol(int sol[], int n) {
	for (int i = 0; i < n; i++) {
		cout << sol[i] << " ";
	}
	cout << endl;
}

bool esValida(int sol[],int n, int k, int d, int e, int cont[]) {
	bool ok = true;
	cont[sol[k]]++;
	if (k == 0) {
		if (sol[k] == e) ok = true;
		else ok = false;
	}
	else {
		if ((sol[k] - sol[k - 1] == 1 || sol[k] - sol[k - 1] == 0) && (cont[sol[k]] <= d && sol[k] >= sol[k - 1])) ok = true;
		else ok = false;
	}
	cont[sol[k]]--;
	return ok;
}

void generar(int sol[], int k, int n, int d, int e, int cont[]) {
	for (int i = e; i < n+e; i++) {
		sol[k] = i;
		if (esValida(sol, n, k, d, e, cont)) {
			if (k == n - 1) printSol(sol, n);
			else {
				cont[sol[k]]++;
				generar(sol, k+1, n, d, e,cont);
				cont[sol[k]]--;
			}
		}
	}
}

void resuelveCaso() {
	int c, d, n, sol[M], e, cont[M]; // cont es un vector donde se guardan cuantas veces aparece cada numero
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n >> d >> e;
		for (int j = 0; j <= n; j++) {
			cont[j] = 0;
		}
		generar(sol, 0, n, d, e, cont);
	}
}

int main() {
	resuelveCaso();
	return 0;
}