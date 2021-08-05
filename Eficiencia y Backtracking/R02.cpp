#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

int invertir(int n, int &pot) {
	int num = 0;
	if (n < 10) {
		return n;
	}
	else {
		num = (invertir(n / 10, pot) + ((n % 10)*pot));
		pot = pot * 10;
		return num;
	}
}

bool resuelveCaso() {
	int numero, pot = 10;
	cin >> numero;
	if (!cin) {
		return false;
	}
	cout << invertir(numero, pot) << endl;
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}