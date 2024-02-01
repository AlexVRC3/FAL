
/*@ <authors>
 *
 * Alejandro Vida Ramírez de Arellano F99
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>


// Coste O(n) ya que recorremos una vez cada elemento del vector
// todosConsecutivos(v,p,q) dev bool b = { b = Pt i,j: p <= i < j < q: abs(v[i] - v[j]) = 1
// P = { n >= 0 /\ Pt i: 0 <= i < n: v[i] € Z }
int resolver(const vector<int>& v, const int n) {
    int nSeg = 0;
    int cont = 0; // Contador para la longitud del segmento actual

    for (int i = 0; i < n - 1; ++i) { // Funcion de cota: n - i que decrece en cada iteracion y asegura que el bucle termina
        if (abs(v[i] - v[i + 1]) == 1) { // Si son consecutivos
            cont++;
            nSeg += cont; 
        }
        else {  // I = { 0 <= i <= n - 1 /\ nSeg = # i,j : 0 <= i < j < n /\ todosConsecutivos(v,i,j + 1) /\ j + 1 - i >= 2 /\ 0 <= cont < n}
            cont = 0; 
        }
    }

    return nSeg;
}
// Q = { nSeg = # i,j : 0 <= i < j < n /\ todosConsecutivos(v,i,j + 1) /\ j + 1 - i >= 2}

void resuelveCaso() {

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
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
