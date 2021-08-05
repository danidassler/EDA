#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include<unordered_map>
#include<map>

using namespace std;

bool resuelveCaso() {
	int P;
	cin >> P;
	if (P == 0) return false;
	// Para guardar la informaci�n sobre las pel�culas utilizamos un diccionario
	// no ordenado donde la clave es el t�tulo de la pel�cula y el valor asociado
	// otro diccionario no ordenado con claves los nombres de los actores y valores
	// el tiempo que aparece el actor en la pel�cula. En realidad, por el uso que
	// vamos a hacer de este diccionario interno (recorrerlo siempre), podr�a ser
	// tambi�n un vector de pares <string, int>.
	unordered_map<string, unordered_map<string, int>> pelis;

	for (int i = 0; i < P; i++) {
		string titulo, nombre;
		int NA, tiempo;
		cin >> titulo >> NA;
		for (int j = 0; j < NA; j++) {
			cin >> nombre >> tiempo;
			pelis[titulo][nombre] = tiempo;
		}
	}

	// coste O(P*NA), todos los actores en todas las pel�culas, ya que
	// los accesos a los diccionarios no ordenados son costantes


	// Ahora leemos las emisiones, contando cu�ntas veces se ha emitido
	// cada pel�cula. Para ello utilizamos un diccionario no ordenado
	// donde la clave es el t�tulo de la pel�cula y el valor cu�ntas veces
	// se ha emitido. Vamos recordando cu�l es la pel�cula m�s vista hasta
	// cada momento (y en caso de empates, la �ltima).

	unordered_map<string, int> vistas;

	string peli_mas_vista; // para recordar la m�s vista (si empate, la m�s reciente)

	int E;
	cin >> E;
	string titulo;
	for (int i = 0; i < E; i++) {
		cin >> titulo;
		vistas[titulo]++;
		if (vistas[titulo] >= vistas[peli_mas_vista]) {
			peli_mas_vista = titulo;
		}
	}
	// coste O(E), por cada emisi�n se hacen consultas a un diccionario no ordenado

	// Ahora ya tenemos toda la informaci�n para calcular el tiempo en
	// pantalla de cada actor. Para eso utilizamos un diccionario tambi�n
	// no ordenado (aunque la salida nos la piden ordenada, solamente hace
	// falta ordenar los actores m�s vistos, por lo que lo haremos despu�s)
	// donde las claves son los nombres de los actores y el valor cu�nto
	// ha salido por pantalla.
	// En el proceso vamos recordando el tiempo de los m�s vistos (pueden
	// ser varios), para recuperarlos despu�s.

	unordered_map<string, int> actores;
	int mas_visto = 0; // tiempo del actor m�s visto

	for (auto & pel : vistas) { // recorremos las pel�culas vistas
		auto & reparto = pelis[pel.first];
		// recorremos los actores de esta peli
		for (auto const& actor : reparto) {
			auto & t = actores[actor.first];
			t += pel.second * actor.second;
			if (t > mas_visto)
				mas_visto = t;
		}
	}
	// coste O(P * A), ya que por cada pel�cula se recorren todos
	// sus actores. Los accesos a los diccionarios son constantes.

	vector<string> actores_mas_vistos;
	for (auto const& actor : actores) {
		if (actor.second == mas_visto)
			actores_mas_vistos.push_back(actor.first);
	}
	// y los ordenamos
	sort(actores_mas_vistos.begin(), actores_mas_vistos.end());

	// el coste en el caso peor de este paso es O(A log A) por ordenar


	// Mostramos la salida

	cout << vistas[peli_mas_vista] << ' ' << peli_mas_vista << '\n';
	cout << mas_visto;
	for (auto const& actor : actores_mas_vistos) // O(A)
		cout << ' ' << actor;
	cout << '\n';

	// En total, el coste de resolver un caso es O(P*A + E + A*log A).

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}