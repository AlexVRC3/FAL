
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

Lo subo tambien haciendolo con la terminologia vista en clase para practicar de cara al examen

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>


struct Objeto {
    int coste;
    int superficie;
};

bool es_solucion(const int k, const int n) {
    return k == n - 1;
}

bool es_valida(const int gastoActual, const int presupuesto) {
    return gastoActual <= presupuesto;
}

bool es_mejor(const int supActual, const int maxSup) {
    return supActual > maxSup;
}

bool es_completable(const int k, const int n) {
    return k < n - 1;
}



void adornosNavidad(const int i, const int n, const int presupuesto, int& gastoActual, const vector<Objeto>& objetos, int& supActual, int& maxSuperficie) {


    // no cogemos el objeto
    if (es_solucion(i, n) && es_mejor(supActual, maxSuperficie)) {
        maxSuperficie = supActual;
    }
    else if (es_completable(i, n)) {
        adornosNavidad(i + 1, n, presupuesto, gastoActual, objetos, supActual, maxSuperficie);
    }

    // lo cogemos

    gastoActual += objetos[i].coste;
    supActual += objetos[i].superficie;
    if (es_valida(gastoActual, presupuesto)) {
        if (es_solucion(i, n) && es_mejor(supActual, maxSuperficie))
            maxSuperficie = supActual;
        else if (es_completable(i, n))
            adornosNavidad(i + 1, n, presupuesto, gastoActual, objetos, supActual, maxSuperficie);
    }
    gastoActual -= objetos[i].coste;
    supActual -= objetos[i].superficie;
}


bool resuelveCaso() {
    int n, presupuesto;
    cin >> n >> presupuesto;

    if (!std::cin)  // fin de la entrada
        return false;

    vector<Objeto> objetos(n);
    for (int i = 0; i < n; i++) {
        cin >> objetos[i].coste >> objetos[i].superficie;
    }

    int maxSuperficie = 0;
    int gastoActual = 0;
    int supActual = 0;

    adornosNavidad(0, n, presupuesto, gastoActual, objetos, supActual, maxSuperficie);

    cout << maxSuperficie << endl;
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
