
/*@ <authors>
 *
 * Alejandro Vida Ram�rez de Arellano F99
 *
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>


struct tSol {
    bool hiper;
    int min;
    int cuentaMin;
};

tSol hiperminimalista(const vector<int>& v, int ini, int fin) {
    if (ini > fin) {
        return { true, INT_MAX, 0 }; // Caso base: secuencia vac�a
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

        bool cond = (cuentaMin == 1); // El m�nimo debe aparecer exactamente una vez
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

    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
