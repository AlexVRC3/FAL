
/*@ <authors>
 *
 * Alejandro Vida Ramírez de Arellano TAIS71
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

// El coste del algoritmo es del orden de O(N) porque recorremos todos los valores del vector de ventas una vez.

// P = {anyoIni >= 1700 /\ anyoFin <= 100.000 /\ Pt i: 0 <= i < anyoFin - anyoIni + 1: -2^31 <= v[i] <= 2^31 }
vector<int> resolver(const vector<int>& v, const int tam, const int anyoIni) {
    int max = v[0];
    vector<int> sol;
    for (int i = 1; i < tam; i++) // Funcion de cota: tam - i que decrece en cada iteración y asegura la terminación del bucle
    {   
        // I = { 1 <= i <= tam /\ max = max j: 0 <= j < tam : v[j] /\ sol Pt k: (Pt l: 0 <= l < i < k : v[l] <= v[i]) : sol[k] = anyoIni + i }
        if (v[i] > max) {
            max = v[i];
            sol.push_back(anyoIni + i);
        }
    }
    return sol;
}
// Q = { sol Pt k: (Pt l: 0 <= l < i < k : v[l] <= v[i]) : sol[k] = anyoIni + i }

void resuelveCaso() {
    int anyoIni, anyoFin;
    cin >> anyoIni >> anyoFin;
    int tam = anyoFin - anyoIni + 1;
    vector<int> ventas(tam);
    for (int i = 0; i < tam; i++)
    {
        cin >> ventas[i];
    }

    vector<int> sol = resolver(ventas, tam, anyoIni);
    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << " ";
    }
    cout << "\n";
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
