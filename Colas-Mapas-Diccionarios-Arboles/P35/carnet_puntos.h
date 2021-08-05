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

using namespace std;

class Carnet_Puntos {
private:
	unordered_map<string, pair <int, list<string>::iterator>> dicc;
	list<string> vector[16];
public:

	void nuevo(string dni) {
		if (dicc.count(dni) == 1) {
			throw domain_error("Conductor duplicado");
		}
		else {
			vector[15].push_front(dni);
			dicc.insert({ dni, {15, vector[15].begin()} });
		}
	}

	void quitar(string dni, int puntos) {
		if (dicc.count(dni) == 0) {
			throw domain_error("Conductor inexistente");
		}
		else {
			if (dicc[dni].first < puntos) {
				if (dicc[dni].first == 0) {

				}
				else {
					vector[dicc[dni].first].erase(dicc[dni].second);
					vector[0].push_front(dni);
					dicc[dni].first = 0;
					dicc[dni].second = vector[0].begin();
				}
			}
			else {
				int nuevos_p = dicc[dni].first - puntos;
				vector[dicc[dni].first].erase(dicc[dni].second);
				dicc[dni].first = nuevos_p;
				vector[nuevos_p].push_front(dni);
				dicc[dni].second = vector[nuevos_p].begin();
			}
		}
	}

	int consultar(string dni) {
		if (dicc.count(dni) == 0) {
			throw domain_error("Conductor inexistente");
		}
		else {
			return dicc[dni].first;
		}
	}

	int cuantos_con_puntos(int puntos) {
		if (puntos < 0 || puntos>15) {
			throw domain_error("Puntos no validos");
		}
		else {
			return vector[puntos].size();
		}
	}

	list<string> lista_por_puntos(int puntos) {
		if (puntos < 0 || puntos>15) {
			throw domain_error("Puntos no validos");
		}
		else {
			return vector[puntos];
		}
	}

	void recuperar(string dni, int puntos) {
		if (dicc.count(dni) == 0) {
			throw domain_error("Conductor inexistente");
		}
		else {
			int nuevos_p = dicc[dni].first + puntos;
			if (nuevos_p > 15) {
				if (dicc[dni].first == 15) {

				}
				else {
					vector[dicc[dni].first].erase(dicc[dni].second);
					vector[15].push_front(dni);
					dicc[dni].first = 15;
					dicc[dni].second = vector[15].begin();
				}
			}
			else {
				vector[dicc[dni].first].erase(dicc[dni].second);
				dicc[dni].first = nuevos_p;
				vector[nuevos_p].push_front(dni);
				dicc[dni].second = vector[nuevos_p].begin();
			}
		}
	}
};
