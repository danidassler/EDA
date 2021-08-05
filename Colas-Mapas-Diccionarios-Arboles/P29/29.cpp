#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

void resuelveCaso() {
	int s, cap, n;
	cin >> s;
	for (int i = 0; i < s; i++) {
		cin >> cap;
		unordered_map<int, int> dicc;
		int max = 1, ini = 0, fin = 0;
		for (int j = 0; j < cap; j++) {
			cin >> n;
			if (dicc.count(n) == 0) {
				dicc[n] = j;
				fin = j;
			}
			else {
				if (dicc[n] < ini) dicc[n] = j;
				else {
					ini = dicc[n] + 1;
					dicc[n] = j;
				}
				fin = j;
			}
			if ((fin - ini) + 1 > max) {
				max = (fin - ini)+1;
			}
		}
		cout << max << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}