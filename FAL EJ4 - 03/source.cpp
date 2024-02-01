
/*@ <authors>
 *
 * Alejandro Vida Ramírez de Arellano F99
 * 
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


/*@ <answer>
                   {    c1 si n < 2
            T(n) = {                                Como a = 2, b = 2 y k = 0 el coste del algoritmo sería del orden de O(n^log 2 2) = O(n)
                   {    2T(n/2) + c2 si n >= 2
 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool esSufDisperso(const vector<int>& v, int ini, int fin, int k) {
    if (fin == ini)
        return true;
    else if (fin - ini == 1) {
        return abs(v[fin] - v[ini]) >= k;
    }
    else {
        int mit = (fin + ini) / 2;
        bool izq = esSufDisperso(v, ini, mit, k);
        bool der = esSufDisperso(v, mit + 1, fin, k);

        return abs(v[ini] - v[fin]) >= k && izq && der;
    }
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int n, k;

    cin >> n >> k;

    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> datos(n);
    for (int i = 0; i < n; i++)
    {
        cin >> datos[i];
    }
    if (esSufDisperso(datos, 0, n - 1, k))
        cout << "SI" << endl;
    else
        cout << "NO" << endl;

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
