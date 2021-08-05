#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

#include"11.h"
#include"queue_eda.h"

void resuelveCaso() {
	int c, n;
	cin >> c;
	for (int i = 0; i < c; i++) {
		ListaDuplica<int> cola1, cola2;
		while (cin >> n && n != 0) {
			cola1.push(n);
		}
		while (cin >> n && n != 0) {
			cola2.push(n);
		}
		cola1.insertarOrdenado(cola2);
		cola1.print();
		cout << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}
