#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

const int M = 1000;

void bandera(char V[], int N) {
	int i = 0, j = N - 1, w = 0;
	while (i <= j) {
		if (V[i] == 'w') {
			i++;
		}
		else if (V[i] == 'r') {
			V[i] = V[w];
			V[w] = 'r';
			w++;
			i++;
		}
		else if (V[i] == 'b') {
			V[i] = V[j];
			V[j] = 'b';
			j--;
		}
	}
}

void resuelveCaso() {
	int casos, N;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		cin >> N;
		char V[M];
		for (int j = 0; j < N; j++) {
			cin >> V[j];
		}
		bandera(V, N);
		for (int j = 0; j < N; j++) {
			cout << V[j];
		}
		cout << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}