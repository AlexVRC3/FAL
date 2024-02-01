
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
               { k1 si n = 0
        T(n) = {                        por lo tanto si a = 1 y b = 2 y k = 0 eso nos deja con que b^k = 1 que nos deja con que a y b^k son iguales y por tanto T(n) pertenece a O(log n)
               { T(n/2) + k2 n > 0

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool busqueda_rotada(const vector<int>& v, int ini, int fin, int x) {
    if (ini > fin) {
        return false;
    }

    int mitad = ini + (fin - ini) / 2;

    if (v[mitad] == x) {
        return true;
    }

    // El subvector [ini,mitad] esta ordenado
    if (v[ini] <= v[mitad]) {

        if (v[ini] <= x && x < v[mitad])
            return busqueda_rotada(v, ini, mitad - 1, x);
        else
            return busqueda_rotada(v, mitad + 1, fin, x);
    }
    // El subvector [mitad, fin] esta ordenado
    else {
        if (v[mitad] < x && x <= v[fin]) 
            return busqueda_rotada(v, mitad + 1, fin, x);
        else
            return busqueda_rotada(v, ini, mitad - 1, x);
    }
}


bool resuelveCaso() {
    int N, x;
    // leer los datos de la entrada
    cin >> N >> x;

    if(N == -1)
        return false;
    vector<int> datos(N);
    for (int i = 0; i < N; i++)
    {
        cin >> datos[i];
    }
    bool encontrado = busqueda_rotada(datos, 0, datos.size() - 1, x);
    if (encontrado)
        cout << "SI" << endl;
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
