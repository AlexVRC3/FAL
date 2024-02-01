
/*@ <authors>
 *
 * Alejandro Vida Ramírez de Arellano F99
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;


/*@ <answer>

El espacio de soluciones es un arbol de profundidad n que es el numero de niños y de anchura m que es el numero de juguetes. Se utiliza un marcador (asignados) para saber si
ese juguete ya ha sido asignado a un niño previamente. En cada nivel del arbol se elige que juguete se le asigna a ese niño teniendo en cuenta los valores del marcador y de esta
manera cuando tengamos los juguetes asignados comprobaremos si la satisfaccion obtenida es la mayor posible o no.

Estimacion: Consiste en llevar almacenados en un vector las mejores satisfacciones posibles en diferentes momentos de la solucion. (por ejemplo si tenemos 1 juguete asignado o si tenemos 2.. etc)
de esta manera solo si nuestra solucion parcial + el mejor valor posible de la siguiente iteracion supera el mejor valor obtenido hasta el momento sera cuando nos interese completar
la solucion.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

using matriz = vector<vector<int>>;

void papa_noel(const int n, const int m, const int k, const matriz& satisfacciones, vector<bool>& asignados, int &satActual, int &maxSat, const vector<int> &max_satisfacciones) {
    for (int i = 0; i < m; i++)
    {
        if (!asignados[i]) {
            satActual += satisfacciones[k][i];
            if (k == n - 1 && satActual > maxSat) { // Si es solucion
                maxSat = satActual;
            }
            else if (k < n - 1 && satActual + max_satisfacciones[k + 1] > maxSat) { // Si es completable
                asignados[i] = true;
                papa_noel(n, m, k + 1, satisfacciones, asignados, satActual, maxSat, max_satisfacciones);
                asignados[i] = false;
            }
            satActual -= satisfacciones[k][i];
        }
    }
}

bool resuelveCaso() {

    int m, n;
    cin >> m >> n;

    if (!std::cin)  // fin de la entrada
        return false;
    matriz satisfacciones (n, vector<int>(m));
    vector<int> max_satisfacciones(n,-1); // max satisfaccion por niño
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        max = INT_MIN;
        for (int j = 0; j < m; j++)
        {
            cin >> satisfacciones[i][j];
            if (satisfacciones[i][j] > max) {
                max = satisfacciones[i][j];
            }
                
        }
        max_satisfacciones[i] = max;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        max_satisfacciones[i] += max_satisfacciones[i + 1];
    }
    int maxSat = 0;
    int satActual = 0;
    vector<bool> asignados(m, false);
    papa_noel(n, m, 0, satisfacciones, asignados, satActual, maxSat,max_satisfacciones);

    cout << maxSat << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
