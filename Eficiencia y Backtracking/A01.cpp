#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>

using namespace std;

bool resuelveCaso() {
	int n, sol;
	cin >> n;
	if (!cin) {
		return false;
	}
	sol = n * 2;
	cout << sol << endl;
	return true;
}

int main() {
	while (resuelveCaso()) {
	}
	return 0;
}