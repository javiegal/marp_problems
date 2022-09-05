// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int INFINITO = 1000000000;

int resolver(vector<int> const& puntos){
	int n = puntos.size() - 1;
	vector<vector<int>> tabla(n, vector<int>(n, 0));
	vector<vector<int>> p(n, vector<int>(n, 0));
	for (int d = 1; d < n; d++){
		for (int i = 0; i < n - d; i++){
			int j = i + d;
			tabla[i][j] = INFINITO;
			for (int k = i; k < j; k++){
				if (tabla[i][k] + tabla[k + 1][j] + 2 * (puntos[j + 1] - puntos[i]) < tabla[i][j])
					p[i][j] = k+1;
				tabla[i][j] = min(tabla[i][k] + tabla[k + 1][j] + 2 * (puntos[j + 1] - puntos[i]), tabla[i][j]);
			}
		}
	}
	return tabla[0][n - 1];
}

bool resuelveCaso() {
	int l, n;
	cin >> l >> n;
	if (l == 0 && n == 0)
		return false;

	vector<int> puntos(n+2);
	puntos[0] = 0;
	for (int i = 1; i <= n; i++)
		cin >> puntos[i];
	puntos[n + 1] = l;

	cout << resolver(puntos) << '\n';

	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/33/datos.txt");
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