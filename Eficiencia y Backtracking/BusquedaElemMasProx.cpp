#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

const int M = 1000;

int cercano(int v[], int ini,int fin, int x) {
	int h = (ini + fin) / 2;
	if (fin - ini == 1) {
		int i = abs(x - v[ini]);
		int d = abs(v[fin] - x);
		if (i <= d) return v[ini];
		else return v[fin];
	}
	else {
		if (v[h] > x) {
			cercano(v, ini, h, x);
		}
		else if(v[h] < x) {
			cercano(v, h, fin, x);
		}
		else {
			return v[h];
		}
	}
}

void resuelveCaso() {
	int c, x, n, v[M], sol;
	cin >> c;
	for (int i = 0; i < c; i++ ) {
		cin >> x >> n;
		for (int j = 0; j < n; j++) {
			cin >> v[j];
		}
		sol = cercano(v, 0, n - 1, x);
		cout << sol << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}