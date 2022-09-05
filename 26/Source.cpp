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
		if (inicio < p2.inicio )
			return true;
		else if (inicio == p2.inicio && p2.fin < fin)
			return true;
		else return false;
	}
};

bool resuelveCaso() {
	int c,f,n;
	cin >> c >> f >> n;
	if (c == 0 && f == 0 && n == 0)
		return false;
	list<pase> trabajos;
	int ini, fin;
	for (int i = 0; i < n; i++){
		cin >> ini >> fin;
		trabajos.push_back({ ini, fin });
	}
	trabajos.sort();
	bool imposible = false, acabado = false;
	int prim;
	if (!trabajos.empty())
		prim = trabajos.front().inicio - 1;
	int min = 0, ult = c-1;
	while (!trabajos.empty() && !imposible && !acabado){
		auto elem = trabajos.front();
		trabajos.pop_front();
		if (elem.inicio > ult+1)
			imposible = true;
		if (elem.fin > ult+1){
			if (elem.inicio > prim){
				prim = ult + 1;
				min++;
			}
			ult = elem.fin-1;
			if (ult >= f-1)
				acabado = true;
		}
	}
	if (imposible || !acabado)
		cout << "IMPOSIBLE";
	else cout << min;
	cout << '\n';
	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/26/datos.txt");
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