
/*@ <authors>
 *
 * Alejandro Vida Ramírez de Arellano TAIS71
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

void consultoria(const int n, const int m, const int k, vector<int> &sol, const vector<int> &E, const vector<int>& L, const vector<int>& G, const vector<int>& S, vector<int> &personas,
    int& sueldoAct, int&sueldoMin, int&proyectos) {
    for (int p = 0; p < n; p++)
    {
        sol[k] = p;
        sueldoAct += S[p] * E[k];
        if (personas[p] + E[k] <= G[p]) { // Asignamos al equipo k el proyecto p
            
            if (personas[p] < L[p] && (personas[p] + E[k] >=  L[p])) {
                proyectos++;
            }
            personas[p] += E[k];
            if (k == m - 1) {
                if (proyectos == n) {
                    if (sueldoAct < sueldoMin)
                        sueldoMin = sueldoAct;
                }
            }
            else if (k < m - 1) {
                consultoria(n, m, k + 1, sol, E, L, G, S, personas, sueldoAct, sueldoMin, proyectos);
            }
            personas[p] -= E[k];
            if (personas[p] < L[p] && (personas[p] + E[k] >= L[p]))
                proyectos--;
        }
        sueldoAct -= S[p] * E[k];
    }

}

void resuelveCaso() {

    int m, n;
    cin >> m >> n;
    vector<int> E(m);
    vector<int> L(n);
    vector<int> G(n);
    vector<int> S(n);
    for (int i = 0; i < m; i++)
    {
        cin >> E[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> L[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> G[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> S[i];
    }

    int sueldoAct = 0;
    int sueldoMin = INT_MAX;
    int proyectos = 0; // Numero de proyectos satisfechos
    vector<int> personas(n, 0); // vector para saber si el equipo esta asignado o no
    vector<int> sol(m);
    consultoria(n, m, 0, sol, E, L, G, S, personas, sueldoAct, sueldoMin, proyectos);
    if (sueldoMin != INT_MAX)
        cout << sueldoMin << endl;
    else cout << "NO" << endl;

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
