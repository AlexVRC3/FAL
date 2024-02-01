
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

                       { c1 si n == 1
                T(n) = {                            Como a = 1 y b = 2 y k = 0 el coste de esta recurrencia esta en O(log N)
                       { T(n/2) + c2 si n > 1

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
int numACantar(const vector<int>& v, int ini, int fin, int numCantado) {
    if (ini == fin - 1) // Solo un numero
        return numCantado + ini == v[ini] ? v[ini] : -1;
    else {
        int mitad = (ini + fin) / 2;
        if (mitad + numCantado < v[mitad]) {
            return numACantar(v, ini, mitad,numCantado);
        }
        else {
            return numACantar(v, mitad, fin, numCantado);
        }
    }
}

void resuelveCaso() {

    int n,numCantado;
    cin >> n >> numCantado;

    vector<int> datos(n);
    for (int i = 0; i < n; i++)
    {
        cin >> datos[i];
    }

    int sol = numACantar(datos, 0, datos.size(), numCantado);
    if (sol != -1)
        cout << sol << endl;
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
