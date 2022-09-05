// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>

using namespace std;

bool resuelveCaso() {
	int pesoSilla, usuarios, p;
	cin >> pesoSilla;
	if (!cin)
		return false;
	cin >> usuarios;
	list<int> peso;
	for (int i = 0; i < usuarios; i++){
		cin >> p;
		peso.push_back(p);
	}
	peso.sort();
	int numViajes = 0;
	while(!peso.empty()){
		if (peso.front() + peso.back() <= pesoSilla)
			peso.pop_front();
		if (!peso.empty())
			peso.pop_back();
		numViajes++;
	}
	cout << numViajes << '\n';
	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/21/datos.txt");
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