#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

const int M = 1000;

void bandera(int V[], int N) {
	int i = 0, aux;
	while(i<N-1){
		if (V[i] <= V[i + 1]) {
			i++;
		}
		else if (V[i] > V[i + 1]) {
			aux = V[i + 1];
			V[i + 1] = V[i];
			V[i] = aux;
			i--;
		}
	}
}

void resuelveCaso() {
	int casos, N;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		cin >> N;
		int V[N];
		for (int j = 0; j < N; j++) {
			cin >> V[j];
		}
		bandera(V, N);
		for (int j = 0; j < N; j++) {
			cout << V[j]<<" ";
		}
		cout << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}