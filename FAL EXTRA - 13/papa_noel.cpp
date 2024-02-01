
/*@ <authors>
 *
 * Alejandro Vida Ram�rez de Arellano F99
 *
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
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

using matriz = vector<vector<int>>;


void papa_noel(const matriz& satisfacciones, vector<int> &sol, const int n, const int m, const int k, vector<bool> &asignados, int& satActual, int& maxSat, const vector<int>& estimaciones) {
    for (int j = 0; j < m; j++) 
    {
        if (!asignados[j]) {
            sol[k] = j; // Asignamos el juguete j al ni�o k
            satActual += satisfacciones[k][j];
            if (k == n - 1) {
                if (satActual > maxSat)
                    maxSat = satActual;
            }
            else if (k < n - 1 && satActual + estimaciones[k + 1] > maxSat) {
                asignados[j] = true;
                papa_noel(satisfacciones, sol, n, m, k + 1, asignados, satActual, maxSat, estimaciones);
                asignados[j] = false;
            }
            satActual -= satisfacciones[k][j];
        }
        
    }
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int n, m; // n es ni�os m es juguetes
    cin >> m >> n;
    if (!std::cin)  // fin de la entrada
        return false;

    matriz satisfacciones(n, vector<int>(m));
    vector<int> estimaciones(n,-1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> satisfacciones[i][j];
            if (satisfacciones[i][j] > estimaciones[i]) {
                estimaciones[i] = satisfacciones[i][j];
            }
            
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        estimaciones[i] += estimaciones[i + 1];
    }
    int satActual = 0;
    int maxSat = INT_MIN;
    vector<int> sol(n);
    vector<bool> asignados(m, false);
    papa_noel(satisfacciones, sol,n, m, 0, asignados, satActual, maxSat, estimaciones);
    cout << maxSat << endl;

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
