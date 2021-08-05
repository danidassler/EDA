#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

long long int eliminarPar(long long int n) {
	long long int n2 = 0;
	if (n < 10) {
		if (n % 10 % 2 != 0) {
			return n;
		}
	}
	else {
		if (n % 10 % 2 != 0) {
			n2 = (eliminarPar(n / 10) * 10) + (n % 10);
		}
		else {
			return eliminarPar(n / 10);
		}
	}
	return n2;
}

bool resuelveCaso() {
	long long int numero;
	cin >> numero;
	if (!cin) return false;
	long long int sol = eliminarPar(numero);
	cout << sol << endl;
}

int main() {
	while (resuelveCaso());
	return 0;
}