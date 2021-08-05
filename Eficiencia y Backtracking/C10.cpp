#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

int numPalabras(string frase, int N) {
	int j = 0, contador = 0;
	while (j < N) {
		if (frase[j] != ' ') {
			if ((j + 1 < N && frase[j + 1] == ' ') || j + 1 == N) {
				contador++;
			}
		}
		j++;
	}
	return contador;
}

void resuelveCaso() {
	string frase;
	long long int N;
	while (getline(cin, frase)) {
		N = frase.length();
		cout << numPalabras(frase, N) << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}