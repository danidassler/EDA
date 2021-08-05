#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

const int M = 100000;

int colados(int V[], int N) {
	int i = N - 1, p = 0, m = V[N - 1];
	while (i >= 0) {
		if (V[i - 1] > m) p++;
		m = min(V[i - 1], m);
		i--;
	}
	return p;
}

void resuelveCaso() {
	int casos, N;
	cin >> casos;
	for (int j = 0; j < casos; j++) {
		cin >> N;
		int vector[N]; // aqui me da error pero al subirlo al juez me da bien, si pongo la M(maxima long) en el juez me da mal de esta forma 
		for (int a = 0; a < N; a++ ) {
			cin >> vector[a];
		}
		cout << colados(vector, N) << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}

// 3 2 1 5 9 4