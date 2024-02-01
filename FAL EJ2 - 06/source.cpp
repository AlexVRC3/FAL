
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

//Predicado aux creciente(v) = Pt i, j: 0 <= i <= j < v.size(): v[i] <= v[j]
// Predicado aux minimo(v1,v2,i,j) = ret min i,j : 0 <= i < v1.size() /\ 0 <= j < v2.size() : v1[i] < v2[j] ? v1[i] : v2[j]

// P = { creciente(lista1) /\ creciente(lista2) /\ 0 <= n < 100000 /\ 0 <= m < 100000 /\ Pt i: 0 <= i < n : lista1[i] >= 0 /\ Pt j: 0 <= j < n : lista2[j] >= 0 }
vector<int> resolver(const vector<int>& lista1, const vector<int>& lista2, const int n, const int m) {
    vector<int> sol;
    int i = 0;
    int j = 0;
    while (i < n && j < m) { // Funcion de cota (n - i) + (m - j) decrece en cada iteracion y asegura la terminacion del bucle
        int precio1 = lista1[i];
        int precio2 = lista2[j];
        if (precio1 == precio2) {
            sol.push_back(precio1);
            sol.push_back(precio2);         // I = { 0 <= i <= n /\ 0 <= j <= m /\ Pt k: 0 <= k < i + j : sol[k] = minimo(v1,v2,i,j) /\ creciente(sol)
            i++;    
            j++;
        }
        else if (precio1 < precio2) {
            sol.push_back(precio1);
            i++;
        }
        else {
            sol.push_back(precio2);
            j++;
        }
    }
    while (i < n) { // Cota n - i
        sol.push_back(lista1[i]);
        i++;
    }

    while (j < m) { // Cota m - j
        sol.push_back(lista2[j]);
        j++;
    }
    return sol;
}

// Q = { Pt k: 0 <= k < i + j : sol[k] = minimo(v1,v2,i,j) /\ creciente(sol) }

void resuelveCaso() {

    int n, m;
    cin >> n >> m;
    vector<int> precios1(n);
    vector<int> precios2(m);
    for (int i = 0; i < n; i++)
    {
        cin >> precios1[i];
    }
    for (int j = 0; j < m; j++)
    {
        cin >> precios2[j];
    }

    vector<int> sol = resolver(precios1, precios2,n,m);
    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << " ";
    }
    cout << "\n";
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
