// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>

using namespace std;

bool resuelveCaso() {
	int partidos, pts;
	cin >> partidos;
	if (partidos == 0)
		return false;
	list<int> ptsRival, ptsPropios;
	for (int i = 0; i < partidos; i++){
		cin >> pts;
		ptsRival.push_back(pts);
	}
	for (int i = 0; i < partidos; i++){
		cin >> pts;
		ptsPropios.push_back(pts);
	}
	ptsRival.sort();
	ptsPropios.sort();
	int diferencia = 0;
	while (!ptsRival.empty()){
		if (ptsPropios.back() - ptsRival.front() > 0)
			diferencia += ptsPropios.back() - ptsRival.front();
		ptsRival.pop_front();
		ptsPropios.pop_back();
	}
	cout << diferencia << '\n';
	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/22/datos.txt");
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