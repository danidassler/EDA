#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

bool resuelveCaso() {
	struct comparador
	{
		bool operator()(pair<string, int> const& a, pair<string, int> const& b) const {
			return(a.second > b.second || (a.second == b.second && a.first < b.first));
		}

	};
	string linea, aux;
	unordered_map<string, int> dep;
	unordered_map<string, pair<string, bool>> est;
	getline(cin, linea);
	if (!cin) return false;
	while (linea != "_FIN_") {
		if (isupper(linea[0])) {
			aux = linea;
			dep[linea] = 0;
		}
		else {
			auto ins = est.insert({ linea,{aux, true} });
			if (ins.second) {
				++dep[aux];
			}
			else {
				if (ins.first->second.second && ins.first->second.first != aux) {
					ins.first->second.second = false;
					--dep[ins.first->second.first];
				}
				else {

				}
			}
		}
		getline(cin, linea);
	}
	vector<pair<string, int>> resultado;

	for (auto & de : dep) {
		resultado.push_back({ de.first, de.second });
	}

	sort(resultado.begin(), resultado.end(), comparador());

	for (auto const & res : resultado) {
		cout << res.first << " " << res.second << endl;
	}

	cout << "***" << endl;
	return true;
}

int main() {
	while(resuelveCaso());
	return 0;
}