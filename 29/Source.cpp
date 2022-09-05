// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

const int INFINITO = 1000;

bool resolver(vector<int> const& ptsSectores, int puntuacion, int & numDardos, vector<int> & cuales){
	int n = ptsSectores.size();
	vector<vector<int>> v(n+1, vector<int>(puntuacion + 1, INFINITO));
	for (int i = 0; i <= n; i++)
		v[i][0] = 0;
	for (int j = 1; j <= n; j++){
		for (int k = 1; k <= puntuacion; k++){
			if (ptsSectores[j - 1] > k)
				v[j][k] = v[j - 1][k];
			else
				v[j][k] = min(v[j - 1][k], v[j][k - ptsSectores[j - 1]] + 1);
		}
	}
	numDardos = v[n][puntuacion];
	int i = n, j = puntuacion;
	if (numDardos < INFINITO){
		while (j > 0){
			if (ptsSectores[i - 1] <= j && v[i][j] == v[i][j - ptsSectores[i - 1]] + 1){
				cuales.push_back(ptsSectores[i - 1]);
				j = j - ptsSectores[i - 1];
			}
			else
				i--;
		}
	}
	return numDardos < INFINITO;
}

bool resuelveCaso() {
	int puntuacion, sectores;
	cin >> puntuacion;
	if (!cin)
		return false;
	cin >> sectores;
	vector<int> ptsSectores(sectores);
	for (int i = 0; i < sectores; i++)
		cin >> ptsSectores[i];
	
	int numDardos;
	vector<int> cuales;

	bool sol = resolver(ptsSectores, puntuacion, numDardos, cuales);

	if (sol){
		cout << numDardos << ": ";
		for (int i = 0; i < cuales.size(); i++)
			cout << cuales[i] << ' ';
	}
	else
		cout << "IMPOSIBLE";
	cout << '\n';
	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/29/datos.txt");
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