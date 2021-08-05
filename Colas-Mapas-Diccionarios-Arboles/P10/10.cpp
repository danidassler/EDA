#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

#include"10.h"
#include"queue_eda.h"

bool resuelveCaso() {
	int n, m, p, num;
	ListaDuplica<int> cola1, cola2;
	cin >> n;
	if (!cin) return false;
	for (int i = 0; i < n; i++) {
		cin >> num;
		cola1.push(num);
	}
	cin >> m >> p;
	for (int i = 0; i < m; i++) {
		cin >> num;
		cola2.push(num);
	}
	cola1.insertar(cola2, p);
	cola1.print();
	cout << endl;
	return true;
}

int main() {
	while(resuelveCaso());
	return 0;
}