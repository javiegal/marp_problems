// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include "GrafoDirigido.h"
#include <vector>
#include <utility>


using namespace std;

void alcanzaTodos(GrafoDirigido const& graf, size_t i, int & cuenta, bool & repite, vector<bool> & marcados){
	marcados[i] = true;
	cuenta++;
	for (auto elem : graf.adj(i)){
		if (marcados[elem])
			repite = true;
		else
			alcanzaTodos(graf, elem, cuenta, repite, marcados);
	}
}

pair<bool, size_t> esArborescente(GrafoDirigido const& graf){
	bool repite;
	for (size_t i = 0; i < graf.V(); i++){
		vector<bool> marcados;
		for (size_t j = 0; j < graf.V(); j++)
			marcados.push_back(false);
		int cuenta = 0;
		repite = false;
		alcanzaTodos(graf, i, cuenta, repite, marcados);
		if (repite)
			return{ false, -1 };
		if (cuenta == graf.V())
			return{ true, i };
	}
	return{ false, -1 };
}

bool resuelveCaso() {
	size_t v, e, w1, w2;
	cin >> v;
	if (!cin)
		return false;
	GrafoDirigido graf = GrafoDirigido(v);
	cin >> e;
	for (size_t i = 0; i < e; i++){
		cin >> w1 >> w2;
		graf.ponArista(w1, w2);
	}
	pair<bool, int> arborescente = esArborescente(graf);
	if (arborescente.first)
		cout << "SI " << arborescente.second;
	else cout << "NO";
	cout << '\n';
	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/11/datos.txt");
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