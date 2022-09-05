// DG, Javier Gallego Gutiérrez

#include <iostream>
#include <fstream>
#include "ConjuntosDisjuntos.h"
#include <vector>
#include <string>

using namespace std;


size_t actualizarResultado(ConjuntosDisjuntos & cd, vector<bool> & mar, size_t filas, size_t columnas, size_t & max){
	size_t x, y;
	cin >> x >> y;
	size_t pos = (x - 1) * columnas + (y - 1);
	mar[pos] = false;
	if (((y - 1) > 0)){
		if (!mar[pos - 1])
			cd.unir(pos, pos - 1); // izquierda
		if (((x - 1) > 0) && !mar[pos - columnas - 1])
			cd.unir(pos, pos - columnas - 1); // arriba-izquierda
		if ((x < filas) && !mar[pos + columnas - 1])
			cd.unir(pos, pos + columnas - 1); // abajo-izquierda
	}
	if ((y < columnas)){
		if (!mar[pos + 1])
			cd.unir(pos, pos + 1); // derecha
		if (((x - 1) > 0) && !mar[pos - columnas + 1])
			cd.unir(pos, pos - columnas + 1); //arriba-derecha
		if ((x < filas) && !mar[pos + columnas + 1])
			cd.unir(pos, pos + columnas + 1); // abajo-derecha
	}
	if (((x - 1) > 0) && !mar[pos - columnas])
		cd.unir(pos, pos - columnas); // arriba
	if ((x < filas) && !mar[pos + columnas])
		cd.unir(pos, pos + columnas); // abajo
	size_t n = cd.size(pos);
	if (n > max)
		return max = n;
	else return max;
}

bool resuelveCaso() {
	size_t filas, columnas;
	cin >> filas;
	if (!cin)
		return false;
	cin >> columnas;
	size_t tam = filas*columnas;
	vector<bool> mar(tam);
	string linea;
	cin.ignore();
	char elem;
	for (size_t i = 0; i < filas; i++){
		getline(cin, linea);
		for (size_t l = 0; l < columnas; l++)	{
			elem = linea.at(l);
			if (elem == '#')
				mar[i*columnas + l] = false;
			else mar[i*columnas + l] = true;
		}
	}
	ConjuntosDisjuntos cd(tam);
	size_t max = 0;
	for (size_t k = 0; k < tam; k++){	// unir celdas de petróleo contiguas
		if (!mar[k]){
			size_t aux = cd.size(k);
			if ((k%columnas != columnas - 1) && !mar[k + 1])
				cd.unir(k, k + 1);
			if (k < (columnas*(filas - 1)) && !mar[k + columnas])
				cd.unir(k, k + columnas);
			if (k < (columnas*(filas - 1)) && (k%columnas != columnas - 1) && !mar[k + columnas + 1])
				cd.unir(k, k + columnas + 1);
			if (k < (columnas*(filas - 1)) && (k%columnas != 0) && !mar[k + columnas - 1])
				cd.unir(k, k + columnas - 1);
			if (aux > max)
				max = aux;
		}
	}
	cout << max << ' ';
	int numFotos;
	cin >> numFotos;
	for (int j = 0; j < numFotos; j++)
		cout << actualizarResultado(cd, mar, filas, columnas, max) << ' ';
	cout << '\n';
	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Javier/Documents/CARRERA/2017-18/14/datos.txt");
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