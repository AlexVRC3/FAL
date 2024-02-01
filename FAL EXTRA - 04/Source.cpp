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
    int ini;
    int fin;
};

// Predicado aux decreciente(v,i,j) = Pt k,z: i <= k < z <= j : v[k] <= v[z]

// P = { 0 <= n <= 1000 /\ Pt i : 0 <= i < n : v[i] > 0 }

tSol resolver(const vector<int>& v) {
    tSol sol{ 0,0 };
    int ini = 0;
    int fin = 0;
    int prev = v[0];
    int n = v.size();
    for (int i = 1; i < n; i++) // Cota n - i
    {
        if (v[i] > prev) { // Si ya no es interesante la secuencia
            if (fin - ini  > sol.fin - sol.ini ) {
                sol.ini = ini;
                sol.fin = fin;  // I = { 1 <= i <= v.size() /\ prev = Pt j: 0 <= j < n : v[j] /\ 0 <= sol.ini <= sol.fin < n /\ decreciente(v,sol.ini,sol.fin) }
            }
            ini = i;
            fin = i;
        }
        else {
            fin++;
        }
        prev = v[i];
    }
    if (fin - ini  > sol.fin - sol.ini ) {
        sol.ini = ini;
        sol.fin = fin;
    }
    return sol;
}

// Q {max (q,p) : 0 <= q < p < n /\ decreciente(v,q,p) : q - p + 1}

void resuelveCaso() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& i : v)
        cin >> i;
    if (v.size() != 0) {
        tSol sol = resolver(v);
        cout << sol.fin - sol.ini + 1 << endl;
    }
    else
        cout << 0 << endl;

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
