#include<iostream>
#include<string>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<sstream>

using namespace std;

const int M = 10000;

bool esValida(int sol[], int k, int i, int used[], int pos[M][3]) {
	bool ok = false;
	used[i]--; // marcaje
	if (used[i] > 0) ok = true;
	else if (used[i] == 0 && (pos[i][1]-pos[i][2])==i+1) ok = true;
	used[i]++; // desmarcaje
	return ok;
}

void vect(int sol[], int k, int n, int used[], int pos[M][3], int & s) {
	for (int i = 1; i <= n; i++) {
		pos[i][used[i]] = k;
		sol[k] = i;
		if (esValida(sol, k, i, used, pos)) {
			if (k == (n * 2) - 1) {
				for (int p = 0; p <= k; p++) {
					cout << sol[p] << " ";
				}
				cout << endl;
				s++;
			}
			else {
				used[i]--;
				vect(sol, k + 1, n, used, pos, s);
				used[i]++;
			}
		}
	}
}

void resuelveCaso() {
	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		int n, used[M], pos[M][3], sol[M], s = 0;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			used[j] = 2;
		}
		for (int j = 1; j <= n; j++) {
			for (int z = 1; z <= 2; z++) {
				pos[j][z] = 0;
			}
		}
		vect(sol, 0, n, used, pos, s);
		cout << "Soluciones: " << s << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}