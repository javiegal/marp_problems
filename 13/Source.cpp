// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include "ConjuntosDisjuntos.h"
#include <vector>

using namespace std;

bool resuelveCaso() {
	size_t ancho, alto, numNegros = 0;
	cin >> ancho;
	if (!cin)
		return false;
	cin >> alto;
	ConjuntosDisjuntos cd(ancho*alto);
	char elem;
	vector<bool> negros(ancho*alto);
	for (size_t i = 0; i < ancho*alto; i++){
		cin >> elem;
		if (elem == 'X'){
			negros[i] = true;
			numNegros++;
		}
		else negros[i] = false;
	}
	for (size_t k = 0; k < ancho*alto; k++){
		if (!negros[k]){
			if ((k%ancho != ancho - 1) && !negros[k + 1])
				cd.unir(k, k + 1);
			if (k < (ancho*(alto - 1)) && !negros[k + ancho])
				cd.unir(k, k + ancho);
		}
	}
	cout << cd.count()-(numNegros + 1) << '\n';

	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/13/datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	while(resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}