// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>

using namespace std;

struct pase{
	int inicio;
	int fin;

	bool operator < (const pase& p2) const{
		if (inicio < p2.inicio)
			return true;
		else return false;
	}
};

bool resuelveCaso() {
	int peliculas;
	cin >> peliculas;
	if (peliculas == 0)
		return false;
	list<pase> listaPeliculas;
	char c;
	int h_ini, m_ini , dur;
	for (int i = 0; i < peliculas; i++){
		cin >> h_ini >> c >> m_ini >> dur;
		int ini = h_ini * 60 + m_ini;
		listaPeliculas.push_back({ ini, ini + dur });
	}
	listaPeliculas.sort();
	int vistas = 0;
	while (!listaPeliculas.empty()){
		pase peli = listaPeliculas.front();
		listaPeliculas.pop_front();
		if (!listaPeliculas.empty() && listaPeliculas.front().inicio < (peli.fin + 10)){
			if(listaPeliculas.front().fin > peli.fin){
				listaPeliculas.pop_front();
				listaPeliculas.push_front(peli);
			}
		}
		else vistas++;
	}
	cout << vistas << '\n';
	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/24/datos.txt");
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