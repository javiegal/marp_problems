// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"

using namespace std;


bool resuelveCaso() {
	int parejas, p;
	PriorityQueue<int> min;
	PriorityQueue<int, greater<int>> max;
	cin >> p >> parejas;
	if (p == 0 && parejas == 0)
		return false;
	max.push(p);
	for (int i = 0; i < parejas; i++){
		for (int j = 0; j < 2; j++){
			cin >> p;
			if (max.top() <= p)
				min.push(p);
			else max.push(p);
			if (max.size() > min.size() + 1){
				int elem;
				max.pop(elem);
				min.push(elem);
			}
			if (min.size() > max.size() + 1){
				int elem;
				min.pop(elem);
				max.push(elem);
			}
		}
		if (min.size() < max.size())
			cout << max.top();
		else cout <<  min.top();
		cout << ' ';
	}
	cout << '\n';
	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/07/datos.txt");
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