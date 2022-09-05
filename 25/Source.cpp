// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include "PriorityQueue.h"

using namespace std;

struct pase{
	int inicio;
	int fin;

	bool operator < (const pase& p2) const{
		if (inicio < p2.inicio)
			return true;
		else return false;
	}
};

bool resuelveCaso() {
	int numConferencias;
	cin >> numConferencias;
	if (numConferencias == 0)
		return false;
	list<pase> conferencias;
	int h_ini, h_fin;
	for (int i = 0; i < numConferencias; i++){
		cin >> h_ini >> h_fin;
		conferencias.push_back({ h_ini, h_fin });
	}
	conferencias.sort();
	PriorityQueue<int> salas;
	while (!conferencias.empty()){
		pase conf = conferencias.front();
		conferencias.pop_front();
		if (!salas.empty()){
			auto min = salas.top();
			if (conf.inicio >= min)
				salas.pop();
		}
		salas.push(conf.fin);		
	}
	cout << salas.size() << '\n';
	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/25/datos.txt");
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