// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>

using namespace std;

bool resuelveCaso() {
	int numCiudades, efectivos;
	cin >> numCiudades;
	if (!cin)
		return false;
	list<int> efEnemigo, efDefensa;
	for (int i = 0; i < numCiudades; i++){
		cin >> efectivos;
		efEnemigo.push_back(efectivos);
	}
	for (int i = 0; i < numCiudades; i++){
		cin >> efectivos;
		efDefensa.push_back(efectivos);
	}
	efEnemigo.sort();
	efDefensa.sort();
	int victorias = 0;
	while (!efEnemigo.empty()){
		if (efDefensa.back() < efEnemigo.back())
			efDefensa.pop_front();
		else{
			efDefensa.pop_back();
			victorias++;
		}
		efEnemigo.pop_back();
	}
	cout << victorias << '\n';
	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/23/datos.txt");
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