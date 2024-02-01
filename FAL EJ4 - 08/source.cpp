
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

                       { c1 si n == 1
                T(n) = {                            Como a = 2 y b = 2 y k = 0 el coste de esta recurrencia esta en O(N)
                       { 2T(n/2) + c2 si n > 1

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

struct tSol {
    bool caucasico;
    int nPares;
};

tSol caucasico(const vector<int>& v, int ini, int fin) {
    if (ini == fin)
        return { true, v[ini] % 2 == 0 ? 1 : 0 };
    else {
        int mit = (ini + fin) / 2;
        tSol izq = caucasico(v, ini, mit);
        tSol der = caucasico(v, mit + 1, fin);

        return { abs(izq.nPares - der.nPares) <= 2 && izq.caucasico && der.caucasico, izq.nPares + der.nPares };
    }
}


bool resuelveCaso() {

    int n;
    cin >> n;
    if(n == 0)
        return false;

    vector<int> datos(n);
    for (int i = 0; i < n; i++)
    {
        cin >> datos[i];
    }
    tSol sol = caucasico(datos, 0, n - 1);
    if (sol.caucasico)
        cout << "SI";
    else
        cout << "NO";
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
