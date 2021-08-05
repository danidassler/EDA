#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

const int M = 100;

void print(int sol[], int n) {
	for (int i = 0; i < n; i++) {
		cout << sol[i] << " ";
	}
	cout << endl;
}

bool esValida(int sol[], int cont[],int  i, int k) {
	bool ok = true;
	cont[i] = cont[i] + 1; // marcaje
	if (k == 0 && cont[i] <= i) ok = true;
	else if(k>0) {
		if (cont[i] <= i && sol[k] >= sol[k - 1]) ok = true;
		else ok = false;
	}
	cont[i] = cont[i] - 1; // desmarcaje
	return ok;
}

void timido(int sol[], int k, int ini, int fin, int n, int cont[]) {
	for (int i = ini; i <= fin; i++) {
		sol[k] = i;
		if (esValida(sol, cont, i, k)) {
			if (k == n - 1) {
				print(sol, n);
			}
			else {
				cont[i]++; // marcaje
				timido(sol, k + 1, ini, fin, n, cont);
				cont[i]--; // desmarcaje
			}
		}
	}
}

bool resuelveCaso() {
	int n, ini, fin, cont[M], sol[M];
	cin >> n;
	if (n == 0) return false;
	cin >> ini >> fin;
	for (int i = ini; i <= fin; i++) {
		cont[i] = 0;
	}
	timido(sol, 0, ini, fin, n, cont);
}

int main() {
	while (resuelveCaso());
	return 0;
}