
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

struct tSol {
    int nPartidos;
    bool seJuega;
    int ronda;
};

tSol resolver(const vector<string>& v, int ini, int fin, int ronda) {
    if (ini + 1 == fin) {
        if (v[ini] == "NP" && v[fin] == "NP")
            return { 0,false, 1};
        else if (v[ini] == "NP" || v[fin] == "NP")
            return { 0, true, 1};
        else
            return { 1, true, 1 };
    }
    else {
        int mit = (ini + fin) / 2;
        tSol izq = resolver(v, ini, mit, ronda);
        tSol der = resolver(v, mit + 1, fin, ronda);
        if (izq.ronda == ronda) {
            return { izq.nPartidos + der.nPartidos, true, ronda };
        }
        bool seJuega = izq.seJuega && der.seJuega;
        return { izq.nPartidos + der.nPartidos + (seJuega ? 1 : 0), (izq.seJuega || der.seJuega) , izq.ronda + 1};
    }
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int n, r;
    cin >> n >> r;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<string> jugadores(n);
    for (int i = 0; i < n; i++)
    {
        cin >> jugadores[i];
    }

    tSol sol = resolver(jugadores, 0, n - 1, r);

    cout << sol.nPartidos << "\n";

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
