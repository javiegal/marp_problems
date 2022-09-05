// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int INFINITO = 2000000;

bool resolver(vector<int> const& valores, vector<int> const& cantidades, int precio, int & sol){
	int n = valores.size();
	vector<vector<int>> monedas(n+1, vector<int>(precio + 1, INFINITO));
	for (int i = 0; i <= n; i++)
		monedas[i][0] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= precio; j++){
			monedas[i][j] = monedas[i - 1][j];
			for (int k = 1; k <= cantidades[i - 1] && k*valores[i - 1] <= j; k++)
				monedas[i][j] = min(monedas[i][j], monedas[i-1][j - k*valores[i-1]] + k);
		}
	}
	sol = monedas[n][precio];
	return sol < INFINITO;
}

bool resuelveCaso() {
	int n;
	cin >> n;
	if (!cin)
		return false;
	vector<int> valores(n);
	vector<int> cantidades(n);
	for (int i = 0; i < n; i++)
		cin >> valores[i];
	for (int j = 0; j < n; j++)
		cin >> cantidades[j];
	int precio, sol;
	cin >> precio;
	if (resolver(valores, cantidades, precio, sol))
		cout << "SI " << sol;
	else 
		cout << "NO";
	cout << '\n';

	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/36/datos.txt");
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