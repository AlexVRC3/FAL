
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

// noMas(v,i,j,l) = (# r : i <= r < j : v[r] % 2 == 1) <= l

// P = { l >= 0 /\ 0 <= k <= n  /\ Pt i: 0 <= i < k: v[i] % 2 == 0}
int resolver(const vector<int>& v, const int k, const int l, const int n) {
    if (k == 0)
        return n + 1;
    int numSeg = 1;
    int impares = 0;
    for (int i = k; i < n; i++) // Cota N - i
    {
        if (v[i] % 2 == 1)      // I = { k <= i <= n /\ (impares = # s: i - k < s <= i: v[s] % 2 == 1) /\ numSeg = # (p,q) : 0 <= p < q < n /\ q - p = k : noMas(v,p,q,l)
            impares++;
        if (v[i - k] % 2 == 1)
            impares--;
        if (impares <= l)
            numSeg++;
    }
    return numSeg;
}
// Q = {#p,q: 0 <= p < q < n /\ q - p = k : noMas(v,p,q,l)}

void resuelveCaso() {

    int n, k, l;
    cin >> n >> k >> l;
    vector<int> v(n);
    for (int& i : v) {
        cin >> i;
    }

    cout << resolver(v, k, l,n) << "\n";
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
