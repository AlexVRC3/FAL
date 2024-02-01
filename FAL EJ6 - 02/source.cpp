
/*@ <authors>
 *
 * Alejandro Vida Ramírez de Arellano F99
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

// P = { c > 0 /\ 0 <= n <= 1000000 /\ Pt i: 0 <= i < n : v[i] > 0}

// Predicado auxiliar: suma(v,i,j) = sum k: i <= k < j: v[k] 

bool resolver(const vector<int>& v, int c) {
    int sumaAct = 0;
    int ini = 0;

    // I = { 0 <= ini <= i <= v.size() /\ sumaAct = suma(v,ini,i + 1) /\ b = Ex i,j: 0 <= i <= j : suma(v,i,j) == c}
    for (int i = 0; i < v.size(); i++) { // Cota v.size() - i
        sumaAct += v[i];
        while (sumaAct > c && ini <= i) { // Cota i - ini
            sumaAct -= v[ini];
            ini++;
        }
        if (sumaAct == c) {
            return true;
        }
    }
    return false;
}

// Q = { b = Ex i,j: 0 <= i <= j : suma(v,i,j) == c}


bool resuelveCaso() {
    int n, c;
    cin >> n;
    if (n == -1)
        return false;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cin >> c;

    if (resolver(v, c))
        cout << "SI";
    else
        cout << "NO";
    cout << endl;

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
