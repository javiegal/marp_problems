// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include "GrafoValorado.h"
#include <vector>
#include <queue>
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"

using namespace std;

bool resolver(size_t intersecciones, size_t & coste, PriorityQueue<Arista<size_t>> pq){
	queue<Arista<size_t>> inc;
	ConjuntosDisjuntos cd(intersecciones);
	while (!pq.empty() && inc.size() < intersecciones - 1){
		Arista<size_t> a;
		pq.pop(a);
		size_t v = a.uno();
		size_t w = a.otro(v);
		if (cd.buscar(v) != cd.buscar(w)){
			cd.unir(v, w);
			inc.push(a);
			coste += a.valor();
		}
	}
	if (cd.size(0) < intersecciones)
		return false;
	return true;
}

bool resuelveCaso() {
	size_t intersecciones, calles;
	cin >> intersecciones;
	if (!cin)
		return false;
	cin >> calles;
	size_t i1, i2, valor;
	PriorityQueue<Arista<size_t>> pq;
	for (size_t i = 0; i < calles; i++){
		cin >> i1 >> i2 >> valor;
		pq.push({ --i1, --i2, valor });
	}
	size_t coste = 0;
	bool sol = resolver(intersecciones, coste, pq);
	if (sol)
		cout << coste;
	else cout << "Imposible";
	cout << '\n';
	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/15/datos.txt");
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