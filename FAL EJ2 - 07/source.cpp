
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

// P = { 0 < ptMax <= 20000 /\ 1 <= N <= 200000 }

// Predicado auxiliar veces(v,k) = #j: 0 <= j < v.size() : v[j] = k

vector<int> resolver(const vector<int>& valores, const int ptMax) {
    int N = valores.size();
    vector<int> sol;
    vector<int> veces(ptMax + 1, 0);
    int maxVeces = 0;
    for (int i = 0; i < N; i++) // Cota: N - i que decrece en cada iteracion y asegura que el bucle termina
    {
        int val = valores[i];
        veces[val]++;                     // I = { 0 <= i <= N /\ maxVeces = max j: 0 <= j < N: veces(valores,j) /\ Pt k: 0 <= k < ptMax + 1: veces[k] = veces(valores,k)}
        if (veces[val] > maxVeces) {
            maxVeces = veces[val];
        }
    }
    for (int j = ptMax; j > 0; j--) // Cota: i que decrece en cada iteracion y asegura que el bucle termina
    {
        if (veces[j] == maxVeces)
            sol.push_back(j);           // I = { 0 < j <= ptMax /\ Pt k: 0 <= k < sol.size(): sol[k] = j sii veces(valores,j) == maxVeces}
    }
    return sol;
}

// Q = {Pt k: 0 <= k < sol.size(): sol[k] = j sii veces(valores,j) == maxVeces}


bool resuelveCaso() {

    int nTiradas, ptMax;
    cin >> nTiradas >> ptMax;

    if (nTiradas == -1)
        return false;

    vector<int> valores(nTiradas);
    for (int i = 0; i < nTiradas; i++)
    {
        cin >> valores[i];
    }
    
    vector<int> sol = resolver(valores, ptMax);
    for (int i = 0; i < sol.size(); i++)
    {
        if (i == sol.size() - 1)
            cout << sol[i];
        else
            cout << sol[i] << " ";
    }
    cout << "\n";
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
