// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int INFINITO = 1000;

int resolver(vector<vector<bool>> const& tableta){
	int f = tableta.size(), c = tableta[0].size();
	vector<vector<vector<vector<int>>>> matriz(f, vector<vector<vector<int>>>(f, vector<vector<int>>(c, vector<int>(c, 0))));
	vector<vector<vector<vector<int>>>> sabor(f, vector<vector<vector<int>>>(f, vector<vector<int>>(c, vector<int>(c, 1))));
	for (int i1 = f-1; i1 >= 0; i1--){
		for (int i2 = i1; i2 < f; i2++){
			for (int j1 = c-1; j1 >= 0; j1--){
				for (int j2 = j1; j2 < c; j2++){
					if (i1 == i2 && j1 == j2)
						sabor[i1][i2][j1][j2] = 1;
					else{
						if (i1 != i2){
							sabor[i1][i2][j1][j2] = max(sabor[i1 + 1][i2][j1][j1], sabor[i1][i2][j1][j2]);
							if (tableta[i1][j1] != tableta[i1 + 1][j1])
								sabor[i1][i2][j1][j2] = 2;
						}
						if (j1 != j2){
							sabor[i1][i2][j1][j2] = max(sabor[i1][i1][j1 + 1][j2], sabor[i1][i2][j1][j2]);
							if (tableta[i1][j1] != tableta[i1][j1 + 1])
								sabor[i1][i2][j1][j2] = 2;
						}
						if (j1 != j2 && i1 != i2){
							sabor[i1][i2][j1][j2] = max(sabor[i1 + 1][i2][j1 + 1][j2], sabor[i1][i2][j1][j2]);
							if (tableta[i1][j1] != tableta[i1 + 1][j1 + 1])
								sabor[i1][i2][j1][j2] = 2;
						}
					}

					if (sabor[i1][i2][j1][j2] == 1)
						matriz[i1][i2][j1][j2] = 0;
					else{
						int tempi = INFINITO, tempj = INFINITO;
						for (int k = i1; k < i2; k++){
							if (tempi > matriz[i1][k][j1][j2] + matriz[k + 1][i2][j1][j2])
								tempi = matriz[i1][k][j1][j2] + matriz[k + 1][i2][j1][j2];
						}

						for (int l = j1; l < j2; l++){
							if (tempj > matriz[i1][i2][j1][l] + matriz[i1][i2][l + 1][j2])
								tempj = matriz[i1][i2][j1][l] + matriz[i1][i2][l + 1][j2];
						}
						matriz[i1][i2][j1][j2] = min(tempi, tempj) + 1;
					}
				}
			}
		}
	}
	return matriz[0][f - 1][0][c - 1];
}

bool resuelveCaso() {
	int f, c;
	cin >> f;
	if (!cin)
		return false;
	cin >> c;
	char elem;
	vector<vector<bool>> tableta(f, vector<bool>(c, false));
	for (int i = 0; i < f; i++){
		for (int j = 0; j < c; j++){
			cin >> elem;
			if (elem == '#')
				tableta[i][j] = true;
		}
	}


	cout << resolver(tableta) << '\n';

	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/35/datos.txt");
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