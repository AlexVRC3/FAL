
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
            { c1                si n == 2
    T(n) =  {                                       Aplicando el teorema de la division a = 1, b = 2, k = 0 como a == b^k entonces el coste es de la forma O(n^log b a) = O(log n)
            { T(n/2) + c2 si   si n > 2

*/


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int resolver(const vector<int>&v, int ini, int fin, int M, int G) {
    const int n = fin - ini;
    if (n <= 2) {
        return n == 0 ? -1 : ini;
    }
    else {
        int mit = (ini + fin) / 2;
        int aguaNecesaria = (M - mit) * G;
         if (v[mit] < aguaNecesaria)
            return resolver(v, ini, mit, M, G);
        else
            return resolver(v, mit, fin, M, G);
    }
}


void resuelveCaso() {

    int M, G;
    cin >> M >> G;
    vector<int> estimaciones(M);
    for (int i = 0; i < M; i++)
    {
        cin >> estimaciones[i];
    }
    int sol = resolver(estimaciones, 0, M , M, G);

    if (sol == -1) {
        cout << "SIN RACIONAMIENTO\n";
    }
    else {
        cout << sol << "\n";
    }

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