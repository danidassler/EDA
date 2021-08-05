#include <stdexcept>
#include <utility>
#include <iostream>
#include <iomanip>
#include <istream>
#include<sstream>
#include<vector>

using namespace std;

#include "consultorio.h"



bool resuelveCaso() {
	std::string orden, m, p;
	int punt, c, d, h, min;
	Consultorio con;
	std::cin >> c;
	if (!std::cin)
		return false;


	for( int i=0; i<c; i++) {
		cin >> orden;
		try {
			if (orden == "nuevoMedico") {
				cin >> m;
				con.nuevoMedico(m);
			}
			else if (orden == "pideConsulta") {
				cin >> p >> m >> d >> h >> min;
				Fecha f(d, h, min);
				con.pideConsulta(p, m, f);
			}
			else if (orden == "siguientePaciente") {
				cin >> m;
				string p2=con.siguientePaciente(m);
				cout << "Siguiente paciente doctor " << m << endl;
				cout << p2 << endl;
				cout << "---\n";
			}
			else if (orden == "atiendeConsulta") {
				cin >> m;
				con.atiendeConsulta(m);
			}
			else if (orden == "listaPacientes") {
				int d;
				cin >> m >> d;
				auto const& lista = con.listaPacientes(m, d);
				cout << "Doctor " << m << " dia " << d << endl;
				auto it = lista.begin();
				while (it != lista.end()) {
					cout << *it << " ";
					++it;
					cout << setfill('0') << setw(2) << *it << ":";
					++it;
					cout << setfill('0') << setw(2) << *it << "\n";
					++it;
				}
				cout << "---\n";
			}
			else
				cout << "OPERACION DESCONOCIDA\n";
		}
		catch (std::domain_error e) {
			std::cout << e.what() << '\n';
			cout << "---\n";
		}
	}
	std::cout << "------\n";
	return true;
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	// _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
