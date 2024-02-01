
/*@ <authors>
 *
 * Alejandro Vida Ram�rez de Arellano F99
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

int resolver(const vector<int>& v) {
    int ceroIzq = 0, unoIzq = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0)
            ceroIzq++;
        else if (v[i] == 1)
            unoIzq++;
    }

    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (ceroIzq == unoIzq)
            return i;
        
        if (v[i] == 0)
            ceroIzq--;
        else if (v[i] == 1)
            unoIzq--;
    }

    return -1; 
}

void resuelveCaso() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& i : v)
        cin >> i;

    cout << resolver(v) << endl;
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
