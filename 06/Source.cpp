// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"
#include <vector>

using namespace std;

struct usuario {

int id;
int per;
int sig;
bool operator < (const usuario& u2) const{
		if (sig < u2.sig)
			return true;
		else if (sig > u2.sig)
			return false;
		else{
			if (id < u2.id)
				return true;
			else return false;
		}
	}
};

vector<int> resolver(PriorityQueue<usuario> cola, int k){
	vector<int> sol;
	usuario usu;
	for (int i = 0; i < k; i++){
		cola.pop(usu);
		usu.sig += usu.per;
		sol.push_back(usu.id);
		cola.push(usu);
	}
	return sol;
}

bool resuelveCaso() {
	int n;
	PriorityQueue<usuario> cola;
	cin >> n;
	if (n == 0)
		return false;
	int id, per;
	usuario usu;
	for (int i = 0; i < n; i++){
		cin >> id >> per;
		usu = { id, per, per };
		cola.push(usu);
	}
	int k;
	cin >> k;
	vector<int> sol = resolver(cola, k);
	for (auto e : sol){
		cout << e << '\n';
	}
	cout << "----\n";
	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/06/datos.txt");
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