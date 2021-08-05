#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

bool esValida(int sol[], int k) {
	bool ok = true;
	int i = 0;
	while (i < k && ok) {
		if (sol[i] == sol[k] || abs(sol[i]-sol[k]) == k - i) ok = false;
		else i++;
	}
	return ok;
}

void reinas(int sol[], int N, int k, int &soluciones) {
	for (int i = 0; i < N; i++) { // solo asignamos columnas , suponemos que nunca pueden estar en la misma fila
		sol[k] = i;
		if (esValida(sol, k)) {
			if (k == N - 1) {
				soluciones++;
			}
			else {
				reinas(sol, N, k + 1, soluciones);
			}
		}
	}
}

void resuelveCaso() {
	int M, N, soluciones = 0, sol[14];
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> N;
		reinas(sol, N, 0, soluciones);
		cout << soluciones << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}