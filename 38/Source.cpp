// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int resolver(string texto, unordered_set<string> const& simbolos, int tam){
	vector<int> tabla(tam, 0);
	for (int i = tam - 1; i >= 0; i--){
		int suma = 0;
		for (int k = i; k < tam && k < i + 3; k++){
			string aux = texto.substr(i, k - i + 1);
			if (simbolos.count(aux) || aux == "0"){
				if (k == tam - 1)
					suma++;
				else
					suma += tabla[k + 1];
				suma %= 1000000007;
			}
		}
		tabla[i] = suma;
	}
	return tabla[0];
}

bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0)
		return false;
	unordered_set<string> simbolos(n);
	string elem;
	for (int i = 0; i < n; i++){
		cin >> elem;
		simbolos.insert(elem);
	}
	string texto;
	cin >> texto;
	cout << resolver(texto, simbolos, texto.size()) << '\n';

	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/38/datos.txt");
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