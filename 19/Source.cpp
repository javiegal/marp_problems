// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool resuelveCaso() {
	int numLibros;
	cin >> numLibros;
	if (!cin)
		return false;
	vector<int> libros;
	int libro;
	for (int i = 0; i < numLibros; i++){
		cin >> libro;
		libros.push_back(libro);
	}
	sort(libros.begin(), libros.end(), greater<int>());
	int descuento = 0;
	for (int j = 0; j < numLibros; j++){
		if (j % 3 == 2)
			descuento += libros[j];
	}
	cout << descuento << '\n';
	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/19/datos.txt");
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