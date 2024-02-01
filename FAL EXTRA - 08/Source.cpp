
/*@ <authors>
 *
 * Alejandro Vida Ramírez de Arellano F99
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


/*
            { c1                si n == 2
    T(n) =  {                                       Aplicando el teorema de la division a = 2, b = 2, k = 0 como a > b^k entonces el coste es de la forma O(n^log b a) = O(n)
            { 2T(n/2) + c2 si   si n > 2

*/


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Jugador {
    string nombre;
    int nCanicas;
};

Jugador resolver(const vector<Jugador>& v, int ini, int fin) {
    if (ini + 1 == fin) {
        bool ganaIzq = v[ini].nCanicas >= v[fin].nCanicas;
        return { ganaIzq ? v[ini].nombre : v[fin].nombre, ganaIzq ? v[ini].nCanicas + (v[fin].nCanicas / 2) : v[fin].nCanicas + (v[ini].nCanicas / 2) };
    }
    else {
        int mit = (ini + fin) / 2;
        Jugador izq = resolver(v, ini, mit);
        Jugador der = resolver(v, mit + 1, fin);

        bool ganaIzq = izq.nCanicas >= der.nCanicas;
        return { ganaIzq ? izq.nombre : der.nombre, ganaIzq ? izq.nCanicas + (der.nCanicas / 2) : der.nCanicas + (izq.nCanicas / 2) };
    }
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<Jugador> jugadores(n);
    for (int i = 0; i < n; i++)
    {
        cin >> jugadores[i].nombre >> jugadores[i].nCanicas;
    }

    Jugador j = resolver(jugadores, 0, n - 1);

    cout << j.nombre << " " << j.nCanicas << "\n";

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
