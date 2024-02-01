
/*@ <authors>
 *
 * Alejandro Vida Ram�rez de Arellano TAIS71
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
