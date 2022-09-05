// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool resuelveCaso() {
	int numAgujeros, tamParche;
	cin >> numAgujeros;
	if (!cin)
		return false;
	cin >> tamParche;
	vector<int> agujeros(numAgujeros);
	for (int i = 0; i < numAgujeros; i++)
		cin >> agujeros[i];
	int numParches = 1, primero = agujeros[0];
	for (int j = 0; j < numAgujeros; j++){
		if (agujeros[j] - primero > tamParche){
			primero = agujeros[j];
			numParches++;
		}
	}
	cout << numParches << '\n';
	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/20/datos.txt");
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