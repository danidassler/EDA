#include <iostream>
#include <cmath>
#include <iomanip>
#include <istream>
#include <string>
#include <vector>
#include <fstream>
#include<stack>

using namespace std;


// La solución recorre los accidentes de menor a mayor fecha. Utiliza una
// pila para recordar los accidentes que todavía tienen opción de ser el
// anterior más cercano para algún accidente futuro. Cuando va a tratar el
// i-ésimo accidente, desapila los accidentes en la pila con un nº menor o igual
// de víctimas (que ya no podrán ser la respuesta a ningún accidente futuro porque
// el actual es mayor y más cercano).
// Si la pila no queda vacía, la cima es el accidente anterior buscado.
// Si no, no hay. En cualquier caso, el accidente i-ésimo se apila,
// porque puede ser la respuesta para alguno de los siguientes.

// O(N), con N el número de accidentes. Como cada vuelta del bucle más externo
// puede tardar algo distinto, sumamos el coste de todas las vueltas. Para eso
// hay que saber cuántas veces se ejecuta el cuerpo del bucle más interno (cuántos
// pops se hacen). Como cada accidente se apila una sola vez, el número máximo
// total de pops es N.

bool resuelveCaso() {
	int n, v;
	string f;
	cin >> n;
	if (!cin) return false;
	vector<pair<string, int>> acc;
	for (int i = 0; i < n; i++) {
		cin >> f >> v;
		acc.push_back({ f,v });
	}
	int z = acc.size();
	stack<pair<string,int>> pila;
	for (int i = 0; i < z; i++) {
		if (i == 0) { // caso base, el primero no tiene accidentes antecesores
			cout << "NO HAY" << endl;
			pila.push(acc[i]);
		}
		else {
			while (!pila.empty() && pila.top().second <= acc[i].second) {
				pila.pop(); // desapilamos
			}
			if (pila.empty()) {
				cout << "NO HAY" << endl;
			}
			else {
				cout << pila.top().first << endl;
			}
			pila.push(acc[i]);
		}
	}
	cout << "---" << endl;
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}