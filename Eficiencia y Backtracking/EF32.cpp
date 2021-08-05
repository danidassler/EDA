#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

const int M = 1000;

bool esValida(int sol[], int k, int contCol[], int c_bombilla[], int TW, int numC, int maxC, int& sumTotCol) {
	bool ok = true;
	contCol[sol[k]]++; // marcaje
	sumTotCol++; //marcaje
	TW = TW+c_bombilla[sol[k]]; // marcaje
	if (k > 1 && sol[k] == sol[k - 1] && sol[k] == sol[k - 2]) {
		ok = false;
	}
	if (contCol[sol[k]] > sumTotCol - contCol[sol[k]] + 1) {
		ok = false;
	}
	if (TW > maxC) {
		ok = false;
	}
	contCol[sol[k]]--; //desmarcamos
	sumTotCol--; //desmarcamos
	TW = TW-c_bombilla[sol[k]]; //desmarcamos
	return ok;
}

void luces(int sol[], int k, int TW, int l, int numC, int maxC, int c_bombilla[], int contCol[], int &soluciones, int &sumTotCol) {
	for (int i = 0; i < numC; i++) {
		sol[k] = i;
		if (esValida(sol, k, contCol,c_bombilla, TW, numC, maxC, sumTotCol)) {
			if (k == l - 1) soluciones++;
			else {
				contCol[sol[k]]++; // marcaje
				sumTotCol++;//marcaje
				TW = TW + c_bombilla[sol[k]]; // marcaje
				luces(sol, k + 1, TW, l, numC, maxC, c_bombilla, contCol, soluciones, sumTotCol);
				contCol[sol[k]]--; // desmarcamos
				sumTotCol--; // desmarcamos
				TW = TW - c_bombilla[sol[k]]; //desmarcamos
			}
		}
	}
}

bool resuelveCaso() {
	int l, numC, maxC,sol[M], c_bombilla[M], contCol[M], soluciones=0, sumTotCol=0;
	cin >> l >> numC >> maxC;
	if (!cin) return false;
	for (int i = 0; i < numC; i++) {
		cin >> c_bombilla[i];
		contCol[i] = 0;
	}
	luces(sol, 0, 0, l, numC, maxC, c_bombilla, contCol, soluciones, sumTotCol);
	cout << soluciones << endl;
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}