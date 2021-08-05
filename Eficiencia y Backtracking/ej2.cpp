#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

const int M = 1000;

int ceros(int v[], int ini, int fin, int n) {
	int h = (ini + fin) / 2;
	if (v[h] == 1 && h == n - 2 && v[h] == v[h + 1]) return 0;
	if (v[h] != v[h + 1] && v[h] == 1) return ((n-1) - h);
	else if (v[h] == 0 && v[h] != v[h - 1]) return  ((n-1) - (h - 1));
	else if (v[h] == 1) {
		ceros(v, h, fin, n);
	}
	else if (v[h] == 0) {
		ceros(v, ini, h, n);
	}
}

int cerosAux(int v[], int n) {
	if (n == 0) return 0;
	if (n == 1) {
		if (v[0] == 0) return 1;
		if (v[0] == 1) return 0;
	}
	if (n == 2) {
		if (v[0] == 1 && v[1] == 1) return 0;
		else if (v[0] == 0) return n;
		else if (v[0] == 1 && v[1] == 0) return 1;
	}
	if (n > 2) {
		if (v[0] == 0) return n;
		else {
			return ceros(v, 0, n - 1, n);
		}
	}
}

void resuelveCaso() {
	int c, n, v[M], sol = 0;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> v[j];
		}
		sol = cerosAux(v, n);
		cout << sol << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}