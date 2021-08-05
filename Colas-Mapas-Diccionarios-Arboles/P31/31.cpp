#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

void resuelveCaso(int n) {
	map<string, vector<int>> dicc;
	string linea;
	for (int i = 0; i < n; i++) {
		getline(cin, linea);
		stringstream ss(linea);
		string clave;
		while (ss >> clave) {
			int l = clave.length();
			if (l > 2) {
				for (int j = 0; j < l; j++) {
					clave[j] = tolower(clave[j]);
				}
				auto it = dicc.find(clave);
				if (it!=dicc.end() && it->second.back()==i+1){
					// si ya ha salido en esa linea no hace falta ponerlo otra vez
			    }
				else {
					dicc[clave].push_back(i + 1);
				}
			}
		}
	}
	auto it = dicc.begin();
	while (it != dicc.end()) {
		cout << it->first << " ";
		for (int i : it->second) {
			cout << i << " ";
		}
		cout << endl;
		++it;
	}
	cout << "----" << endl;
}

int main() {
	int n;
	cin >> n;
	while (n != 0) {
		cin.ignore();
		resuelveCaso(n);
		cin >> n;
	}
	return 0;
}