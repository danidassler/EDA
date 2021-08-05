#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

const int M = 1000;

bool rotate(int v[], int w[], int N) {
	bool si = false;
	int i = 0, m = 0;
	// primero encontramos el "pivote"
	while (m <= N && !si) {
		if (v[0] == w[m]) {
			si = true;
		}
		else {
			m++;
		}
	}
	// despues comprobamos que se cumple la rotacion
	while (i<N) {
		if (v[i] != w[m]) {
			return false;
		}
		i++;
		m = ++m % N;
	}
	return true;
}

bool resuelveCaso() {
	int N;
	cin >> N;
	if (!cin) {
		return false;
	}
	int v[M], w[M];
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> w[i];
	}
	if (N > 0) {
		if (rotate(v, w, N)) cout << "TRUE" << endl;
		else cout << "FALSE" << endl;
	}
	else {
		cout << "TRUE" << endl;
	}
	return true;
}

int main() {
	while (resuelveCaso()) {

	}
	return 0;
}