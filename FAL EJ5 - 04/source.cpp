
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

void generarVariacionesSinRepeticion(vector<char>& letras, int n, vector<bool>& usadas, string& actual) {
    if (n == 0) {
        cout << actual << endl;
        return;
    }

    for (int i = 0; i < letras.size(); i++)
    {
        if (!usadas[i]) {
            usadas[i] = true;
            actual.push_back(letras[i]);
            generarVariacionesSinRepeticion(letras, n - 1, usadas, actual);
            actual.pop_back();
            usadas[i] = false;

        }
    }
}


bool resuelveCaso() {

    // leer los datos de la entrada
    int n, m;
    cin >> m >> n;

    if (!std::cin)  // fin de la entrada
        return false;
    vector<char> letras;
    vector<bool> usadas(m, false);
    for (int i = 0; i < m; i++)
    {
        letras.push_back('a' + i);
    }
    string actual = "";
    generarVariacionesSinRepeticion(letras, n,usadas, actual);

    cout << endl;

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
