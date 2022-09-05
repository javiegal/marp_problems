// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

void resolver(vector<int> const& tiempo, vector<int> const& valor, int segundos, int & v, vector<pair<int,int>> & escogidos){
	int n = tiempo.size();
	vector<vector<int>> max_oro(n + 1 , vector<int>(segundos + 1, 0));
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= segundos; j++){
			if (3 * tiempo[i - 1] > j)
				max_oro[i][j] = max_oro[i - 1][j];
			else
				max_oro[i][j] = max(max_oro[i - 1][j], max_oro[i - 1][j - 3 * tiempo[i - 1]] + valor[i - 1]);
		}
	}
	v = max_oro[n][segundos];
	int resto = segundos;
	for (int i = n; i >= 1; i--){
		if (max_oro[i][resto] > max_oro[i - 1][resto]){
			escogidos.push_back({ tiempo[i - 1], valor[i - 1] });
			resto = resto - 3*tiempo[i - 1];
		}
	}
}

bool resuelveCaso() {
	int segundos, numCofres;
	cin >> segundos;
	if (!cin)
		return false;
	cin >> numCofres;
	vector<int> tiempo(numCofres), valor(numCofres);
	for (int i = 0; i < numCofres; i++)
		cin >> tiempo[i] >> valor[i];
	int maxOro;
	vector<pair<int, int>> escogidos;
	resolver(tiempo, valor, segundos, maxOro, escogidos);

	cout << maxOro << '\n';
	cout << escogidos.size() << '\n';
	while (!escogidos.empty()){
		cout << escogidos.back().first << ' ' << escogidos.back().second << '\n';
		escogidos.pop_back();
	}
	cout << "----\n";
	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/28/datos.txt");
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