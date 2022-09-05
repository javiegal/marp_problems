// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct pelicula{
	int ini;
	int duracion;

	bool operator <(const pelicula& p2) const{
		return ini < p2.ini;
	}
};

int resolver(vector<pelicula> const& cart){
	int n = cart.size();
	vector<int> sol(n, 0);
	for (int i = n-2; i >= 0; i--){
		sol[i] = sol[i + 1];
		for (int j = i+1; j < n; j++){
			if (cart[i].ini + cart[i].duracion + 10 <= cart[j].ini)
				sol[i] = max(sol[i], sol[j] + cart[i].duracion);
		}
	}
	return sol[0];
}

bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0)
		return false;
	vector<pelicula> cart(n+1);
	char aux;
	int h, m;
	for (int i = 0; i < n; i++){
		cin >> h >> aux >> m;
		cart[i].ini = h * 60 + m;
		cin >> cart[i].duracion;
	}
	cart[n].ini = 24 * 60 + 10;
	cart[n].duracion = 0;
	sort(cart.begin(), cart.end());

	cout << resolver(cart) << '\n';

	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/37/datos.txt");
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