#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

const int M = 1000;

int elementoPerdido(int a[], int b[], int i, int j) {
	if (j - i == 0) {
		return a[i];
	}
	else if (j - i == 1) {
		if (a[i] == b[i]) {
			return a[j];
		}
		else {
			return a[i];
		}
	}
	else {
		int mitad = (j + i) / 2;
		if (a[mitad] == b[mitad]) {
			elementoPerdido(a, b, mitad, j);
		}
		else {
			elementoPerdido(a, b, i, mitad);
		}
	}
}

void resuelveCaso() {
	int C, N;
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> N;
		int v[N], w[N]; // aqui da error pero en el juez da bien ( uso M para que me compile en el visual)
		for (int j = 0; j < N; j++) {
			cin >> v[j];
		}
		for (int j = 0; j < N-1; j++) {
			cin >> w[j];
		}
		int sol = elementoPerdido(v, w, 0, N - 1);
		cout << sol << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}