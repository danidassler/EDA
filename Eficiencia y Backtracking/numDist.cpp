#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

const int M = 10000;

void numDist(int v[], int i, int j, int &dist) {
	int h = (i + j) / 2;

	if (j - i == 1) dist += 1;
	else if (j - i == 2) {
		if (v[i] == v[j - 1]) dist += 1;
		else if (v[i] != v[j - 1]) dist += 2;
	}
	else {
		numDist(v, i, h, dist);
		numDist(v, h, j, dist);
		if (v[h] == v[h - 1]) dist--;
	}
}

int numDistAux(int v[], int n) {
	if (n == 1) return 1;
	else if (n == 2) {
		if (v[0] == v[1]) return 1;
		else return 2;
	}
	else {
		int dist = 0;
		numDist(v, 0, n - 1, dist);
		return dist;
	}
}

bool resuelveCaso() {
	int n, v[M], sol;
	cin >> n;
	if (n == 0) {
		return false;
	}
	else {
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sol = numDistAux(v, n);
		cout << sol << endl;
	}
	return true;
}

int main() {
	while(resuelveCaso());
	return 0;
}