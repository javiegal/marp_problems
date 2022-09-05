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
	int tiempo;
	int tiempo_optimista;
	vector<bool> asignado;

	bool operator > (const nodo& n2) const{
		return tiempo_optimista > n2.tiempo_optimista;
	}
};

int resolver(vector<vector<int>> const& tiempos, vector<int> const& rap, vector<int> const& lent){
	int res;
	int numFuncionarios = tiempos[0].size();
	vector<int> c_optimista(numFuncionarios + 1), c_pesimista(numFuncionarios + 1);
	c_optimista[numFuncionarios] = 0;
	c_pesimista[numFuncionarios] = 0;
	for (int k = numFuncionarios - 1; k >= 0; k--){
		c_pesimista[k] = c_pesimista[k + 1] + lent[k];
		c_optimista[k] = c_optimista[k + 1] + rap[k];
	}
	priority_queue<nodo, vector<nodo>, greater<nodo> > cola;
	nodo x, y;
	y.k = 0;
	y.asignado = vector<bool>(numFuncionarios, false);
	y.tiempo = 0;
	y.tiempo_optimista = c_optimista[0];
	cola.push(y);
	res = c_pesimista[0];
	while (!cola.empty() && cola.top().tiempo_optimista <= res){
		y = cola.top();
		cola.pop();
		x.k = y.k + 1;
		x.asignado = y.asignado;
		for (int t = 0; t < numFuncionarios; t++){
			if (!x.asignado[t]){
				x.asignado[t] = true;
				x.tiempo = y.tiempo + tiempos[x.k - 1][t];
				x.tiempo_optimista = x.tiempo + c_optimista[x.k];
				if (x.tiempo_optimista <= res){
					if (x.k == numFuncionarios)
						res = x.tiempo;
					else{
						cola.push(x);
						res = min(res, x.tiempo + c_pesimista[x.k]);
					}
				}
				x.asignado[t] = false;
			}
		}
	}
	return res;
}

bool resuelveCaso() {
	int numFuncionarios;
	cin >> numFuncionarios;
	if (numFuncionarios == 0)
		return false;

	int tiempo, lento, rapido;
	vector<int> rap(numFuncionarios), lent(numFuncionarios);
	vector<vector<int>> tiempos(numFuncionarios, vector<int>(numFuncionarios));
	for (int i = 0; i < numFuncionarios; i++){
		cin >> tiempos[i][0];
		lento = tiempos[i][0];
		rapido = tiempos[i][0];
		for (int j = 1; j < numFuncionarios; j++){
			cin >> tiempo;
			rapido = min(rapido, tiempo);
			lento = max(lento, tiempo);
			tiempos[i][j] = tiempo;
		}
		lent[i] = lento;
		rap[i] = rapido;
	}
	
	cout << resolver(tiempos, rap, lent) << '\n';

	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/39/datos.txt");
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