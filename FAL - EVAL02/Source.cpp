
/*@ <authors>
 *
 * Alejandro Vida Ramírez de Arellano F99
 *
 *@ </authors> */

#include <iostream>
#include <fstream>

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

/*
            { c1                si n < 10
    T(n) =  {                                       Aplicando el teorema de la division a = 1, b = 10, k = 0 como a == b^k entonces el coste es de la forma O(n^k log n) = O(log n)
            { T(n/10) + c2 si   si n >= 10

*/

int complementario(const int n) {
    if (n < 10) {
        return 9 - n;
    }
    else {
        return complementario(n / 10) * 10 +  (9 - n % 10);
    }
}

struct tSol {
    int num;
    int pot;
};

tSol inverso_comp(const int n) {
    if (n < 10) {
        return { 9 - n,1 };
    }
    else {
        tSol comp = inverso_comp(n / 10);
        int pot = comp.pot * 10;
        int num = comp.num + (9 - n % 10) * pot;
        return { num,pot };
    }
}


void resuelveCaso() {

    int num;
    cin >> num;
    int comp = complementario(num);
    tSol inv = inverso_comp(num);
    cout << comp << " " << inv.num << endl;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

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
