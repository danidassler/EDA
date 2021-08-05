#pragma once
#include <stdexcept>
#include <utility>
#include <iostream>
#include <iomanip>
#include <istream>
#include <unordered_map>
#include <vector>
#include <list>
#include <iterator>
#include <map>

using namespace std;

class Libros {
private:
	struct infoLibro {
		int ejemplares;
		int veces_comprado;
		list<string>::iterator pl;
	};
	unordered_map<string, infoLibro> libreria;
	map<int, list<string>, greater<int>> top;
	const int max = 10;
public:

	void nuevoLibro(int n, string l) {
		if (libreria.count(l) == 1) {
			libreria[l].ejemplares += n;
		}
		else {
			libreria[l].ejemplares = n;
			libreria[l].veces_comprado = 0;
			// inicializamos el iterador
			top[0].push_front(l);
			libreria[l].pl = top[0].begin();
		}
	}

	void comprar(string l) {
		if (libreria.count(l) == 0) {
			throw invalid_argument("Libro no existente");
		}
		else if (libreria[l].ejemplares == 0) {
			throw out_of_range("No hay ejemplares");
		}
		else {
			auto it = libreria.find(l);
			top[it->second.veces_comprado].erase(it->second.pl);
			it->second.ejemplares = it->second.ejemplares - 1;
			it->second.veces_comprado = it->second.veces_comprado + 1;
			top[it->second.veces_comprado].push_front(l);
			it->second.pl = top[it->second.veces_comprado].begin();
		}
	}

	bool estaLibro(string l) {
		if (libreria.count(l) == 0) {
			return false;
		}
		else {
			return true;
		}
	}

	void elimLibro(string l) {
		if (libreria.count(l) == 0) {
			// no tiene efecto
		}
		else {
			auto it = libreria.find(l);
			top[it->second.veces_comprado].erase(it->second.pl);
			libreria.erase(it);
		}
	}

	int numEjemplares(string l) {
		if (libreria.count(l) == 0) {
			throw invalid_argument("Libro no existente");
		}
		else {
			return libreria[l].ejemplares;
		}
	}

	list<string> top10() {
		list<string> lista;
		for (auto it = top.begin(); it != top.end() && (int)lista.size() < max; ++it) {
			for (auto it_list = it->second.begin(); it_list != it->second.end() && (int)lista.size() < max; ++it_list) {
				if (it->first > 0)
					lista.push_back(*it_list);
			}
		}
		return lista;
	}

};
