#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

const int M = 1000;

/*const int M = 1000;

// iterativo
void heidi(int v[], int N, int l, int &mx, int &cont, int p[]) {
	int mismos = 1, j = N - 1, alt = 0;
	while (j >= 0) {
		alt = max(v[j], alt);
		if (j > 0 && v[j] == v[j - 1] && alt <= v[j]) {
			mismos++;
		}
		else {
			if (mismos >= mx && mismos >= l) {
				mx = mismos;
			}
			if (mismos >= l) {
				p[cont++] = (j + (mismos - 1));
				mismos = 1;
			}
		}
		j--;
	}
}

//recursivo

bool resuelveCaso() {
	int N, l, cont = 0, max = 0;
	cin >> N >> l;
	if (!cin) {
		return false;
	}
	int v[M];
	int a[M];
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	heidi(v, N, l, max, cont, a);
	cout << max << " " << cont << " ";
	for (int j = 0; j <cont; j++) {
		cout << a[j] << " ";
	}
	cout << endl;
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}*/

//recursivo
void heidi(int v[], int N, int l, int &mx, int &cont, int a[], int i, int c, int alt) {
	alt = max(v[i], alt);
	if (i > 0 && v[i] == v[i - 1] && alt <= v[i]) {
		c++;
		heidi(v, N, l, mx, cont,a, i - 1, c, alt);
	}
	else {
		if (c >= mx && c >= l) mx = c;
		if (c >= l) a[cont++] = (i + (c - 1));
		c = 1;
		if (i >= 0) {
			heidi(v, N, l, mx, cont, a, i - 1, c, alt);
		}
	}
}

void heidiAux(int v[], int N, int l, int &mx, int &cont, int a[]) {
	int i = N - 1, int c = 1, alt = 0;
	heidi(v, N, l, mx, cont, a, i, c, alt);
}

// iterativo
void buscarLlano(int V[], int N, int l, int& secMax, int& numTram, int A[]) {
	int i = N - 1, c = 1, aux = 0;
	while (i >= 0) {
		aux = max(V[i], aux);
		if (i>0 && V[i] == V[i - 1] && aux <= V[i]) c++;
		else {
			if (c >= secMax && c >= l) secMax = c;
			if (c >= l) A[numTram++] = (i + (c - 1));
			c = 1;
		}
		i--;
	}
}

void resuelveCaso() {
	int N, l;
	while (cin >> N >> l) {
		int V[M], A[M], secMax = 0, numTram = 0;
		for (int i = 0; i < N; i++) cin >> V[i];
		buscarLlano(V, N, l, secMax, numTram, A);
		cout << secMax << " " << numTram << " ";
		for (int j = 0; j < numTram; j++) cout << A[j] << " ";
		cout << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}