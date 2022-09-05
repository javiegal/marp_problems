// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include "GrafoValorado.h"
#include <vector>
#include "IndexPQ.h"

using namespace std;

const size_t INFINITO = 2147483648;

size_t resolver(GrafoValorado<size_t> const& graf){
	size_t tam = graf.V();
	IndexPQ<size_t> pq(tam);
	vector<size_t> distTo(tam), formas;
	for (size_t v = 0; v < tam; v++){
		distTo[v] = INFINITO;
		formas.push_back(0);
	}
	formas[0] = 1;
	distTo[0] = 0;
	pq.push(0, 0);

	while (!pq.empty()){
		size_t v = pq.top().elem;
		pq.pop();
		for (Arista<size_t> a : graf.adj(v)){
			size_t w = a.otro(v);
			if (distTo[w] > distTo[v] + a.valor()){
				distTo[w] = distTo[v] + a.valor();
				pq.update(w, distTo[w]);
				formas[w] = formas[v];
			}
			else if (distTo[w] == distTo[v] + a.valor()){
				formas[w] += formas[v];
			}
		}
	}
	return formas[graf.V()-1];
}

bool resuelveCaso() {
	size_t intersecciones, calles;
	cin >> intersecciones;
	if (!cin)
		return false;
	cin >> calles;
	size_t i1, i2, valor;
	GrafoValorado<size_t> graf(intersecciones);
	for (size_t i = 0; i < calles; i++){
		cin >> i1 >> i2 >> valor;
		graf.ponArista({ --i1, --i2, valor });
	}
	cout << resolver(graf) << '\n';
	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/16/datos.txt");
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