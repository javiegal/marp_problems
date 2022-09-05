// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include <vector>
#include "IndexPQ.h"
#include "GrafoDirigidoValorado.h"

using namespace std;

const size_t INFINITO = 1000000000;

vector<size_t> resolver(GrafoDirigidoValorado<size_t> const& graf, size_t elem){
	size_t tam = graf.V();
	IndexPQ<size_t> pq(tam);
	vector<size_t> distTo(tam), formas;
	for (size_t v = 0; v < tam; v++)
		distTo[v] = INFINITO;
	distTo[elem] = 0;
	pq.push(elem, 0);

	while (!pq.empty()){
		size_t v = pq.top().elem;
		pq.pop();
		for (AristaDirigida<size_t> a : graf.adj(v)){
			size_t w = a.to();
			if (distTo[w] > distTo[v] + a.valor()){
				distTo[w] = distTo[v] + a.valor();
				pq.update(w, distTo[w]);
			}
		}
	}
	return distTo;
}

bool resuelveCaso() {
	size_t numCasas, conexiones;
	cin >> numCasas;
	if (!cin)
		return false;
	cin >> conexiones;
	GrafoDirigidoValorado<size_t> graf(numCasas);
	size_t ori, dest, esf;
	for (int i = 0; i < conexiones; i++){
		cin >> ori >> dest >> esf;
		graf.ponArista({ --ori, --dest, esf });
	}
	size_t oficina, paquetes;
	cin >> oficina >> paquetes;
	oficina--;
	vector<size_t> destinos(paquetes);
	for (int j = 0; j < paquetes; j++){
		cin >> destinos[j];
		destinos[j]--;
	}
	vector<size_t> ida = resolver(graf, oficina), vuelta = resolver(graf.reverse(), oficina);
	bool imposible = false;
	int k = 0;
	size_t tiempo = 0;
	while (k < paquetes && !imposible){
		size_t ir = ida[destinos[k]], volver = vuelta[destinos[k]];
		if (ir == INFINITO || volver == INFINITO)
			imposible = true;
		else
			tiempo += ir + volver;
		k++;
	}
	if (imposible)
		cout << "IMPOSIBLE";
	else cout << tiempo;
	cout << '\n';

	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/17/datos.txt");
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