// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include <functional>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct nodo{
	int k;
	int beneficio;
	float beneficio_optimista;
	//vector<bool> solucion;
	float ocupada1;
	float ocupada2;

	bool operator < (const nodo& n2) const{
		return beneficio_optimista < n2.beneficio_optimista;
	}
};

struct tema{
	int duracion;
	int puntuacion;
};

bool comp(const tema &t1, const tema &t2)
{
	return ((float)(t1.puntuacion) / (float)(t1.duracion)) > ((float)(t2.puntuacion) / (float)(t2.duracion));
}

float calc_optimista(vector<tema> const& temas, int T, int k, int beneficio, float ocupada1, float ocupada2){
	int n = temas.size(), j = k + 1;
	float hueco = T - (ocupada1 + ocupada2), opt = beneficio;
	while (j <= n && temas[j-1].duracion <= hueco){
		hueco = hueco - temas[j-1].duracion;
		opt = opt + temas[j-1].puntuacion;
		j++;
	}
	if (j <= n)
		opt = opt + (hueco / temas[j-1].duracion)*temas[j-1].puntuacion;
	return opt;
}

int calc_pesimista(vector<tema> const& temas, int T, int k, int beneficio, float ocupada1, float ocupada2){
	float ocupada_aux1 = ocupada1, ocupada_aux2 = ocupada2;
	int n = temas.size(), pes = beneficio, j = k + 1;
	while (j <= n && (ocupada_aux1 <= T / 2 || ocupada_aux2 <= T / 2)){
		if (ocupada_aux1 + temas[j-1].duracion <= T / 2){
			ocupada_aux1 = ocupada_aux1 + temas[j-1].duracion;
			pes = pes + temas[j-1].puntuacion;
		}
		else{
			if (ocupada_aux2 + temas[j-1].duracion <= T / 2){
				ocupada_aux2 = ocupada_aux2 + temas[j-1].duracion;
				pes = pes + temas[j-1].puntuacion;
			}
		}
		j++;
	}
	return pes;
}

int resolver(vector<tema> const& temas, int T){
	int res;

	int n = temas.size(), pes;
	nodo x, y;
	priority_queue<nodo> cola;
	y.k = 0;
	y.ocupada1 = 0;
	y.ocupada2 = 0;
	y.beneficio = 0;
	y.beneficio_optimista = calc_optimista(temas, T, y.k, y.beneficio, y.ocupada1, y.ocupada2);
	cola.push(y);
	res = calc_pesimista(temas, T, y.k, y.beneficio, y.ocupada1, y.ocupada2);
	while (!cola.empty() && cola.top().beneficio_optimista >= res){
		y = cola.top();
		cola.pop();
		x.k = y.k + 1;
		if (y.ocupada1 + temas[x.k-1].duracion <= T / 2){
			x.ocupada1 = y.ocupada1 + temas[x.k-1].duracion;
			x.ocupada2 = y.ocupada2;
			x.beneficio = y.beneficio + temas[x.k-1].puntuacion;
			x.beneficio_optimista = y.beneficio_optimista;
			if (x.k == n)
				res = x.beneficio;
			else cola.push(x);
		}
		if (y.ocupada1 != y.ocupada2){
			if (y.ocupada2 + temas[x.k-1].duracion <= T / 2){
				x.ocupada1 = y.ocupada1;
				x.ocupada2 = y.ocupada2 + temas[x.k-1].duracion;
				x.beneficio = y.beneficio + temas[x.k-1].puntuacion;
				x.beneficio_optimista = y.beneficio_optimista;
				if (x.k == n)
					res = x.beneficio;
				else{
					cola.push(x);
					pes = calc_pesimista(temas, T, x.k, x.beneficio, x.ocupada1, x.ocupada2);
					res = max(res, pes);
				}
			}
		}
		x.ocupada1 = y.ocupada1;
		x.ocupada2 = y.ocupada2;
		x.beneficio = y.beneficio;
		x.beneficio_optimista = calc_optimista(temas, T, x.k, x.beneficio, x.ocupada1, x.ocupada2);
		if (x.beneficio_optimista >= res){
			if (x.k == n)
				res = x.beneficio;
			else{
				cola.push(x);
				pes = calc_pesimista(temas, T, x.k, x.beneficio, x.ocupada1, x.ocupada2);
				res = max(res, pes);
			}
		}
	}



	return res;
}

bool resuelveCaso() {
	int numCanciones, durCara;
	cin >> numCanciones;
	if (numCanciones == 0)
		return false;
	cin >> durCara;
	vector<tema> temas(numCanciones);

	for (int i = 0; i < numCanciones; i++)
		cin >> temas[i].duracion >> temas[i].puntuacion;

	sort(temas.begin(), temas.end(), comp);

	int T = 2 * durCara;
	cout << resolver(temas, T) << '\n';

	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/40/datos.txt");
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