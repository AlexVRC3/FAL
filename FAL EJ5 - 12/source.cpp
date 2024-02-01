
/*@ <authors>
 *
 * Alejandro Vida Ramírez de Arellano F99
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

using matriz = vector<vector<int>>;

//aproximamos por la recaudación máxima por las teclas que quedan pulsar
int poda(const int k, const int m, const int rec_max) {
	return (m - k + 1) * rec_max;
}

//La única restricción es que el castigo no debe superar C
bool esCompatible(const int castigo, const int C) {
	return castigo <= C;
}

/*
 * Espacio de búsqueda: árbol de profundidad m (la longitud de la secuencia) y anchura de n (las distintas teclas).
 * Marcadores: - rec: la recompensa acumulada hasta ahora.
 *             - castigo: el castigo acumulado hasta ahora.
 * Solución: - pulsa: vector de tamaño m con la secuencia de teclas.
 *           - maxRec: la recompensa máxima.
 * Poda: aproximar por la máxima recompensa por el número de teclas por pulsar
 */


void teclas(int k, const int n, const int m, const int C, const matriz& recompensa, const int rec_max, int& maxRec, int& castigo, int& rec, vector<int>& pulsa) {
	for (int i = 0; i < n; i++) {
		pulsa[k] = i; //asignamos la tecla
		if (k > 0) {//la primera tecla puede ser cualquiera y no hay recompensas
			//Marcamos
			if (recompensa[pulsa[k - 1]][i] >= 0) //recompensa
				rec += recompensa[pulsa[k - 1]][i];
			else //castigo
				castigo -= recompensa[pulsa[k - 1]][i];
		}
		if (esCompatible(castigo, C)) {
			if (k == m - 1) {//Es solución
				if (rec > maxRec)
					maxRec = rec; //nueva recompensa máxima
			}
			else {//no es solución
				int beneficio = poda(k, m, rec_max);
				if (rec + beneficio > maxRec) //podamos si no mejora lo esperado
					teclas(k + 1, n, m, C, recompensa, rec_max, maxRec, castigo, rec, pulsa);
			}
		}
		if (k > 0) {//Desmarcamos
			if (recompensa[pulsa[k - 1]][i] >= 0)
				rec -= recompensa[pulsa[k - 1]][i];
			else
				castigo += recompensa[pulsa[k - 1]][i];
		}
	}
}


int teclas(const int n, const int m, const int C, const matriz& recompensa, const int rec_max) {
	//Marcadores
	int castigo = 0; //castigos que recibe el ratón
	int rec = 0; //recompensa actual
	//Solucion
	int maxRec = -1;  //recompensa máxima
	vector<int> sol(m);  //las teclas pulsadas
	//Llamada
	teclas(0, n, m, C, recompensa, rec_max, maxRec, castigo, rec, sol);
	return maxRec;
}

void resuelveCaso() {
	int n, m, C; //teclas, longitud de la secuencia y castigo
	cin >> n >> m >> C;
	matriz recompensa(n, vector<int>(n));
	int rec_max = 0; //recompensa máxima para la poda
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> recompensa[i][j];   //recompensa por pulsar j después de i
			if (recompensa[i][j] >= rec_max)
				rec_max = recompensa[i][j];
		}
	int rec = teclas(n, m, C, recompensa, rec_max);

	if (rec > -1)
		cout << rec << endl;
	else
		cout << "NO" << endl;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
