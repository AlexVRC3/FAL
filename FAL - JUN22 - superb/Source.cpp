
/*@ <authors>
 *
 * Alejandro Vida Ramírez de Arellano TAIS71
 *
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

struct tSol {
    bool superb;
    int max;
    int min;
};

tSol resolver(const vector<int>& v, const int ini, const int fin) {
    if (v.size() < 3)
        return { false, -1 };
    else if (ini == fin) {
        return{ true,v[ini] , v[ini]};
    }
    else {
        int mit = (ini + fin) / 2;
        tSol izq = resolver(v, ini, mit - 1);
        tSol der = resolver(v, mit + 1 , fin);

        bool superb = izq.superb && der.superb && abs(izq.max - der.min) == v[mit];
        return { superb, max({izq.max,der.max,v[mit]}), min({der.min, izq.min, v[mit]}) };
    }
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == -1)
        return false;
    vector<int> v(n);
    for (int& i : v)
        cin >> i;

    tSol sol = resolver(v, 0, n - 1);
    if (sol.superb)
        cout << "SUPERB\n";
    else
        cout << "NO SUPERB\n";
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
