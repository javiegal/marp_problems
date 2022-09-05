// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int resolver(string p1, string p2){
	int n1 = p1.size(), n2 = p2.size();
	vector<vector<int>> tabla(n1+1, vector<int>(n2+1, 0));
	for (int i = 1; i <= n1; i++){
		for (int j = 1; j <= n2; j++){
			if (p1.at(i - 1) == p2.at(j - 1))
				tabla[i][j] = tabla[i-1][j-1] + 1;
			else
				tabla[i][j] = max(tabla[i - 1][j], tabla[i][j - 1]);
		}
	}
	return tabla[n1][n2];
}

bool resuelveCaso() {
	string p1, p2;
	cin >> p1;
	if (!cin)
		return false;
	cin >> p2;
	cout << resolver(p1, p2) << '\n';
	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/31/datos.txt");
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