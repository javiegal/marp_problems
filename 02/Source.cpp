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

bool esAVL(bintree<int> const & arb, int & alt, int & n_izq, int & n_der){
	if (arb.empty())
		return true;
	else{
		int elem = arb.root();
		if ((n_izq != -1 && elem <= n_izq) || (n_der != -1 && n_der <= elem))
			return false;
		int ant_der = n_der;
		int alt_izq = 0, alt_der = 0;
		auto izq = arb.left(), der = arb.right();
		n_der = elem;
		bool avl_izq = esAVL(izq, alt_izq, n_izq, n_der);
		n_izq = elem;
		n_der = ant_der;
		bool avl_der = esAVL(der, alt_der, n_izq, n_der);
		if (avl_izq && avl_der && abs(alt_izq - alt_der) <= 1){
			alt = max(alt_izq, alt_der) + 1;
			return true;
		}
		else return false;
	}
}

void resuelveCaso() {
	auto arb = leerArbol(-1);
	int alt = 0, n_izq = -1, n_der = -1;
	if (esAVL(arb, alt, n_izq, n_der))
		cout << "SI\n";
	else cout << "NO\n";
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/02/datos.txt");
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