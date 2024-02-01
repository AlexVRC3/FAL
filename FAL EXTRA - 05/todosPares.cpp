
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

// todosPares(v,p,q) dev bool b: {b = Pt k: p <= k < q: v[k] % 2 == 0}
// Coste O(N) ya que recorremos el vector entero una unica vez accediendo a cada elemento una unica vez.

// P = { n >= 0 /\ Pt i: 0 <= i < n: INT_MIN <= v[i] <= INT_MAX}
int resolver(const vector<int>& v, const int n) {
    int nSeg = 0;
    int nPares = 0;
    for (int i = 0; i < n; i++) // Cota n - i que decrece en cada iteracion y no toma valores negativos y asegura la terminacion del bucle
    {
        if (v[i] % 2 == 0) {    // I = { 0 <= i <= n /\ nSeg = #(p,q) : 0 <= p <= q < n: todosPares(v,p,q) /\ q - p >= 1 /\ 
                                // nPares = #c: Pt k,z: 0 <= k <= c <= z /\ z - k >= 1 /\ todosPares(v,k,z) /\ v[c] % 2 == 0 
            nPares++;
            nSeg += nPares;
        }
        else {
            nPares = 0;
        }
    }
    return nSeg;
}

// Q = { #(p,q) : 0 <= p <= q < n: todosPares(v,p,q) /\ q - p >= 1}

void resuelveCaso() {

    int n;
    cin >> n;
    vector<int>v(n);
    for (int& i : v)
        cin >> i;

    cout << resolver(v,n) << "\n";
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
