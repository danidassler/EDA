//DANIEL SANZ MAYO
#include <stdexcept>
#include <utility>
#include <iostream>
#include <iomanip>
#include <istream>

using namespace std;


class Horas {
private:  //atributos
	int _hora;
	int _minutos;
	int _segundos;
	bool check(int h, int m, int s) {
		return 0 <= h && h < 24 && 0 <= m && m < 60 && 0 <= s && s < 60; // continuar
	}
public:   //metodos
	Horas(int h = 0, int m = 0, int s = 0) {//constructor , le introducimos el valor 0 por defecto que es como si hiciesemos un constructor sin argumentos ( por defecto)
		if (check(h, m, s)) {
			_hora = h;
			_minutos = m;
			_segundos = s;
		}
		else {
			throw invalid_argument("esto no es una hora");
		}
	}
	// observadoras
	int hora() const { return _hora; }
	int minuto() const { return _minutos; }
	int segundo() const { return _segundos; }

	// operador comparador
	bool operator <(Horas const& h) const {
		return 3600 * _hora + 60 * _minutos + _segundos <  3600 * h._hora + 60 * h._minutos + h._segundos; //continuar
	}
	bool operator >(Horas const& h) const {
		return 3600 * _hora + 60 * _minutos + _segundos >  3600 * h._hora + 60 * h._minutos + h._segundos; //continuar
	}
	// funcion leer
	void read(istream & i = cin) {
		int h, m, s;
		char c;
		i >> h >> c >> m >> c >> s;
		if (check(h, m, s)) {
			_hora = h;
			_minutos = m;
			_segundos = s;
		}
		else {
			throw invalid_argument("esto no es una hora");
		}
	}
	// funcion print
	void print(ostream& o = cout) const {
		o << setfill('0') << setw(2) << _hora << ':' << setfill('0') << setw(2) << _minutos << ':' << setfill('0') << setw(2) << _segundos;
	}
};

/* Horas::Horas( int _hora, int _minutos, int _segundos){ //definimos el constructor, preguntar si vale asi o hay que definirlo en la clase

if((_hora <= 23)&&(_hora >= 0)){
hora=_hora;
}
else{
throw std::domain_error("ERROR");
}
if((_minutos>=0 && _minutos <= 59) && ( _segundos >=0 && _segundos <= 59)){
minutos=_minutos;
segundos=_segundos;
}
else{
throw std::domain_error2("ERROR");
}
} */

inline ostream & operator<<(ostream & salida, Horas const & h) {
	h.print(salida); // esto de print no me compila si pongo la funcion print fuera de la clase, me dice que Horas has no memmber named print 
	return salida;

}

inline istream & operator >>(istream & entrada, Horas & h) {
	h.read(entrada); // aqui no me compila me pasa igual que con el print
	return entrada;
}