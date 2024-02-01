
/*@ <authors>
 *
 * Alejandro Vida Ramírez de Arellano TAIS71
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

int resolver(const vector<int>& gastos, int ini, int fin, const int P, const int a, const int n) {
    if (ini == fin) {
        int val = a * (n - ini) + gastos[ini];
        if (P >= val) return -1;
        else return ini;
    }

    int mitad = (ini + fin) / 2;
    int ahorroPend = a * (n - mitad); 
    int gasto = gastos[mitad]; 

    int presupuestoRestante = P - gasto - ahorroPend;

    if (presupuestoRestante < 0) {
        return resolver(gastos, ini, mitad, P, a, n);
    }
    else {
        return resolver(gastos, mitad + 1 , fin, P, a, n);
        
    }
    
}

void resuelveCaso() {

    int P, a, n;
    cin >> P >> a >> n;
    vector<int> gastos(n);
    for (int& i : gastos)
        cin >> i;

    int sol = resolver(gastos, 0, n - 1, P, a , n);
    if (sol == -1)
        cout << "NO NECESARIO" << endl;
    else
        cout << sol << endl;
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
