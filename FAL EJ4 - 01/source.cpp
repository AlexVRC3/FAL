
/*@ <authors>
 *
 * Alejandro Vida Ramírez de Arellano F99
 * 
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


/*@ <answer>
               { k1 si n = 0
        T(n) = {                        por lo tanto si a = 1 y b = 2 y k = 0 eso nos deja con que b^k = 1 que nos deja con que a y b^k son iguales y por tanto T(n) pertenece a O(log n)
               { T(n/2) + k2 n > 0

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct tSol {
    int posPrim;
    int posUlt;
    bool encontrado;
};

tSol busqueda_binaria(const vector<int>& v, int ini, int fin, int a) {
    tSol resultado = { -1, -1, false };

    while (ini <= fin) {
        int mitad = ini + (fin - ini) / 2;

        // Si el elemento está presente en el medio
        if (v[mitad] == a) {
            resultado.encontrado = true;
            resultado.posPrim = mitad;
            resultado.posUlt = mitad;

            // Buscar hacia la izquierda para encontrar el primer a
            int temp = busqueda_binaria(v, ini, mitad - 1, a).posPrim;
            if (temp != -1) {
                resultado.posPrim = temp;
            }

            // Buscar hacia la derecha para encontrar el último a
            temp = busqueda_binaria(v, mitad + 1, fin, a).posUlt;
            if (temp != -1) {
                resultado.posUlt = temp;
            }

            return resultado;
        }

        // Si el elemento es menor que el medio, buscar en la mitad izquierda
        if (v[mitad] > a) {
            fin = mitad - 1;
        }
        // Si el elemento es mayor que el medio, buscar en la mitad derecha
        else {
            ini = mitad + 1;
        }
    }

    return resultado;
}

bool resuelveCaso() {

    // leer los datos de la entrada

    int s, a;
    cin >> s >> a;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> sospechosos(s);
    int value;
    for (int i = 0; i < s; i++)
    {
        cin >> sospechosos[i];
    }
    
    tSol sol = busqueda_binaria(sospechosos, 0, sospechosos.size() - 1, a);

    if (sol.encontrado) {
        if (sol.posUlt == sol.posPrim)
            cout << sol.posPrim << endl;
        else
            cout << sol.posPrim << " " << sol.posUlt << endl;
    }
    else
        cout << "NO EXISTE" << endl;
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
