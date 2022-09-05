// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include <vector>
#include <set>


using namespace std;

vector<int> calculaLista(set<int> const & arb, int min, int max){
	if (arb.empty())
		return{};
	else{
		vector<int> sol;
		auto it = arb.lower_bound(min);
		while (*it <= max && it != arb.end()){
			sol.push_back(*it);
			++it;
		}
		return sol;
	}
}

bool resuelveCaso() {
	int num, elem;
	cin >> num;
	if (num == 0)
		return false;
	set<int> arb;
	for (int i = 0; i < num; i++){
		cin >> elem;
		arb.insert(elem);
	}
	int min, max;
	cin >> min >> max;
	auto sol = calculaLista(arb, min, max);
	for (auto e : sol){
		cout << e << " ";
	}
	cout << '\n';
	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/03/datos.txt");
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