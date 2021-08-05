#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

const int M = 10000;

int solve(int v[], int ini, int fin, const int c, bool &ok) {
	int mitad = (ini + fin) / 2;
	if (fin - ini == 1) {
		if (v[ini] == c + mitad) {
			return v[ini];
		}
		else {
			ok = false;
		}
	}
	else {
		if (v[mitad] > c + mitad) {
			return solve(v, ini, mitad, c, ok);
		}
		else if (v[mitad] < c+mitad) {
			return solve(v, mitad, fin, c, ok);
		}
	}
}

void resuelveCaso() {
	int C, N, num;
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> N >> num;
		int v[N]; // aqui da error pero en el juez da bien
		for (int j = 0; j < N; j++) {
			cin >> v[j];
		}
		bool ok = true;
		int sol = solve(v, 0, N, num, ok);
		if (ok) {
			cout << sol << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}

int main() {
	resuelveCaso();
	return 0;
}