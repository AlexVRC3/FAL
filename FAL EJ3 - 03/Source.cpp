
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
    int sumaIzq;
    bool interesante;
};


/*
            { c1               si n < 10
    T(n) =  {                                          Aplicando el teorema de la division a = 1, b = 10, k = 0 como a == b^k entonces el coste es de la forma O(n^k log n) = O(log n)
            { T(n/10) + c2 si   si n >= 10             Siendo n el valor del numero de la entrada

*/

tSol es_interesante(int n, int sumaDch) {
    if (n % 10 == 0) 
        return { -1,false };
    else if (n < 10)
        return { n,sumaDch % n == 0 };
    else {
        int ultDigito = n % 10;
        tSol sol = es_interesante(n / 10, sumaDch + ultDigito);
        bool interesante = sol.interesante && (sol.sumaIzq % ultDigito == 0) && (sumaDch % ultDigito == 0);
        return { sol.sumaIzq + ultDigito,interesante };
    }
}

void resuelveCaso() {
    int n;
    cin >> n;
    tSol sol = es_interesante(n,0);
    if (sol.interesante)
        cout << "SI\n";
    else
        cout << "NO\n";
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
