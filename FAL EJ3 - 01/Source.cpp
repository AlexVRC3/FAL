
/*@ <authors>
 *
 * Alejandro Vida Ramírez de Arellano F99
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
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

int sumaDigitos(const int n) {
    if (n < 10) {
        return n;
    }
    else {
        return sumaDigitos(n / 10) + n % 10;
    }
}

int sumaDigitosFinal(const int n, int acum) {
    if (n < 10) {
        return acum + n;
    }
    else {
        acum += n % 10;
        return sumaDigitosFinal(n / 10, acum);
    }
}

//void resuelveCaso() {
//
//    int nElems, num;
//    cin >> nElems >> num;
//    vector<int> numeros(nElems);
//    int k = sumaDigitos(num);
//    int aux;
//    for (int i = 0; i < nElems; i++)
//    {
//        cin >> aux;
//        if (sumaDigitos(aux) == k)
//            cout << aux << " ";
//    }
//    cout << "\n";
//}

void resuelveCaso() {

    int nElems, num;
    cin >> nElems >> num;
    vector<int> numeros(nElems);
    int acum = 0;
    int k = sumaDigitosFinal(num,acum);
    int aux;
    for (int i = 0; i < nElems; i++)
    {
        acum = 0;
        cin >> aux;
        if (sumaDigitosFinal(aux,acum) == k)
            cout << aux << " ";
    }
    cout << "\n";
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
