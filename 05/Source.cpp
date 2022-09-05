// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"

using namespace std;

unsigned long long int resolver(PriorityQueue<unsigned long long int> cola){
	unsigned long long int gorras = 0;
	while (cola.size() > 1){
		unsigned long long int e1, e2;
		cola.pop(e1);
		cola.pop(e2);
		gorras += e1 + e2;
		cola.push(e1 + e2);
	}
	return gorras;
}

bool resuelveCaso() {
	int n;
	PriorityQueue<unsigned long long int> cola;
	cin >> n;
	if (n == 0)
		return false;
	long long int elem;
	for (int i = 0; i < n; i++){
		cin >> elem;
		cola.push(elem);
	}
	cout << resolver(cola) << '\n';
	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/04/datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while(resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}