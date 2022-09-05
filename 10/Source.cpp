// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include "Grafo.h"
#include <vector>


using namespace std;

const int NARANJA = 1;
const int AZUL = 0;
const int VACIO = -1;

bool esComponenteBipartita(Grafo const& graf, size_t ini, int color, vector<size_t> & colores, vector<bool> & marcados, size_t & cuenta){
	colores[ini] = color;
	marcados[ini] = true;
	cuenta++;
	for (auto elem : graf.adj(ini)){
		if (!marcados[elem]){ 
			if (!esComponenteBipartita(graf, elem, 1 - color, colores, marcados, cuenta))
				return false;
		}
		else if (colores[elem] == colores[ini])	
			return false;
	}
	return true;
}

bool esBipartito(Grafo const& graf){
	vector<size_t> colores; // color de los vértices
	vector<bool> marcados;	// vértices coloreados
	size_t cuenta = 0;			// nº de vértices coloreados
	for (size_t k = 0; k < graf.V(); k++){
		colores.push_back(VACIO);
		marcados.push_back(false);
	}
	size_t tamano = graf.V();
	for (size_t ini = 0; ini < tamano; ini++){
		if (cuenta == tamano)	
			return true;
		if (!marcados[ini] && !esComponenteBipartita(graf, ini, NARANJA, colores, marcados, cuenta)) 
			return false;
	}
	return true;
}

bool resuelveCaso() {
	size_t v, e, w1, w2;
	cin >> v;
	if (!cin)
		return false;
	Grafo graf = Grafo(v);
	cin >> e;
	for (size_t i = 0; i < e; i++){
		cin >> w1 >> w2;
		graf.ponArista(w1, w2);
	}
	if (esBipartito(graf))
		cout << "SI";
	else cout << "NO";
	cout << '\n';
	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/10/datos.txt");
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