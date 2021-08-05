// DANIEL SANZ MAYO
#include <iostream>
#include <stdexcept>  // std::domain_error
#include <utility>    // std::move
#include <string>

using namespace std;

#include"81.h"
#include"queue_eda.h"

void resuelveCaso() {
	int n;
	cin >> n;
	while (n != 0) {
		ListaEnlazada<string> cola;
		string h;
		for (int i = 0; i < n; i++) {
			cin >> h;
			cola.push(h);
		}
		cola.elim();
		cola.print();
		cout << endl;
		cin >> n;
	}
}

int main() {
	resuelveCaso();
	return 0;
}