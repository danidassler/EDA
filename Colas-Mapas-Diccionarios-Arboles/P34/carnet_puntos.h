#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<unordered_map>

using namespace std;

class carnet_puntos {
private:
	unordered_map<string, int> dicc;
	int vector[16] = {};
public:
	void nuevo(string dni) {
		if (dicc.count(dni) == 0) {
			dicc[dni] = 15;
			vector[15]++;
		}
		else {
			throw domain_error("Conductor duplicado");
		}
	}
	void quitar(string dni, int puntos) {
		if (dicc.count(dni) == 0) {
			throw domain_error("Conductor inexistente");
		}
		else {
			if (puntos > dicc[dni]) {
				vector[dicc[dni]]--;
				dicc[dni] = 0;
				vector[0]++;
			}
			else {
				vector[dicc[dni]]--;
				dicc[dni] -=puntos;
				vector[dicc[dni]]++;
			}
		}
	}

	int consultar(string dni) {
		if (dicc.count(dni) == 0) {
			throw domain_error("Conductor inexistente");
		}
		else return dicc[dni];
	}

	int cuantos_con_puntos(int puntos) {
		if (puntos < 0 || puntos > 15) {
			throw domain_error("Puntos no validos");
		}
		else return vector[puntos];
	}
};
