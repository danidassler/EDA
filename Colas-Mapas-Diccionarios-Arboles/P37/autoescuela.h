#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<unordered_map>
#include<map>

using namespace std;

class autoescuela {
private:
	map<string, pair <string, int>> diccA; // alumnos, par<prof, puntos>
public:

	autoescuela() {};

	void alta(string alumno, string profesor) {
		if (diccA.count(alumno) == 0) { // si no estaba matriculado en la autoescuela
			diccA[alumno].first = profesor;
			diccA[alumno].second = 0;
		}
		else { // si ya estaba de antes 
			diccA[alumno].first = profesor;
		}
	}

	bool es_alumno(string alumno, string profesor) {
		if (diccA[alumno].first == profesor) {
			return true;
		}
		else return false;
	}

	int puntuacion(string alumno) {
		if (diccA.count(alumno) == 0) {
			throw domain_error("El alumno " + alumno + " no esta matriculado");
		}
		else {
			return diccA[alumno].second;
		}
	}

	void actualizar(string alumno, int puntos) {
		if (diccA.count(alumno) == 0) {
			throw domain_error("El alumno " + alumno + " no esta matriculado");
		}
		else {
			diccA[alumno].second = diccA[alumno].second + puntos;
		}
	}

	vector<string> examen(string profesor, int puntos) {
		vector<string> lista;
		auto itA = diccA.begin();
		while (itA != diccA.end()) {
			if (itA->second.first == profesor && itA->second.second >= puntos) {
				lista.push_back(itA->first);
			}
			++itA;
		}
		return lista;
	}

	void aprobar(string alumno) {
		if (diccA.count(alumno) == 0) {
			throw domain_error("El alumno " + alumno + " no esta matriculado");
		}
		else {
			diccA.erase(alumno);
		}
	}

};