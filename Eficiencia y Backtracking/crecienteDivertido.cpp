#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

const int M = 1000;

/*
P{ 0 <= n <= 1000 && d > 0}
fun crecDiv (v[0...n) de ent, int d, int n) dev: bool ok
Q{ b= Vi : 0<=i<=n-1 : v[i] <= v[i+1] && v[i + 1] - v[i]<= 1 && act < d}

I: Q[N/n] and 0<=n<=N

C(n) = (n-1)-i;

Init: act, ok, i= 1, true, 0;
Step: i=i+1;
Restore: 	if (v[i + 1] - v[i]== 1) {
					if (act > d) {
						return false;
					}
					act = 1;


*/

bool crecDiv(int v[], int d, int n) { // el coste del algoritmo es O(n-1) siendo n el numero de elementos del vector ya que se recorre todo el vector excepto su ultima posicion y dentro del algoritmo se realizan operaciones con coste lineal como accesos ( O(1) )
	int act = 1, i = 0;
	bool ok = true;
	while (i < n - 1) {
		if (v[i] == v[i + 1]) {
			act++;
		}
		else {
			if (v[i] > v[i + 1]) return false;
			else { // si v[i] < v[i+1]
				if (v[i + 1] - v[i]== 1) {
					if (act > d) {
						return false;
					}
					act = 1;
				}
				else {
					return false;
				}
			}
		}
		if (act > d) {
			return false;
		}
		i++;
	}
}

void resuelveCaso() {
	int c, d, n, v[M];
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> d >> n;
		bool sol = true;
		for(int j = 0; j < n; j++) {
			cin >> v[j];
		}
		sol = crecDiv(v, d, n);
		if (sol) cout << "SI" << endl;
		else cout << "NO" << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}