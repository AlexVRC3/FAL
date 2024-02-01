
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

// Coste O(N) ya que recorremos el vector pasando por cada valor una unica vez

// P = {0 <= n <= 100000 /\ Pt i: 0 <= i < n : INT_MIN <= v[i] <= INT_MAX}

pair<bool, int> resolver(const vector<int>& v) {
    int suma = 0;
    int i = v.size() - 1;
    bool pastoso = false;
    while (i >= 0 && !pastoso) { // Cota n - i que decrece en cada iteracion y asegura la terminacion del bucle
        if (v[i] == suma)
            pastoso = true;
        else {
            suma += v[i];
            i--;
        }
           
        
    }
    
    return { pastoso,i };
}

// Q = { bool b = Existe i: 0 <= i < n: (sum j: i < j < n: v[j]) = v[i]} 

void resuelveCaso() {

    int n;
    cin >> n;
    vector<int>v (n);
    for (int& i : v)
        cin >> i;
    
    auto sol = resolver(v);
    if (!sol.first)
        cout << "No\n";
    else
        cout << "Si " << sol.second << "\n";
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
