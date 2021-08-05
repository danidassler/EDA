// DANIEL SANZ MAYO
#include <iostream>
#include <stdexcept>  // std::domain_error
#include <utility>    // std::move
#include <string>

using namespace std;

#include"deque_eda.h"
#include"83.h"

void resuelveCaso() {
	int c, n, num;
	cin >> c;
	for (int i = 0; i < c; i++) {
		ListaEnlazada<int> cola1;
		ListaEnlazada<int> cola2;
		cin >> n; 
		for (int i = 0; i < n; i++) {
			cin >> num;
			cola1.push_back(num);
		}
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> num;
			cola2.push_back(num);
		}
		cola1.engordar(cola2);
		cola1.print();
		cout <<endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}