
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

                       { c1 si n == 1
                T(n) = {                            Como a = 2 y b = 2 y k = 0 el coste de esta recurrencia esta en O(N)
                       { 2T(n/2) + c2 si n > 1

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct sol {
    int l; // mas largo
    int lIzq; // primero
    int lDer; // ultimo
};

// función que resuelve el problema
sol resolver(const vector<int>& v, const int ini, const int fin) {
    if (ini == fin) {
        return { 1,1,1 };
    }
    else {
        int mitad = (ini + fin) / 2;
        sol iz = resolver(v, ini, mitad);
        sol dr = resolver(v, mitad + 1, fin);
        sol total;
        total.l = max(iz.l, dr.l);
        total.lIzq = iz.lIzq;
        total.lDer = dr.lDer;
        if (v[mitad] != v[mitad + 1]) {
            return total;
        }
        else {
            int central = iz.lDer + dr.lIzq;
            total.l = max(central, total.l);
            if (v[ini] == v[mitad]) {
                total.lIzq += dr.lIzq;
            }
            if (v[mitad + 1] == v[fin]) {
                total.lDer += iz.lDer;
            }
            return total;
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam, dato;
    cin >> tam;
    if (tam == 0)
        return false;

    vector<int>v;
    for (int i = 0; i < tam; i++) {
        cin >> dato;
        v.push_back(dato);
    }
    sol sol = resolver(v, 0, v.size() - 1);


    // escribir sol
    cout << sol.l << endl;

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
