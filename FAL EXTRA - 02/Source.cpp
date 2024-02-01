
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

struct tSol {
    bool pastoso;
    int idx;
};

// P = { 0 <= n <= 100000 /\ Pt i: 0 <= i < n : INT_MIN <= v[i] <= INT_MAX }
// Predicado auxiliar: suma(v,i,j) = sum k: i <= k < j : v[k]
tSol resolver(const vector<int>& v, const int n) {
    tSol sol = { false,-1 };
    int sumaDer = 0;
    int i = n - 1;
    while (i >= 0 && !sol.pastoso) { // Cota N - i
        if (v[i] == sumaDer) {
            sol.pastoso = true; // I = { -1 <= i <= n - 1 /\ sol.pastoso = (Ex c: 0 <= c < n: v[c])  /\ Pt l : c < l < n : suma(v,l,n) = v[c] 
                                //    /\ sol.idx = max c : 0 <= c < n: v[c]  /\ Pt l : c < l < n : suma(v,l,n) = v[c] 
            sol.idx = i;
        }
        sumaDer += v[i];
        i--;
    }
    return sol;
}
// Q = { sol.pastoso = (Ex c: 0 <= c < n: v[c])  /\ Pt l : c < l < n : suma(v,l,n) = v[c] /\ sol.idx = max c : 0 <= c < n: v[c]  /\ Pt l : c < l < n : suma(v,l,n) = v[c] }

void resuelveCaso() {

    int n;
    cin >> n;
    vector<int> v(n);
    for (int& i : v)
        cin >> i;
    tSol sol = resolver(v, n);
    if (sol.pastoso)
        cout << "Si " << sol.idx << "\n";
    else
        cout << "No\n";
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
