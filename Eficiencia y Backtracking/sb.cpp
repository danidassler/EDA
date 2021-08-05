#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

const int M = 100;

bool esValida(int sol[], int z) {
	int c = z, suma = 0;
	while (c >= 0) {
		suma = suma + sol[c];
		c--;
	}
	if (suma%(z+1) == 0) return true;
	else return false;
}

void sumdiv(int sol[],int z, int k, int &cont) {
	for (int i = 0; i < 10; i++) {
		sol[z] = i;
		if (esValida(sol, z)) {
			if (z == k-1) cont = cont + 1;
			else {
				sumdiv(sol, z + 1, k, cont);
			}
		}
	}
}

bool resuelveCaso() {
	int d, k, sol[M], cont = 0;
	cin >> d;
	if (d == 0) return false;
	cin >> k;
	sol[0] = d;
	sumdiv(sol, 1, k, cont);
	cout << cont << endl;
}

int main() {
	while (resuelveCaso());
	return 0;
}