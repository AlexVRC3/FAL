
/*@ <authors>
 *
 * Alejandro Vida Ramírez de Arellano F99
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

using matriz = vector<vector<int>>;

int combinatorio(int a, int b, matriz& mat) {
    if (b == 0 || a == b)
        return 1;
    if (mat[a][b] != -1)
        return mat[a][b];
    else {
        int resultado = combinatorio(a - 1, b - 1, mat) + combinatorio(a - 1, b, mat);
        mat[a][b] = resultado;
        return resultado;
    }
}

bool resuelveCaso() {

    int a, b;
    cin >> a >> b;

    if (!std::cin)  // fin de la entrada
        return false;

    matriz mat(a + 1, vector<int>(b + 1, -1));

    cout << combinatorio(a, b, mat) << "\n";

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
