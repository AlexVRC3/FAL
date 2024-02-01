
/*@ <authors>
 *
 * Alejandro Vida Ramírez de Arellano F99
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


/*
           { c1             si n == 1
    T(n) = {                                Aplicando el teorema de la division con a = 1, b = 2 y k = 0 obtenemos que a == b^k (1 == 2^0) y por ello el coste es O(n^k log n) = O(log n) siendo n el valor del numero de entrada
           { T(n/2) + c2   si n > 1
*/

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int resolver(const vector<int>& agua_dia, const int ini, const int fin, const int G, const int M) {
    if (ini == fin) {
        if (agua_dia[ini] >= (M - ini) * G) return -1;
        else return ini;
    }
    else {
        int mitad = (ini + fin) / 2;
        int aguaRestante = (M - mitad) * G;
        if (agua_dia[mitad] < aguaRestante) {
            return resolver(agua_dia, ini, mitad, G, M);
        }
        else
            return resolver(agua_dia, mitad + 1, fin, G, M);
    }
}

void resuelveCaso() {

    int M, G;
    cin >> M >> G;
    vector<int> agua_dia(M);
    for (int& i : agua_dia)
        cin >> i;

    int sol = resolver(agua_dia, 0, M - 1, G, M);
    if (sol == -1)
        cout << "SIN RACIONAMIENTO\n";
    else
        cout << sol << "\n";
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
