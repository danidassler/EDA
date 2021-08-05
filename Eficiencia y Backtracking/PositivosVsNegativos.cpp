#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

const int M = 10000;

void print(int v[], int n) {
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int PvsN(int v[], int n) {
	int i = 0, j = n - 1, aux;
	if (n == 1) {
		if (v[i] >= 0) return n;
		else return 0;
	}
	else {
		while (i != j) {
			if (v[j] < 0) j--;
			else {
				aux = v[j];
				v[j] = v[i];
				v[i] = aux;
				i++;
			}
		}
		return j;
	}
}

void resuelveCaso() {
	int c, n, v[M];
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> v[j];
		}
		int p = PvsN(v, n);
		print(v, n);
		cout << p << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}