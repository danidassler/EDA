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
Dado un �rbol, calculamos la longitud del camino m�s largo formado por
n�meros pares de manera recursiva. Si el �rbol es vac�o, el camino m�s
largo tambi�n, por lo que la soluci�n es 0. Si el �rbol no es vac�o,
el camino m�s largo puede estar en alguno de sus hijos (lo que saben
calcular llamadas recursivas con cada uno de ellos) o pasar por la
ra�z, en el caso de que esta sea par. Para calcular el camino m�s largo
que pasa por la ra�z, necesitamos saber cu�nto podemos bajar por cada
uno de los hijos pasando solamente por n�meros pares. Y la longitud
de ese camino es 1 (la ra�z) m�s lo que podamos bajar por la izquierda m�s
lo que podamos bajar por la derecha. Por eficiencia, hacemos que la funci�n
recursiva devuelva tambi�n ese dato, que llamamos alturaPar. La alturaPar
de un �rbol vac�o o de un �rbol con un impar en la ra�z es 0, y la de un
�rbol no vac�o con un par en la ra�z es 1 m�s que el m�ximo de las alturas
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