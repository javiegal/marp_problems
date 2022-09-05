// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include "Grafo.h"
#include <vector>
#include <utility>

using namespace std;

pair<bool, size_t> resolver(Grafo const& graf, size_t entrada, size_t puerta){
	BreadthFirstPaths bfp = BreadthFirstPaths(graf, entrada);
	if (bfp.hasPathTo(puerta))
		return{ true, bfp.distance(puerta) };
	else return{ false, -1 };
}

void resuelveCaso() {
	size_t ancho, alto, entrada, puerta;
	cin >> ancho >> alto;
	Grafo graf = Grafo(ancho*alto);
	char elem;
	vector<bool> inhabilitadas(ancho * alto);					// casillas por las que no se podrá pasar
	vector<bool> muros(ancho * alto);
	vector<pair<size_t,size_t>> sensores;		// sensor y su categoría
	for (size_t i = 0; i < ancho*alto; i++){	// lectura de datos
		cin >> elem;
		if (elem == '#'){	// muro
			inhabilitadas[i] = true;
			muros[i] = true;
		}
		else if (elem >= '0' && elem <= '9'){	// sensor
			inhabilitadas[i] = true;
			sensores.push_back({ i, (size_t)elem - '0' });
		}
		else{
			if (elem == 'E')
				entrada = i;
			else if (elem == 'P')
				puerta = i;
			inhabilitadas[i] = false;
		}
	}
	for (auto sens : sensores){		// se inhabilitan las casillas que indican los sensores
		size_t j;
		bool fin;
		for (int dir = 0; dir < 4; dir++){
			fin = false;
			size_t eCamb;
			j = 1;
			while (!fin && j <= sens.second){
				if (dir == 0){ // hacia arriba
					if (ancho * j <= sens.first){	// comprobar si se sale
						eCamb = sens.first - ancho*j;
						if (muros[eCamb])	// comprueba si hay un muro
							fin = true;
						else inhabilitadas[eCamb] = true;
					}
					else
						fin = true;
				}
				else if (dir == 1){ // hacia la izquierda
					if ((sens.first%ancho) >= j){
						eCamb = sens.first - j;
						if (muros[eCamb])
							fin = true;
						else inhabilitadas[eCamb] = true;
					}
					else
						fin = true;
				}
				else if (dir == 2){ // hacia la derecha
					if (ancho-(sens.first%ancho) > j){
						eCamb = sens.first + j;
						if (muros[eCamb])
							fin = true;
						else inhabilitadas[eCamb] = true;
					}
					else
						fin = true;
				}
				else{ // hacia abajo
					if (((ancho*alto) - sens.first) > j*ancho){
						eCamb = sens.first + ancho*j;
						if (muros[eCamb])
							fin = true;
						else inhabilitadas[eCamb] = true;
					}
					else
						fin = true;
				}
				j++;
			}
		}
	}
	for (size_t k = 0; k < ancho*alto; k++){ // se ponen las aristas que indican los movimientos posibles
		if (!inhabilitadas[k]){
			if ((k%ancho != ancho - 1) && !inhabilitadas[k + 1])
				graf.ponArista(k, k + 1);
			if (k < (ancho*(alto - 1)) && !inhabilitadas[k + ancho])
				graf.ponArista(k, k + ancho);
		}
	}
	pair<bool, size_t> sol = resolver(graf, entrada, puerta);
	if (sol.first)
		cout << sol.second;
	else cout << "NO";
	cout << '\n';
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/12/datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}