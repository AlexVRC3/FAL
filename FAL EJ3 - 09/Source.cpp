
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


/*
           { c1             si n < 10
    T(n) = {                                Aplicando el teorema de la division con a = 1, b = 10 y k = 0 obtenemos que a == b^k (1 == 10^0) y por ello el coste es O(n^k log n) = O(log n) siendo n el valor del numero de entrada
           { T(n/10) + c2   si n >= 10
*/

struct tSol {
    int codificado;
    int max;
    int pos;
};

tSol num_codificado(int n, int minDer) {
    if (n < 10) {
        return{ n * 3 + minDer, n , 1};
    }
    else {
        int ultDigito = n % 10;
        tSol izq = num_codificado(n / 10, min(minDer, ultDigito));
        int pos = izq.pos + 1;
        if (pos % 2 == 1) { // Si es pos impar

            izq.codificado += ultDigito * 3 + minDer;

        }
        else { // Si es pos par
            izq.codificado += ultDigito * 2 + izq.max;
        }
        return { izq.codificado, max(izq.max,ultDigito), pos };
    }
}
void resuelveCaso() {

    int n;
    cin >> n;
    cout << num_codificado(n,n%10).codificado << "\n";
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
