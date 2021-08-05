#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

void sumdivisible(int num, bool &ok) {
	int suma = 0, cont = 0, aux = num;
	if (num / 10 == 0) return;
	while (aux > 0) {
		suma = suma + (aux % 10);
		aux = aux / 10;
		cont++;
	}
	if (suma%cont == 0) {
		ok = true;
		sumdivisible(num / 10, ok);
	}
	else {
		ok = false;
	}
}

bool resuelveCaso() {
	int num;
	bool ok = true;
	cin >> num;
	if (num == 0) return false;
	sumdivisible(num, ok);
	if (ok) cout << "SI" << endl;
	else cout << "NO" << endl;
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}