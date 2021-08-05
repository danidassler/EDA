#include <iostream>
#include <stdexcept>  // std::domain_error
#include <utility>    // std::move
#include <string>

using namespace std;

#include "stack_eda.h"

bool isletra(char const c) {
	if (c != '(' && c != ')' && c != '{' && c != '}' && c != '[' && c != ']') {
		return true;
	}
	else return false;
}

bool evaluar(string const& expresion) {
	stack<char> pila;
	for (char c : expresion) {
		try {
			if (isletra(c)) {
				// skip
			}
			else if (c == '(') pila.push(c);
			else if (c == ')') {
				if (pila.top() == '(') {
					pila.pop();
				}
				else return false;
			}
			else if (c == '{') pila.push(c);
			else if (c == '}') {
				if (pila.top() == '{') {
					pila.pop();
				}
				else return false;
			}
			else if (c == '[') pila.push(c);
			else if (c == ']') {
				if (pila.top() == '[') {
					pila.pop();
				}
				else return false;
			}
		}
		catch (domain_error e) {
			return false;
		}

	}
	if (pila.empty()) {
		return true;
	}
	else return false;
}

int main() {
	string cadena;
	while (getline(cin, cadena)) {

		if (evaluar(cadena)) {
			cout << "SI" << endl;
		}
		else cout << "NO" << endl;

	}
	return 0;
}