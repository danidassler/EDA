#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

int becarios(int h, const int k, int n) {
	n++; // n es el nivel del arbol empieza en 0
	int mayor = 0;
	int tiempo;
	if (h == 0) {
		if (n-1 >= k) {
			n--;
			return 1;
		}
		else {
			n--;
			return 0;
		}
	}
	else {
		for (int i = 0; i < h; i++) {
			int c;
			cin >> c;
			tiempo = becarios(c, k, n);
			mayor = mayor + tiempo;
		}
		return mayor;
	}
}

bool resuelveCaso() {
	int k, n=0, h;
	cin >> k;
	if (!cin) return false;
	cin >> h;
	cout << becarios(h, k, n) << endl;
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}