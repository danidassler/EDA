#include <iostream>
#include <stdexcept>  // std::domain_error
#include <utility>    // std::move
#include <string>

using namespace std;

#include"84.h"
#include"queue_eda.h"

bool resuelveCaso() {
	int n, p, l, num;
	cin >> n >> p >> l;
	if (!cin) return false;
	ListaEnlazada<int> cola;
	for (int i = 0; i < n; i++) {
		cin >> num;
		cola.push(num);
	}
	cola.invertir_segmento(p, l);
	cola.print();
	cout << endl;
	return true;
}

int main() {
	while(resuelveCaso());
	return 0;
}