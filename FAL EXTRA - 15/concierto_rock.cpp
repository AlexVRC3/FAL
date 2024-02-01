
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

using matriz = vector<vector<int>>;


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool es_valida(const vector<bool>& asignados, const int k, const matriz& vetos, const vector<int>& sol) {
    return !asignados[sol[k]] && (k == 0 || vetos[sol[k]][sol[k-1]] == 1);
}

void concierto_rock(const int n, const int k, vector<int>& sol, const matriz& donaciones, const matriz& vetos, vector<bool>& asignados, int& donAct, int& maxDon, const vector<int> &estimaciones) {
    for (int m = 0; m < n; m++)
    {
        sol[k] = m;  // Asigno el momento m al artista k
        if (es_valida(asignados,k,vetos,sol)) {
            donAct += donaciones[m][k];
            if (k == n - 1) {
                if (donAct > maxDon)
                    maxDon = donAct;
            }
            else if (k < n - 1 && donAct + estimaciones[k + 1] > maxDon) {
                asignados[m] = true;
                concierto_rock(n, k + 1, sol, donaciones, vetos, asignados, donAct, maxDon, estimaciones);
                asignados[m] = false;
            }
            donAct -= donaciones[m][k];
        }
    }
}

void resuelveCaso() {

    int n;
    cin >> n; // numero de artistas
    matriz donaciones(n, vector<int>(n));
    vector<int> estimaciones(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> donaciones[i][j];
            if (donaciones[i][j] > estimaciones[j])
                estimaciones[j] = donaciones[i][j];
        }
    }
    matriz vetos(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> vetos[i][j];
        }
    }
    vector<int> sol(n); // n momentos
    vector<bool> asignados(n); // artistas
    int donAct = 0;
    int maxDon = INT_MIN;
    for (int i = n - 2; i >= 0; i--)
    {
        estimaciones[i] += estimaciones[i + 1];
    }
    concierto_rock(n, 0, sol, donaciones, vetos, asignados, donAct, maxDon, estimaciones);
    if (maxDon != INT_MIN)
        cout << maxDon << endl;
    else
        cout << "NEGOCIA CON LOS ARTISTAS\n";

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
