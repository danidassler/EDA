#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

const int M = 200000;

bool ruta(int v[], int N, int D) {
	int i = 0, cuesta = 0;
	while (i < N - 1) {
		if (v[i] < v[i + 1]) {
			cuesta = cuesta + (v[i + 1] - v[i]);
			if (cuesta > D) {
				return false;
			}
		}
		else {
			cuesta = 0;
		}
		i++;
	}
	return true;
}

bool resuelveCaso() {
	int D, N;
	cin >> D >> N;
	if (!cin) {
		return false;
	}
	int v[N]; // aqui da error pero en el juez da bien
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	if (ruta(v, N, D)) {
		cout << "APTA" << endl;
	}
	else {
		cout << "NO APTA" << endl;
	}
}

int main() {
	while (resuelveCaso());
	return 0;
}