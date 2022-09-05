// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int INFINITO = 1000;

bool resolver(vector<vector<int>> tabla, int & separacion){
	int n = tabla[0].size();
	separacion = 0;
	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				tabla[i][j] = min(tabla[i][k] + tabla[k][j], tabla[i][j]);
				if (k == n - 1){
					if(tabla[i][j] == INFINITO)
						return false;
					separacion = max(tabla[i][j], separacion);
				}
			}
		}
	}
	return true;
}

bool resuelveCaso() {
	int numPersonas, relaciones;
	cin >> numPersonas;
	if (!cin)
		return false;
	cin >> relaciones;
	unordered_map<string, int> personas;
	int pos = 0;
	string p1, p2;
	vector<vector<int>> tabla(numPersonas, vector<int>(numPersonas, INFINITO));
	for (int k = 0; k < numPersonas; k++)
		tabla[k][k] = 0;
	for (int i = 0; i < relaciones; i++){
		cin >> p1 >> p2;
		if (personas.count(p1) == 0){
			personas.insert({ p1, pos });
			pos++;
		}
		if (personas.count(p2) == 0){
			personas.insert({ p2, pos });
			pos++;
		}
		tabla[personas.at(p1)][personas.at(p2)] = 1;
		tabla[personas.at(p2)][personas.at(p1)] = 1;
	}
	
	int separacion;
	if (resolver(tabla, separacion))
		cout << separacion;
	else 
		cout << "DESCONECTADA";
	cout << '\n';
	
	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/32/datos.txt");
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