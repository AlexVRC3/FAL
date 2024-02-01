
/*@ <authors>
 *
 * Alejandro Vida Ram�rez de Arellano TAIS71
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

int resolver(const vector<int>& a, const vector<int>& b, const int ini, const int fin) {
    if (ini == fin) {
        return b[ini];
    }

    int mitad = (ini + fin) / 2;

    if (a[mitad] == b[mitad]) {
        return resolver(a, b, mitad + 1, fin);
    }
    else
        return resolver(a, b, ini, mitad);
}


bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    cin >> n;

    if (n == -1)
        return false;
    vector<int> a(n);
    vector<int> b(n + 1);
    for (int& i : a)
        cin >> i;
    for (int& j : b)
        cin >> j;

    cout << resolver(a, b, 0, n) << endl;

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
