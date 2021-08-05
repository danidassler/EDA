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
P{ n>=0 }
fun segmento(v[0...n) de ent, int n) dev: int max
Q{ max= max sumatorio de l, max: 0<=i<=n-1 : abs(v[i]-v[i+1])==1 }

I: Q[N/n] and 0<=n<=N

C(n): (n-1)-i>=0 || i<n-1

Init: l, max, n= 1, 0, 0;
Step: i++;
Restore: if (l > max) {
             max = l;
           }
           l = 1;
El coste de la funcion es de O(n-1) ,siendo n el numero de elementos del vector, ya que se recorre el vector hasta su penultima posicion y dentro del bucle se realizan operaciones constantes sobre este como accesos O(1)
*/

int segmento(int v[], int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n > 1) {
		int l = 1, max = 0;
		for (int i = 0; i < n-1; i++) {
			if (abs(v[i] - v[i + 1]) == 1) l++; // la longitud se aumenta
			else {
				if (l > max) {
					max = l;
				}
				l = 1;
			}
			if (l > max) {
				max = l;
			}
		}
		return max;
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
		int sol = segmento(v, n);
		cout << sol << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}