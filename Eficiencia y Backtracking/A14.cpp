#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

/*
P{ 0<=N<=100000 }
fun inversiones( v[0...N) de ent, int n) : dev long long int cont;
Q={cont = #i, j; 0<=i<n-1 && 1<=j<=n : v[i]>v[j] && i<j}

I:Q[N/n] and 0<=n<=N

C(n) = (n-1)-i >0;

Init: i,j,cont=0,1,0;
Step: j++ and if(j>n-1) i++
Restore: if (j > n - 1) {
				j = 0;
				i++;
			}

*/
const int M = 100000;


long long int inversiones(int v[], int n) {
	if (n == 0 || n == 1) return 0;
	else {
		int i = 0, j = 1;
		long long int cont = 0;
		while (i < n - 1) {
			if (v[i] > v[j] && i < j) cont++;
			j++;
			if (j > n - 1) {
				j = 0;
				i++;
			}
		}
		return cont;
	}
}

void inversionesDyV(int v[], int ini, int fin, long long int &c) {
	int h = (fin + ini) / 2;
	if (fin - ini == 1) {
		if (v[ini] > v[fin]) c++;
	}
	// no se como seguir

}

long long int aux(int v[], int n) {
	if (n == 0 || n == 1) return 0;
	else {
		long long int c = 0;
	    inversionesDyV(v, 0, n, c);
		return c;
	}
}

void resuelveCaso() {
	int c; cin >> c;
	for (int i = 0; i < c; i++) {
		int n, v[M];
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> v[j];
		}
		cout << inversiones(v, n) << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}