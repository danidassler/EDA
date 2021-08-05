#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

const int M = 100000;

#include"queue_eda.h"

int solve(int r, int clave[], int n, int secuencia[]) {
	vector<queue<int>> elems(r);
	int menor = n; // menor longitud de la secuencia que contiene la clave
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < r; j++) {
			if (secuencia[i] == clave[j]) elems[j].push(i);
		}
	}

	int i = 0;
	while (!elems[i].empty() && !elems[i + 1].empty()) {
		if (elems[i].front() > elems[i + 1].front()) {// si encontramos un elemento que no aparece en orden correcto se saca
			elems[i + 1].pop();
			i = 0; 
		}
		else {
			if (i == r - 2) { 
				int m = elems[r - 1].front() - elems[0].front() + 1;
				if (menor > m) menor = m;
				elems[0].pop();
				i = 0;
			}
			else {
				i++;
			}
		}
	}
	return menor;
}

bool resuelveCaso() {
	int r, n, num;
	//int clave[M], secuencia[M];
	cin >> r;
	int clave[r]; // en el juez da bien aunque aqui salga en rojo
	if (!cin) return false;
	for (int i = 0; i < r; i++) {
		cin >> num;
		clave[i] = num;
	}
	cin >> n;
	int secuencia[n];
	for (int i = 0; i < n; i++) {
		cin >> num;
		secuencia[i] = num;
	}
	cout << solve(r, clave, n, secuencia) << endl;
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}