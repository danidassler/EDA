#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

const int M = 1000;

int unico(int ini, int fin, int V[]) {
	// la longitud del vector siempre va a ser impar
	//mirar hojas de atras del cuaderno para entenderlo
	int mitad = (fin + ini) / 2;
	int sol;
	if (mitad > 0) {
		if (V[mitad] == V[mitad - 1]) { 
			if (mitad % 2 == 1) { 
				sol = unico(mitad, fin, V);
			}
			else {
				sol = unico(ini, mitad, V);
			}
		}
		else if (V[mitad] == V[mitad + 1]) {
			if (mitad % 2 == 1) {
				sol= unico(ini, mitad, V);
			}
			else {
				sol = unico(mitad, fin, V);
			}
		}
		else {
			return mitad;
		}
	}
	else {
		return mitad;
	}

	return sol;
}

int unicoAux(int V[], int N) {
	if (N == 1) {
		return 0;
	}
	else {
		return unico(0, N, V);
	}
}

void resuelveCaso() {
	int casos, N;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		cin >> N;
		int V[M];
		for (int j = 0; j < N; j++) {
			cin >> V[j];
		}
		cout << unicoAux(V, N) << endl;
	}

}

int main() {
	resuelveCaso();
	return 0;
}