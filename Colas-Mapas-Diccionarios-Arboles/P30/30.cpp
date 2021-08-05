#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

void resuelveCaso() {
	int c;
	cin >> c;
	cin.ignore();
	for (int i = 0; i < c; i++) {
		map<string, int> prim, sec, mod; // prim viejos sec nuevos mod modificados
		string clave, linea;
		int valor;
		getline(cin, linea);
		stringstream ss1(linea);
		while (ss1 >> clave >> valor) {
			prim[clave] = valor;
		}
		getline(cin, linea);
		stringstream ss2(linea);
		while (ss2 >> clave >> valor) {
			if (prim.count(clave) == 1) {
				if (prim[clave] != valor) {
					mod[clave] = valor; // en modificados guardamos los modificados
				}
				prim.erase(clave); // en el diccionario hacemos que se queden los "eliminados"
			}
			else {
				sec[clave] = valor; // aqui se quedan los nuevos
			}
		}
		if (prim.empty() && mod.empty() && sec.empty()) {
			cout << "Sin cambios" << endl;
		}
		else {
			if (!sec.empty()) {
				cout << "+ ";
				auto it = sec.begin();
				while (it != sec.end()) {
					cout << it->first << " ";
					++it;
				}
				cout << endl;
			}
			if (!prim.empty()) {
				cout << "- ";
				auto it = prim.begin();
				while (it != prim.end()) {
					cout << it->first << " ";
					++it;
				}
				cout << endl;
			}
			if (!mod.empty()) {
				cout << "* ";
				auto it = mod.begin();
				while (it != mod.end()) {
					cout << it->first << " ";
					++it;
				}
				cout << endl;
			}
		}
		cout << "----" << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}