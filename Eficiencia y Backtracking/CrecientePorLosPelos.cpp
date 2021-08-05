#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

const int M = 1000;

bool crecientesPelos(int v[], int ini, int fin) {
	int mitad = (ini + fin) / 2;
	if (fin - ini == 1) {
		if (v[fin] - v[ini] <= 1 && v[ini] <= v[fin]) return true;
		else  return  false;
	}
	else {
		/*if (ok) {
			crecientesPelos(v, ini, mitad, ok);
			if (ok) {
				crecientesPelos(v, mitad, fin, ok);
			}
		}*/
		bool i, d;
		i = crecientesPelos(v, ini, mitad);
		d = crecientesPelos(v, mitad, fin);
		if (i&&d) return true;
		else return false;
	}
}

bool crecientePelosAux(int v[], int n) {
	bool ok = true;
	if (n == 1) { return true; }
	else {
		return crecientesPelos(v, 0, n - 1);
		//return ok;
	}
}

void resuelveCaso() {
	int c, n, v[M];
	bool ok = false;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> v[j];
		}
		ok = crecientePelosAux(v, n);
		if (ok) cout << "SI" << endl;
		else cout << "NO" << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}