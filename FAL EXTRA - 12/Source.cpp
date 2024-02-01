
/*@ <authors>
 *
 * Alejandro Vida Ramírez de Arellano F99
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
using namespace std;

/*
            { c1                si n < 10
    T(n) =  {                                       Aplicando el teorema de la division a = 1, b = 10, k = 0 como a == b^k entonces el coste es de la forma O(n^k log n) = O(log n) siendo n el numero entero
            { T(n/10) + c2 si   si n >= 10

*/


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct tSol{
    bool sumdivisible;
    int sumaIzq;
    int tam;
};

tSol resolver(int n) {
    if (n < 10) {
        return { n % 1 == 0, n , 1};
    }
    else {
        int ultDigito = n % 10;
        tSol sol = resolver(n / 10);
        return{ ((sol.sumaIzq + ultDigito) % (sol.tam + 1) == 0) && sol.sumdivisible, sol.sumaIzq + ultDigito, sol.tam + 1 };
    }
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;
    tSol sol = resolver(n);
    
    if (sol.sumdivisible)
        cout << "SI\n";
    else
        cout << "NO\n";

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
