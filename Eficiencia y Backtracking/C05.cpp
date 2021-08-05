#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

int pBinaria(int V[], int N) {
	int c1 = 0, c2 = N - 1, aux;
	while (N > 1 && c1 <= c2) {
		if (V[c1] >= 0) {
			c1++;
		}
		else if (V[c1] < 0) {
			aux = V[c2];
			V[c2] = V[c1];
			V[c1] = aux;
			c2--;
		}
	}
	if (N == 1 && V[0] >= 0) c1 = 1;
	return c1;
}

void resuelveCaso() {
	int casos, N, sol;
	const int M = 1000;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		cin >> N;
		int V[M];
		for (int j = 0; j < N; j++) {
			cin >> V[j];
		}
		sol = pBinaria(V, N);
		for (int j = 0; j < N; j++) {
			cout << V[j] << " ";
		}
		cout << endl << sol << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}