
/*@ <authors>
 *
 * Alejandro Vida Ram�rez de Arellano F99
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

int resolver(const vector<int>& v, int ini, int fin, int primer) {
    if (ini == fin) {
        return primer;
    }
    else if (ini + 1 == fin)
        return (v[ini] == primer + ini ? v[ini] + 1 : primer + ini);
    else {
        int m = (ini + fin - 1) / 2;
        if (primer + ini == v[ini] && primer + m == v[m])
            return resolver(v, m + 1, fin, primer);
        else
            return resolver(v, ini, m + 1, primer);
    }
}

void resuelveCaso() {

    int nValores, primer;
    cin >> nValores >> primer;
    vector<int>v(nValores);
    for (int& i : v)
        cin >> i;
    cout << resolver(v, 0, nValores, primer) << endl;
    
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
