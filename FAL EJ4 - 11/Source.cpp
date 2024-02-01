/*@ <authors>
 *
 * Alejandro Vida Ramírez de Arellano F99
 *
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

int resolver(const vector<int>& v, const int ini, const int fin) {
    if (ini + 1 == fin)
        return v[ini];
    else {
        int mit = (ini + fin) / 2;
        if (v[mit] > v[mit - 1]) // Si en la curva el valor de delante de la mitad es mas pequeño entonces el minimo estara a su izq
            return resolver(v, ini, mit);
        else
            return resolver(v, mit, fin);
    }
}

bool resuelveCaso() {

    int n;
    cin >> n;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<int> v(n);
    for (int& i : v)
        cin >> i;

    cout << resolver(v,0,n) << endl;

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
