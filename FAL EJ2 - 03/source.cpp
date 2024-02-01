
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
    int ganancia;
    int ini;
    int fin;
};

// P = { s >= 0 /\ 0 <= N <= 10^8 /\ Pt i: 0 <= i < N: INT_MIN <= v[i] <= INT_MAX }

// Predicado aux suma(v,i,j) = sum k: i <= k <= j : v[k]

tSol resolver(const vector<int> v) {
    int sumaAct = 0;
    tSol sol = { 0,0,0 };
    int ini = 0;
    for (int i = 0; i < v.size(); i++) // Función de cota: v.size() - i que decrece en cada iteración y asegura la terminación del bucle
    {
        // I = { 0 <= i <= v.size() /\ ganancia = max i,j : 0 <= i <= j < N : suma(v,i,j) /\ 0 <= ini <= fin < i /\ ganancia = suma(v, ini, fin) /\ sumaAct = suma(v,ini,i)
        sumaAct += v[i];
        if (sumaAct < 0) {
            sumaAct = 0;
            ini = i + 1;
        }
        else {
            if (sumaAct > sol.ganancia) {
                sol.ganancia = sumaAct;
                sol.fin = i;
                sol.ini = ini;
            }
        }
    }
    return sol;
}

// Q = { ganancia = max i,j : 0 <= i <= j < N : suma(v,i,j) /\ 0 <= ini <= fin < i /\ ganancia = suma(v, ini, fin) }

void resuelveCaso() {

    int N, S;
    cin >> N >> S;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    tSol sol = resolver(v);
    if (sol.ganancia >= S)
        cout << sol.ganancia << " " << sol.ini << " " << sol.fin << endl;
    else
        cout << "NO COMPENSA" << endl;
    
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
