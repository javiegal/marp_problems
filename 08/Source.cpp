// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include <cmath>
#include "PriorityQueue.h"

using namespace std;


struct instrumento{
	double num;
	double part;
	bool operator > (const instrumento& i2) const{
		if (num / part > i2.num / i2.part)
			return true;
		else return false;
	}
};

int resolver(PriorityQueue<instrumento, greater<instrumento>> cola, int r){
	instrumento inst;
	for (int i = 0; i < r; i++){
		cola.pop(inst);
		inst.part++;
		cola.push(inst);
	}
	inst = cola.top();
	return ceil(inst.num / inst.part);
}

bool resuelveCaso() {
	int n, p;
	cin >> p;
	if (!cin)
		return false;
	cin >> n;
	instrumento inst;
	PriorityQueue<instrumento, greater<instrumento>> cola;
	for (int i = 0; i < n; i++){
		cin >> inst.num;
		inst.part = 1;
		cola.push(inst);
	}
	cout << resolver(cola, p-n) << '\n';
	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/08/datos.txt");
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