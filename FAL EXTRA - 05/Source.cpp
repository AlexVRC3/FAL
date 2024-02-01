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

// todosPares(v,p,q) = Pt k: p <= k < q : v[k] % 2 == 0

// P {n >= 0 /\ Pt i: 0 <= i < n: v[i] > 0}
int resolver(const vector<int>& v) {
    int n = v.size();
    int nSeg = 0;
    int cont = 0;
    for (int i = 0; i < n; i++) // Cota n - i
    {
        if (v[i] % 2 == 0) { // I = { 0 <= i <= n /\ nSeg = #(p,q) : 0 <= p < q < n: todosPares(v,p,q + 1) /\ cont = # c : 0 <= c < n : v[c] % 2 == 0 }
            cont++;
            nSeg += cont;
        }
        else {
            cont = 0;
        }
    }
    return nSeg;
}

// Q {#(p,q) : 0 <= p < q < n: todosPares(v,p,q + 1)}

void resuelveCaso() {

    int n;
    cin >> n;
    vector<int> v(n);
    for (int& i : v)
        cin >> i;
    cout << resolver(v) << "\n";
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
