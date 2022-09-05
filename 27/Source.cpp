// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

bool resolver(vector<int> const& longitudes, vector<int> const& precios, int l, unsigned long long int & numFormas, 
	unsigned long long int & numCuerdas, unsigned long long int & minCoste){
	int n = longitudes.size();
	vector<unsigned long long int> formas(l + 1, 0), min_cuerdas(l + 1, LLONG_MAX), min_coste(l + 1, LLONG_MAX);
	formas[0] = 1;
	min_cuerdas[0] = 0;
	min_coste[0] = 0;
	for (int i = 0; i < n; i++){
		for (int j = l; j >= longitudes[i]; j--){
			formas[j] = formas[j] + formas[j - longitudes[i]];
			min_cuerdas[j] = min(min_cuerdas[j], min_cuerdas[j - longitudes[i]] + 1);
			min_coste[j] = min(min_coste[j], min_coste[j - longitudes[i]] + precios[i]);
		}
	}
	numFormas = formas[l];
	numCuerdas = min_cuerdas[l];
	minCoste = min_coste[l];
	return numFormas > 0;
}

bool resuelveCaso() {
	int n, l;
	cin >> n;
	if (!cin)
		return false;
	cin >> l;
	vector<int> longitudes(n), precios(n);
	for (int i = 0; i < n; i++)
		cin >> longitudes[i] >> precios[i];
	unsigned long long int numFormas, numCuerdas, minCoste;
	bool sol = resolver(longitudes, precios, l, numFormas, numCuerdas, minCoste);
	if (sol){
		cout << "SI " << numFormas << ' ' << numCuerdas << ' ' << minCoste;
	}
	else cout << "NO";
	cout << '\n';
	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/27/datos.txt");
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