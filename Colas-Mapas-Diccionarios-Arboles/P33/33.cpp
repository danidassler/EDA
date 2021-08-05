#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<set>

using namespace std;

void printSol(map<int, map<int, set<string>>> & sol) {
	auto it1 = sol.rbegin();
	while (it1 != sol.rend()) {
		auto it2 = it1->second.begin();
		while (it2 != it1->second.end()) {
			auto it3 = it2->second.begin();
			while (it3 != it2->second.end()) {
				cout << *it3 << " " << it1->first << " " << it2->first << "\n";
				++it3;
			}
			++it2;
		}
		++it1;
	}
	cout << "----\n";
}

void resuelveCaso() {
	int c;
	cin >> c;
	struct comparador
	{
		bool operator()(pair<string, pair<int, int>> const& a, pair<string, pair<int, int>> const& b) const {
			return(a.second.first > b.second.first || (a.second.first == b.second.first && a.second.second < b.second.second) || (a.second.first == b.second.first && a.second.second == b.second.second && a.first < b.first));
		}

	};
	for (int i = 0; i < c; i++) {
		string e, p, s;
		int t;
		unordered_map<string, pair<int, unordered_map<string, pair<bool, int>>>> equipos_prob;//equipo ->(#aciertos, problemas -> (acertado, tiempo))
		map<int, map<int, set<string>>> resultado;//aciertos ->(tiempo_resolver -> conjuntos_de_equipos)

		cin >> e;
		while (e != "FIN") {
			cin >> p >> t >> s;
			if (!equipos_prob.count(e)) equipos_prob[e].first = 0; //Si el equipo es nuevo, aun no tiene aciertos
			if (equipos_prob[e].second.count(p)) { //Si el equipo ya ha intentado el problema
				if (!equipos_prob[e].second[p].first) { //Miro si el problema aun no ha sido correcto
					if (s != "AC") equipos_prob[e].second[p].second += 20; //Si sigue sin ser correcto se penaliza con 20
					else {
						equipos_prob[e].second[p].first = true; //Si es correcto se actualiza
						equipos_prob[e].second[p].second += t;
						equipos_prob[e].first++; //Aumento el numero de aciertos del equipo.
					}
				}
			}
			else {//Si es la primera vez que el equipo intenta el problema
				if (s == "AC") {//Si lo acierta a la primera se actualiza el numero de aciertos
					equipos_prob[e].second[p] = make_pair(true, t);
					equipos_prob[e].first++;
				}
				else {//Si es el primero y lo falla se penaliza con 20
					equipos_prob[e].second[p] = make_pair(false, 20);
				}
			}
			cin >> e;
		}
		auto it_equipo = equipos_prob.begin();
		while (it_equipo != equipos_prob.end()) {
			int tiempo_total = 0;
			auto it_problema = it_equipo->second.second.begin();
			while (it_problema != it_equipo->second.second.end()) {
				if (it_problema->second.first) tiempo_total += it_problema->second.second;
				++it_problema;
			}
			resultado[it_equipo->second.first][tiempo_total].insert(it_equipo->first);
			++it_equipo;
		}

		printSol(resultado);
	}
}

int main() {
	resuelveCaso();
	return 0;
}