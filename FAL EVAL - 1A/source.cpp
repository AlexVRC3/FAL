
/*@ <authors>
 *
 * Alejandro Vida Ramírez de Arellano F99
 *
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


/*@ <answer>



 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

// P = { 0 <= v.size() < 10^5 /\ forall i : 0 <= i < v.size() : -1000 <= v[i] <= 1000}

bool resolver(const vector<int>& secuencia) {
    int n = secuencia.size();
    int sumaTotal = 0;

    for (int i = 0; i < n; i++) { // Funcion de cota: n - i que siempre es positiva y llega a cero cuando el bucle termina y disminuye en cada iteración
        sumaTotal += secuencia[i]; // I = {sumaTotal = sumatoria i: 0 <= i < n : secuencia[i]}
    }

    for (int i = 0; i < n; i++) { // Funcion de cota: n - i que siempre es positiva y llega a cero cuando el bucle termina y disminuye en cada iteración
        sumaTotal -= secuencia[i];
        if (sumaTotal == secuencia[i]) { // I = {sumaTotal = sumatoria i: 0 <= i < n : sumaTotal -= secuencia[i]}
            return true;
        }
    }

    return false;
}

// Q = { propiedad = Existe un k : 0 <= k < i tq secuencia[k] == sumaTotal}
bool resuelveCaso() {

    int n;
    cin >> n;
    if( n == 0)
        return false;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    if (resolver(v)) {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
