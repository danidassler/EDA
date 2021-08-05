#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

#include"09.h"
#include"queue_eda.h"

bool resuelveCaso() {
	ListaDuplica<int> cola;
	int d;
	if (!cin) return false;
	while (cin >> d && d != 0) {
		cola.push(d);
	}
	cola.invertir();
	cola.print();
	return true;
}

int main() {
	while (resuelveCaso());
}