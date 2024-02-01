
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

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>


struct tSol {
    bool hiper;
    int min;
    int cuentaMin;
};

tSol hiperminimalista(const vector<int>& v, int ini, int fin) {
    if (ini > fin) {
        return { true, INT_MAX, 0 }; // Caso base: secuencia vacía
    }
    if (ini == fin) {
        return { true, v[ini], 1 }; // Caso base: un solo elemento
    }
    else {
        int mit = (ini + fin) / 2;
        tSol izq = hiperminimalista(v, ini, mit - 1);
        tSol der = hiperminimalista(v, mit + 1, fin);

        if (!izq.hiper || !der.hiper) {
            return { false, 0, 0 }; // Si alguna subsecuencia no es hiperminimalista
        }

        int minimo = min({ izq.min, der.min, v[mit] });
        int cuentaMin = (izq.min == minimo ? izq.cuentaMin : 0) +
            (der.min == minimo ? der.cuentaMin : 0) +
            (v[mit] == minimo ? 1 : 0);

        bool cond = (cuentaMin == 1); // El mínimo debe aparecer exactamente una vez
        return { cond, minimo, cuentaMin };
    }
}

bool resuelveCaso() {

    int n;
    cin >> n;
    if (n == -1)
        return false;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    tSol sol = hiperminimalista(v,0,n - 1);
    if (sol.hiper)
        cout << "SI\n";
    else
        cout << "NO\n";

    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución

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
