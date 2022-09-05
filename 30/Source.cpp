// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int INFINITO = 200;

int resolver(string palabra){
	int n = palabra.size();
	vector<vector<int>> tabla(n, vector<int>(n, 0));
	for (int d = 1; d <= n-1; d++){
		for (int i = 0; i < n-d; i++){
			int j = d + i;
			tabla[i][j] = INFINITO;
			if (palabra.at(i) == palabra.at(j))
				tabla[i][j] = tabla[i + 1][j - 1];
			else{
				tabla[i][j] = min(tabla[i + 1][j] + 1, tabla[i][j - 1] + 1);
			}
		}
	}
	return tabla[0][n - 1];
}

bool resuelveCaso() {
	string palabra;
	cin >> palabra;
	if (!cin)
		return false;
	cout << resolver(palabra) << '\n';
	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/30/datos.txt");
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