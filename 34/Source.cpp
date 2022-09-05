// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


int resolver(vector<int> const& cantidad){
	int n = cantidad.size();
	vector<vector<int>> tabla(n, vector<int>(n+1, 0));
	if (n % 2 == 1){
		for (int k = 0; k < n; k++)
			tabla[k][k + 1] = cantidad[k];
	}
	for (int d = 2 + (n%2); d < n+1; d+=2){
		for (int i = 0; i < (n+1) - d; i++){
			int j = i + d;
			int c1, c2;
			if (cantidad[j - 2] > cantidad[i])
				c1 = tabla[i][j - 2];
			else
				c1 = tabla[i + 1][j - 1];
			c1 += cantidad[j - 1];

			if (cantidad[i + 1] > cantidad[j - 1])
				c2 = tabla[i + 2][j];
			else
				c2 = tabla[i + 1][j - 1];
			c2 += cantidad[i];
			tabla[i][j] = max(c1, c2);
		}
	}
	return tabla[0][n];
}

bool resuelveCaso() {
	int numCubos;
	cin >> numCubos;
	if (numCubos == 0)
		return false;

	vector<int> cantidad(numCubos);
	for (int i = 0; i < numCubos; i++)
		cin >> cantidad[i];

	cout << resolver(cantidad) << '\n';

	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/34/datos.txt");
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