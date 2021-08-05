#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 1000;
bool recursion(int v[], int ini, int fin);
bool recursionAux(int v[], int n);

int main() {
	int v[MAX];
	int n = -1; //contador
	int i = -1;

	while (n != 0) {
		n = 0;
		while (i != 0) {
			cin >> i;
			v[n] = i;
			if (i != 0)n++;
		}
		if (n != 0) {
			if (recursionAux(v, n)) {
				cout << "SI" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
		i = -1;
	}

	return 0;
}


bool recursion(int v[], int ini, int fin) {

	bool ordenado = true;
	int mitad = (ini + fin) / 2; // hallamos la mitad
	if (fin - ini == 1) { // si el vector ha quedado reducido finalmente a 2 elementos
		if ((v[fin] >= v[ini]) && (v[ini] <= v[fin])) {
			return true;
		}
		else {
			return false;
		}
	}

	bool izquierda, derecha;

	izquierda = recursion(v, ini, mitad);
	if (!izquierda) {
		return false;
	}
	derecha = recursion(v, mitad + 1, fin);
	if (!derecha) {
		return false;
	}
	if ((derecha) && (izquierda)) {
		if ((v[fin] >= v[mitad]) && (v[ini] <= v[mitad + 1])) {
			return true;
		}
		else { return false; }
	}

}

bool recursionAux(int v[], int n) {
	if (n<2) { // caso base 1 elemento
		return true;
	}

	return recursion(v, 0, n - 1);
}
/*
int solve(int v[], int ini, int fin, int &mx, bool &ok) {
	int h = (ini + fin) / 2;
	if (fin - ini == 1) {
		mx = v[fin];
		return v[ini];
	}
	else {
		if (ok) {
			int maxI, maxD, minI, minD;
			minI = solve(v, ini, h, mx, ok);
			maxI = mx;
			minD = solve(v, h + 1, fin, mx, ok);
			maxD = mx;
			if (maxD >= maxI && minI <= minD) {
				mx = max(maxD, maxI);
				return min(minI, minD);
			}
			else {
				ok = false;
			}
		}
	}
}
*/
/*bool solveAux(int v[], int N) {
	int i = 0, f = N - 1, max = 0;
	bool ok = true;
	solve(v, i, f, max, ok);
	return ok;
}*/

/*int solve(int V[], int i, int j, int maxim, bool& ok) {
	int h = (i + j) / 2, minI, maxD, maxI, minD;

	if (j - i == 1) {
		maxim = V[i];
		return V[i];
	}
	else {
		if (ok) {
			minI = solve(V, i, h, maxim, ok);
			maxI = maxim; //SI HAGO COUT AQUI DE MAXIM POR QUE ME SALE UNA DIRECCION DE MEMORIA Y NO UN VALOR
			minD = solve(V, h, j, maxim, ok);
			maxD = maxim;

			if (minI > minD || maxD < maxD) ok = false;
			else {
				maxim = max(maxI, maxD);
				return min(minI, minD);
			}
		}
	}
}

bool resuelveCaso() {
	int i = 0, n, v[M], max = 0;
	bool ok = true;
	cin >> n;
	if (n == 0) {
		return false;
	}
	else {
		while (n != 0) {
			v[i] = n;
			i++;
			cin >> n;
		}
		solve(v, 0, i, max, ok);
		if (ok) {
			cout << "SI" << endl;
		}
		else cout << "NO" << endl;
	}
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}*/