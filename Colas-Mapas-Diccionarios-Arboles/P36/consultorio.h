#ifndef consultorio_h
#define consultorio_h
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<unordered_map>
#include<map>

using namespace std;

class Fecha {
private:
	int _dia;
	int _hora;
	int _minuto;

public:
	Fecha(int d = 0, int h = 0, int m = 0) {
		_dia = d; _hora = h; _minuto = m;
	}
	// observadoras
	int hora() const { return _hora; }
	int minuto() const { return _minuto; }
	int dia() const { return _dia; }

	bool operator < (Fecha const& f) const {
		return 24 * 60 * _dia + 60 * _hora + _minuto < 24 * 60 * f._dia + 60 * f._hora + f._minuto;
	}
};

class Consultorio {
private:
	// medico->(fecha->(paciente));
	unordered_map<string, map<Fecha, string>> consultorio;
public:
	void nuevoMedico(string m) {
		if (consultorio.count(m) == 0) {
			consultorio[m];
		}
		else {
			// skip
		}
	}

	void pideConsulta(string p, string m, Fecha f) {
		if (consultorio.count(m) == 0) {
			throw domain_error("Medico no existente");
		}
		else {
			if (consultorio[m].count(f)) throw std::domain_error("Fecha ocupada");
			else {
				consultorio[m][f] = p;
				// lo mismo que consultorio[m].insert({ f, p });
			}
		}
	}

	string siguientePaciente(string m) {
		if (consultorio.count(m) == 0) {
			throw domain_error("Medico no existente");
		}
		if (consultorio[m].empty()) {
			throw domain_error("No hay pacientes");
		}
		else {
			auto it = consultorio[m].begin();
			return it->second;
		}
	}
	
	void atiendeConsulta(string m) {
		if (consultorio.count(m) == 0) {
			throw domain_error("Medico no existente");
		}
		if (consultorio[m].empty()) {
			throw domain_error("No hay pacientes");
		}
		else {
			auto it = consultorio[m].begin();
			consultorio[m].erase(it);
		}
	}

	vector<string> listaPacientes(string m, int dia) {
		if (consultorio.count(m) == 0) {
			throw domain_error("Medico no existente");
		}
		if (consultorio[m].empty()) {
			vector<string> v = {};
			return v;
		}
		else {
			vector<string> v;
			auto it = consultorio[m].begin();
			while (it != consultorio[m].end()) {
				if (it->first.dia() == dia) {
					v.push_back(it->second);
					v.push_back(to_string(it->first.hora()));
					v.push_back(to_string(it->first.minuto()));
				}
				++it;
			}
			return v;
		}
	}

};
#endif