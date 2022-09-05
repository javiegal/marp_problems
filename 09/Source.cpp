// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include <cmath>
#include "Grafo.h"

using namespace std;


int resolver(Grafo graf, size_t v){
	vector<bool> marcas;
	int cuenta = 0;
	for (int i = 0; i < v; i++)
		marcas.push_back(false);
	size_t elem = 0;
	while (elem < v){
		if (!marcas[elem]){
			DepthFirstSearch dfs = DepthFirstSearch(graf, elem);
			if(cuenta < dfs.count())
				cuenta = dfs.count();
			for (int j = elem+1; j < v; j++){
				if (dfs.marked(j))
					marcas[j] = true;
			}
		}
		elem++;
	}
	return cuenta;
}

void resuelveCaso() {
	size_t v, e;
	cin >> v >> e;
	Grafo graf = Grafo(v);
	size_t w1, w2;
	for (int i = 0; i < e; i++){
		cin >> w1 >> w2;
		graf.ponArista(--w1, --w2);
	}
	cout << resolver(graf, v) << '\n';
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/09/datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int numCasos;
	cin >> numCasos;
	for(int i = 0; i < numCasos; i++)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}