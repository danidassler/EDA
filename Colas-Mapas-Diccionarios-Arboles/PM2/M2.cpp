#include <iostream>
#include <cmath>
#include <iomanip>
#include <istream>
#include <string>
#include <vector>
#include <fstream>
#include<stack>

using namespace std;

#include"bintree_eda.h"

/*
Dado un árbol, calculamos la longitud del camino más largo formado por
números pares de manera recursiva. Si el árbol es vacío, el camino más
largo también, por lo que la solución es 0. Si el árbol no es vacío,
el camino más largo puede estar en alguno de sus hijos (lo que saben
calcular llamadas recursivas con cada uno de ellos) o pasar por la
raíz, en el caso de que esta sea par. Para calcular el camino más largo
que pasa por la raíz, necesitamos saber cuánto podemos bajar por cada
uno de los hijos pasando solamente por números pares. Y la longitud
de ese camino es 1 (la raíz) más lo que podamos bajar por la izquierda más
lo que podamos bajar por la derecha. Por eficiencia, hacemos que la función
recursiva devuelva también ese dato, que llamamos alturaPar. La alturaPar
de un árbol vacío o de un árbol con un impar en la raíz es 0, y la de un
árbol no vacío con un par en la raíz es 1 más que el máximo de las alturas
pares de sus dos hijos.

*/

struct sol {
	int maximo;
	int alturaPar;
};

// la funcion tiene un coste de O(n) siendo n el numero de nodos del arbol , ya que se recorren todos ellos y se realizan operaciones constantes O(1) durante el recorrido de la funcion

sol pares(bintree<int> a) {
	if (a.empty()) {
		sol s;
		s.maximo = 0;
		s.alturaPar = 0;
		return s;
	}
	else {
		sol iz, der, solucion;
		iz = pares(a.left());
		der = pares(a.right());
		if (a.root() % 2 == 1) {
			solucion.alturaPar = 0;
			solucion.maximo = max(iz.maximo, der.maximo);
		}
		else {
			int porRaiz = 1 + iz.alturaPar + der.alturaPar;
			solucion.alturaPar = 1 + max(iz.alturaPar, der.alturaPar);
			solucion.maximo= max(porRaiz,max(iz.maximo, der.maximo));
		}
		return solucion;
	}
}

int caminoPares(bintree<int> arbol) {
	return pares(arbol).maximo;
}

void resuelveCaso() {
	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		bintree<int> arbol;
		int raiz = -1;
		arbol = leerArbol(raiz);
		cout << caminoPares(arbol) << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}