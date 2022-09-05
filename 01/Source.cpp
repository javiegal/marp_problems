// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include "bintree_eda.h"


using namespace std;


template <class T>
bintree<T> leerArbol(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return{};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol(vacio);
		auto dr = leerArbol(vacio);
		return{ iz, raiz, dr };
	}
}

template <class T>
bool esEquilibrado(bintree<T> const & arb, int & alt){
	if (arb.empty())
		return true;
	else{
		int alt_izq = 0, alt_der = 0;
		if (esEquilibrado(arb.left(), alt_izq) && esEquilibrado(arb.right(), alt_der) &&
			(alt_izq - alt_der) <= 1 && (alt_der - alt_izq) <= 1){
			alt = max(alt_izq, alt_der) + 1;
			return true;
		}
		else return false;
	}
}

void resuelveCaso() {
	auto arb = leerArbol('.');
	int alt = 0;
	if (esEquilibrado(arb, alt))
		cout << "SI\n";
	else cout << "NO\n";
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/01/datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}