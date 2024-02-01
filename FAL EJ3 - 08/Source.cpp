
/*@ <authors>
 *
 * Alejandro Vida Ramírez de Arellano F99
 *
 *@ </authors> */

#include <iostream>
#include <fstream>

using namespace std;


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct tSol {
    int nDig;
    int mult;
};

/*
           { c1             si n < 10
    T(n) = {                                Aplicando el teorema de la division con a = 1, b = 10 y k = 0 obtenemos que a == b^k (1 == 10^0) y por ello el coste es O(n^k log n) = O(log n) siendo n el valor del numero de entrada
           { T(n/10) + c2   si n >= 10
*/

tSol digitos_multiplicativos(int n) {
    if (n < 10) {
        return { (n == 1) ? 1 : 0, n }; // Si el mas significativo es 1 es multiplicativo
    }
    else {
        tSol izq = digitos_multiplicativos(n / 10);
        int ultDigito = n % 10;
        int multiplicativo = izq.mult % 10 == ultDigito;
        return { izq.nDig + multiplicativo, izq.mult * ultDigito };
    }
}


void resuelveCaso() {

    int n;
    cin >> n;
    cout << digitos_multiplicativos(n).nDig << endl;
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
