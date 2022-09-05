// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include <vector>
#include "TreeMap_AVL_ext.h"


using namespace std;

bool resuelveCaso() {
	int numElems;
	cin >> numElems;
	if (numElems == 0)
		return false;
	map<int, int> arbol;
	int elem;
	for (int i = 0; i < numElems; i++){
		cin >> elem;
		arbol.insert({ elem, 0 });
	}
	int numConsultas, consulta;
	cin >> numConsultas;
	for (int j = 0; j < numConsultas; j++){
		cin >> consulta;
		int sol;
		if (arbol.encontrar(consulta, sol))
			cout << sol;
		else
			cout << "??";
		cout << '\n';
	}
	cout << "----\n";
	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/04/datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}