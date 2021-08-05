#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

const int M = 100;

bool esValida(int sol[], int k, int i, int am[], int ac[], int f[]) {
	bool ok = true;
	// si no se a usado y la anchura es valida
	if (f[i] == -1 && ac[i] >= am[k]) ok = true;
	else ok = false;
	return ok;
}

void maximizar(int sol[], int k, int n, int m, int am[], int ac[], int q[M][M], int f[], int& countA, int & count) {
	for (int i = 0; i < n; i++) { // f es para saber si la carretera ya ha sido asignada;
		sol[k] = q[k][i];
		if (esValida(sol, k, i, am, ac, f)) {
			if (k == m - 1) {
				for (int z = 0; z < m; z++) {
					countA = countA + sol[z];
				}
				if (countA > count) {
					count = countA;
				}
				countA = 0;
			}
			else {
				f[i] = 1; // marcamos
				maximizar(sol, k+1, n, m, am, ac, q, f, countA, count);
				f[i] = -1; // desmarcamos
			}
		}
	}
}

void resuelveCaso() {
	int c, m, n, am[M], ac[M], q[M][M], f[M], maximo=0, maximoAux=0, sol[M];
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> m >> n;
		for (int j = 0; j < m; j++) {
			cin >> am[j];
		}
		for (int j = 0; j < n; j++) {
			cin >> ac[j];
		}
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) cin >> q[j][k];
		}
		for (int k = 0; k < n; k++) f[k] = -1;
		maximizar(sol, 0, n, m, am, ac, q, f, maximoAux, maximo);
		cout << maximo << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}