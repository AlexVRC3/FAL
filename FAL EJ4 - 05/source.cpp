
/*@ <authors>
 *
 * Alejandro Vida Ramírez de Arellano F99
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



/*@ <answer>
                       { c1 si n == 1
                T(n) = {                            Como a = 1 y b = 2 y k = 0 el coste de esta recurrencia esta en O(log N)
                       { T(n/2) + c2 si n > 1
 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>


char encontrarPrisionero(const vector<char> &prisioneros,char p, char u, int ini, int fin) {
    if (ini == fin - 1) { // Solo un preso
        return prisioneros[ini] == p ? u : p;
    }
    else {
        int mitad = (ini + fin) / 2;
        char medio = (p + u) / 2;
        if (prisioneros[mitad] > medio)
            return encontrarPrisionero(prisioneros, p, medio, ini, mitad);
        else
            return encontrarPrisionero(prisioneros, medio, u, mitad, fin);
    }
}

char resolver(const vector<char>& prisioneros, char primero, char ultimo) {
    return encontrarPrisionero(prisioneros, primero, ultimo, 0, prisioneros.size());
}

void resuelveCaso() {

    // leer los datos de la entrada

    char ini, fin;

    cin >> ini >> fin;

    vector<char> prisioneros(fin - ini);
    for (int i = 0; i < fin - ini; i++)
    {
        cin >> prisioneros[i];
    }
    cout << resolver(prisioneros, ini, fin) << endl;
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
