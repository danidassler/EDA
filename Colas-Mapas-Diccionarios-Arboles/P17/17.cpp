#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

int altura(int h) {
	int mayor = 1;
	int tiempo;
	if (h == 0) { // no tiene hijos
		return 1;
	}
	else {
		for (int i = 0; i < h; i++) {
			int c;
			cin >> c;
			tiempo=altura(c);
			if (tiempo > mayor) {
				mayor = tiempo;
			}
		}
		return mayor+1;
	}
}

void resuelveCaso() {
	int c, h;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> h;
		cout << altura(h) << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}