//DANIEL SANZ MAYO
#include <stdexcept>
#include <utility>
#include <iostream>
#include <iomanip>
#include <istream>

using namespace std;

#include"queue_eda.h"
#include"horas.h"
#include"82.h"

// esta con int para probar el nuevo algoritmo

void resuelveCaso(ListaEnlazada<int> &lista) {
	lista.elimDec();
	lista.print();
	cout << endl;
}

int main() {
	int num;
	int h;
	cin >> num;
	while (num != 0) {
		ListaEnlazada<int> lista;
		for (int i = 0; i < num; i++) {
			cin >> h;
			lista.push(h);
		}
		resuelveCaso(lista);
		cin >> num;
	}
}