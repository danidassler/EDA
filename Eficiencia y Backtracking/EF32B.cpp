#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

typedef enum { azul, rojo, verde } colores;

void printSol(int a, colores sol[], int contCol[]) {
	for (int i = 0; i < a; i++){
		switch (sol[i]) {
		case verde: cout << "verde"; break;
		case rojo: cout << "rojo"; break;
		case azul: cout << "azul"; break;
		}
		cout << " ";
    }
	cout << endl;
}

bool esValida(colores sol[], int k, int i, const int numCol[], int contCol[], int a) {
	bool ok = true;
	contCol[i]++; // marcamos
	if (sol[k - 1] == verde && sol[k] == verde) {
		ok = false;
	}
	else if (contCol[2] > contCol[0]) {
		ok = false;
	}
	else if (contCol[i]>numCol[i]) {
		ok = false;
	}
	else if (a % 2 == 0 && (contCol[0] + contCol[2]) > (a / 2) - 1) ok = false;
	else if (a % 2 != 0 && (contCol[0] + contCol[2]) > (a / 2)) ok = false;
	if (k == 0) {
		if (sol[k] != rojo) ok = false;
	}

	contCol[i]--; // desmarcamos
	return ok;
}

void torre(colores sol[],int k, int a, const int numCol[], int contCol[], bool & ok) {
	for (int i = 0; i < a; i++) {
		sol[k] = static_cast<colores>(i);
		if (esValida(sol, k, i, numCol, contCol, a)) {
			if (k == a - 1) {
				ok = true;
				printSol(a, sol, contCol);
			}
			else {
				contCol[i]++; // marcamos
				torre(sol, k + 1, a, numCol, contCol, ok);
				contCol[i]--; // desmarcamos
			}
		}
	}
}

bool resuelveCaso() {
	int a, numCol[3];
	colores sol[10000];
	int contCol[3]= { 0,0,0 };
	cin >> a >> numCol[0] >> numCol[1] >> numCol[2];
	if (a == 0 && numCol[0] == 0 && numCol[1] == 0 && numCol[2] == 0) {
		return false;
	}
	bool ok = false;
	torre(sol, 0, a, numCol, contCol, ok);
	if (!ok) {
		cout << "SIN SOLUCION" << endl;
	}
	else cout << endl;
}

int main() {
	while (resuelveCaso());
	return 0;
}