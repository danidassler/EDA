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
P{ 2<= l <= n && -1000 <= v <= 1000 }
fun numSeg( v[0...n) de ent, int n, int l, int & numS) : void
Q{ cont = #i : 0<=i<n-1 : AllesS(v, l) && >=l && ok }
where AllesS(v,l) = forall p: i<=p<n-1 : abs(v[i]-v[i+1]) <=1

I : Q[N/n] and 0<=n<=N
C(n) = (n-1) - i >=0;

Init: i, cont, ok= 0, 1, true;
Step: i=i+1;
Restore: else {
			if (cont >= l&&ok) {
				numS = numS + 1;
			}
			cont = 1;
			ok = true;
		}
		if (cont >= l && ok) {
			numS = numS + 1;
			ok = false;
		}


*/

void numSeg(int v[], int n, int l, int &numS) {
	int i = 0, cont = 1;
	bool ok = true;
	while (i < n - 1) {
		if (abs(v[i] - v[i + 1]) == 1 || abs(v[i] - v[i + 1]) == 0) cont++;
		else {
			if (cont >= l&&ok) {
				numS = numS + 1;
			}
			cont = 1;
			ok = true;
		}
		if (cont >= l && ok) {
			numS = numS + 1;
			ok = false;
		}
		i++;
	}
}

bool resuelveCaso() {
	int n, l, v[M], sol = 0;
	cin >> n >> l;
	if (n == 0 && l==0) return false;
	for (int j = 0; j < n; j++) {
		cin >> v[j];
	}
	numSeg(v, n, l, sol);
	cout << sol << endl;
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}