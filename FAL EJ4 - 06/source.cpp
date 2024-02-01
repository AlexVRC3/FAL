
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
int minimo(const vector<int>& v, int ini, int fin) {
    if (ini == fin - 1) // Solo un numero
        return v[ini];
    else {
        int mitad = (ini + fin) / 2;
        if (v[mitad] > v[ini]) {
            return minimo(v, ini, mitad);
        }
        else {
            return minimo(v, mitad, fin);
        }
    }
}

bool resuelveCaso() {

    int n;
    cin >> n;

    if (!std::cin)  // fin de la entrada
        return false;
    vector<int> datos(n);
    for (int i = 0; i < n; i++)
    {
        cin >> datos[i];
    }

    cout << minimo(datos, 0, datos.size()) << endl;

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
