// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include <utility>
#include <list>
#include "ConjuntosDisjuntos.h"
#include "Matriz.h"

using namespace std;


bool resuelveCaso() {
	size_t N, M, K, numArboles;
	cin >> N;
	if (!cin)
		return false;
	cin >> M >> K >> numArboles;
	size_t tam = (N + 1)*(M + 1);
	ConjuntosDisjuntos cd(tam);
	Matriz<bool> matrix(N + 1, M + 1, false);
	list<pair<size_t, size_t>> cortados;
	size_t e1, e2;
	for (size_t i = 0; i < numArboles; i++){
		cin >> e1 >> e2;
		cortados.push_back({ e1, e2 });
	}
	matrix[0][0] = true;
	matrix[N][M] = true;
	bool enc = false;
	size_t elem1, elem2 = 0;
	while (!cortados.empty() && !enc){
		auto j = cortados.back();
		cortados.pop_back();
		matrix[j.first][j.second] = true;
		size_t pos = j.first*(M + 1) + j.second;
		for (size_t k = 0; k <= K; k++){
			for (size_t l = 0; l <= K; l++){
				if ((k*k + l*l) <= (K*K) && (k*k + l*l) > 0){
					if (matrix.posCorrecta(j.first + k, j.second + l) && matrix[j.first + k][j.second + l])
						cd.unir(pos, pos + (M+1)*k + l);

					if (matrix.posCorrecta(j.first + k, j.second - l) && matrix[j.first + k][j.second - l])
						cd.unir(pos, pos + (M + 1)*k - l);

					if (matrix.posCorrecta(j.first - k, j.second + l) && matrix[j.first - k][j.second + l])
						cd.unir(pos, pos - (M + 1)*k + l);

					if (matrix.posCorrecta(j.first - k, j.second - l) && matrix[j.first - k][j.second - l])
						cd.unir(pos, pos - (M + 1)*k - l);
				}
			}
		}
		if (cd.buscar(0) == cd.buscar(tam - 1)){
			enc = true;
			elem1 = j.first;
			elem2 = j.second;
		}
	}
	if (enc)
		cout << elem1 << ' ' << elem2;
	else cout << "NUNCA SE PUDO";
	cout << '\n';
	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/18/datos.txt");
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