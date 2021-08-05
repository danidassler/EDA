#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

/*
P{ 0 <= n <= 1000 }
fun pista(v[0...N) de ent, int n) dev : ent maxLong
Q{ max act: 0<= i <= n-1 and v[i]>=v[i+1]: act++ }

I: Q[N/n] and 0 <= n <N

C(n)= n-1 - i > 0 || i < n-1 

Init: maxLong, act, i = 0, 1, 0;
Step: i=i+1;
Restore: if (v[i] >= v[i + 1]) act++;
		else {
			if (act > maxLong) {
				maxLong = act;
			}
			act = 1;
		}
		if (i == n - 2) {
			if (act > maxLong) {
				maxLong = act;
			}
		}

*/

const int M = 1000;

int pista(int v[], int n) { // el coste del algoritmo es O(n) siendo n el numero de elementos del vector ( alturas de los tramos de las pistas ) ya que se recorre el vector entero y dentro del bucle se hacen operaciones de acceso a los elementos de este que tienen coste constante ( O(1) )
	int maxLong = 0, act = 1;
	for (int i = 0; i < n-1; i++) {
		if (v[i] >= v[i + 1]) act++;
		else {
			if (act > maxLong) {
				maxLong = act;
			}
			act = 1;
		}
		if (i == n - 2) {
			if (act > maxLong) {
				maxLong = act;
			}
		}
	}
	return maxLong;
}

void resuelveCaso() {
	int c, n, a, sol;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n;
		int v[M];
		for (int j = 0; j < n; j++) {
			cin >> v[j];
		}
		sol = pista(v, n);
		cout << sol << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}