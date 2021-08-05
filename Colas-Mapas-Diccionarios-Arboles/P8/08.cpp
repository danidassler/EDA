#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

#include"08.h"
#include"queue_eda.h"

bool resuelveCaso() {
	int n;
	ListaDuplica<int> cola;
	if (!cin) return false;
	while (cin >> n && n!=0) {
		cola.push(n);
	}
	cola.duplica();
	cola.print();
	cout << endl;
	return true;
}

int main() {
	while(resuelveCaso());
	return 0;
}