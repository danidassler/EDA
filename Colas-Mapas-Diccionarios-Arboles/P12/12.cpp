#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

#include"queue_eda.h"

bool resuelveCaso() {
	int n, s, num;
	queue<int> lista;
	cin >> n >> s;
	if (n == 0 && s == 0) return false;
	for (int i = 1; i <= n; i++) {
		lista.push(i);
	}
	int cont = 0;
	while (lista.size() != 1) {
		if (cont == s) {
			lista.pop();
			cont = 0;
		}
		else {
			int aux = lista.front();
			lista.pop();
			lista.push(aux);
			cont++;
		}
	}
	cout << lista.front() << endl;
}

int main() {
	while (resuelveCaso());
	return 0;
}