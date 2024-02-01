
/*@ <authors>
 *
 * Alejandro Vida Ramírez de Arellano F99
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

/*
            { c1               si n == 1
    T(n) =  {                                       Aplicando el teorema de la division a = 1, b = 10, k = 0 como a == b^k entonces el coste es de la forma O(n^k log n) = O(log n)
            { T(n/2) + c2 si   si n > 1             Siendo n el numero de digitos del numero en decimal

*/

string decimal_a_binario(const int n) {
    if (n < 2) {
        return to_string(n);
    }
    else {
        return decimal_a_binario(n / 2) + to_string(n % 2);
    }
}

void resuelveCaso() {

    int n;
    cin >> n;
    cout << decimal_a_binario(n) << "\n";

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
