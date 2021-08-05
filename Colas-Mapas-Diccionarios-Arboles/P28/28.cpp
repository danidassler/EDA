#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

bool resuelveCaso() {
	int n;
	cin >> n;
	string autor, resultado;
	if (n == 0) return false;
	map<string, int> dicc;
	for (int i = 0; i < n; i++) {
		cin.ignore();
		getline(cin, autor);
		cin >> resultado;
		if (resultado == "INCORRECTO") dicc[autor]--;
		else dicc[autor]++;
	}
	auto it = dicc.begin();
	while (it != dicc.end()) {
		if (it->second == 0) {}
		else cout << it->first << ", " << it->second << endl;
		++it;
	}
	cout << "---" << endl;
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}