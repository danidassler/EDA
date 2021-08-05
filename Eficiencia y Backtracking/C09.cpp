#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

const int M = 1000000;

int cima(int V[], int N) {
	int i = 0;
	if (N > 1) {
		while (i < N - 1 && (V[i] > V[i + 1])) {
			i++;
		}
		while (i < N - 1 && (V[i] < V[i + 1])) {
			i++;
		}
		return i >= N - 1;
	}
	else return 1;
}

bool resuelveCaso() {
	int N;
	cin >> N;
	if (!cin) {
		return false;
	}
	int V[N];
	for (int i = 0; i < N; i++) {
		cin >> V[i];
	}
	cout << cima(V, N) << endl;
}

int main() {
	while (resuelveCaso());
	return 0;
}