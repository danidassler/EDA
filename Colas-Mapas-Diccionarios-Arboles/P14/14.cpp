#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

#include"deque_eda.h"
#include"stack_eda.h"

bool es_vocal(char c) {
	c=tolower(c);
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
	else return false;
}

void print(string cola) {
	int S = cola.size();
	for (int i = 0; i < S; i++) {
		cout << cola[i];
	}
	cout << endl;
}

void volcar_pila(stack<char> &pila, string &cola) {
	if (pila.empty()) return;
	else {
		while (!pila.empty()) {
			cola.push_back(pila.top());
			pila.pop();
		}
	}
}

void resuelveCaso(string & frase) {
	deque<char> cola;
	stack<char> pila;
	int s = frase.size();
	for (int i = 0; i < s; i++) {
		if (i % 2 == 0) {
			cola.push_back(frase[i]);
		}

	}
	int cont = 0;
	if (s % 2 == 0) {

		for (int i = s - 1; i > 0; i--) {
			if (cont % 2 == 0) {
				cola.push_back(frase[i]);
			}
			cont++;
		}
	}
	else {
		for (int i = s - 1; i > 0; i--) {
			if (cont % 2 != 0) {
				cola.push_back(frase[i]);
			}
			cont++;
		}
	}

	string resultado;
	int S = cola.size();
	for (int i = 0; i < S; i++) {
		if (es_vocal(cola.front())) {
			volcar_pila(pila, resultado);
			resultado.push_back(cola.front());
		}
		else {
			pila.push(cola.front());
		}
		cola.pop_front();
	}
	volcar_pila(pila, resultado);

	print(resultado);

}

int main() {
	string frase;

	while (getline(cin, frase)) {
		resuelveCaso(frase);
	}
	return 0;
}