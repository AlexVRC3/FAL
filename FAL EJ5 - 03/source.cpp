
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


void generarVariacionesConRepeticion(vector<char>& letras, int n, string &actual) {
    if (n == 0) {
        cout << actual << endl;
        return;
    }

    for (char letra : letras) {
        actual.push_back(letra);
        generarVariacionesConRepeticion(letras, n - 1, actual);
        actual.pop_back();
    }
}


bool resuelveCaso() {

    // leer los datos de la entrada
    int n, m;
    cin >> m >> n;

    if (!std::cin)  // fin de la entrada
        return false;
    vector<char> letras;
    vector<bool> usado(m, false);
    for (int i = 0; i < m; i++)
    {
        letras.push_back('a' + i);
    }
    string actual = "";
    generarVariacionesConRepeticion(letras, n, actual);

    cout << endl;

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
