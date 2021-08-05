#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "libros.h"

bool resuelveCaso() {
	std::string orden, lib;
	int lineas, ej;
	cin >> lineas;
	if (!std::cin)
		return false;

	Libros libreria;

	for (int i = 0; i < lineas; i++) {
		cin >> orden;

		if (orden == "nuevoLibro") {
			cin >> ej;
			cin.ignore();
			getline(cin, lib);
			libreria.nuevoLibro(ej, lib);
		}
		else if (orden == "comprar") {
			try {
				cin.ignore();
				getline(cin, lib);
				libreria.comprar(lib);
			}
			catch (invalid_argument e) {
				cout << e.what() << endl;
				cout << "---" << endl;
			}
			catch (out_of_range e) {
				cout << e.what() << endl;
				cout << "---" << endl;
			}
		}
		else if (orden == "estaLibro") {
			try {
				cin.ignore();
				getline(cin, lib);
				bool si = libreria.estaLibro(lib);
				if (si) {
					cout << "El libro " << lib << " esta en el sistema" << endl;
				}
				else {
					cout << "No existe el libro " << lib << " en el sistema" << endl;
				}
			}
			catch (invalid_argument e) {
				cout << "No existe el libro " << lib << " en el sistema" << endl;
			}
			cout << "---" << endl;
		}
		else if (orden == "elimLibro") {
			cin.ignore();
			getline(cin, lib);
			libreria.elimLibro(lib);
		}
		else if (orden == "numEjemplares") {
			try {
				cin.ignore();
				getline(cin, lib);
				int x = libreria.numEjemplares(lib);
				cout << "Existen " << x << " ejemplares del libro " << lib << endl;
				cout << "---" << endl;
			}
			catch (invalid_argument e) {
				cout << "No existe el libro " << lib << " en el sistema" << endl;
				cout << "---" << endl;
			}
		}
		else if (orden == "top10") {
			list<string> lista;
			lista = libreria.top10();
			for (auto l : lista) {
				cout << l << endl;
			}
			cout << "---" << endl;
		}
		else {
			cout << "OPERACION DESCONOCIDA\n";
		}
	}
	std::cout << "------\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}
