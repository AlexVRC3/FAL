
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

El espacio de soluciones es un arbol de profundidad n (numero de artistas) y de profundidad m(numero de momentos) que en este caso siempre valen lo mismo n y m. Por cada nivel se elige
que artista será elegido para actuar en ese momento teniendo en cuenta los vetos y maximizando las donaciones obtenidas. Se utiliza un marcador de asignados para saber si ese momento ya ha
sido rellenado con la actuacion de un artista. El vector sol nos permite tener un vector de tamaño m en el que se almacena que artista ha tocado en cada uno de los momentos y de esta forma
podremos comprobar si cumple con los vetos. La poda consiste en estimar cual sera la mayor donacion posible en cada uno de los momentos y de esta manera con las soluciones parciales que 
tengamos podremos descartar las ramas del arbol que no mejoren la solucion actual obtenida.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

using matriz = vector<vector<int>>;

void concierto_rock(const int n, const int k,  vector<int>& sol, const matriz& donaciones, vector<bool>& asignados, const matriz& vetos, bool& haySol, int& donAct, int& maxDon, const vector<int> &max_donaciones) {
    for (int m = 0; m < n; m++)
    {
        sol[k] = m; // Asignamos el artista i al momento k
        if (!asignados[sol[k]] && (k == 0 || vetos[sol[k]][sol[k - 1]] == 1)) { // Si es valida
            donAct += donaciones[m][k];
            if (k == n - 1 && donAct > maxDon) {
                maxDon = donAct;
                haySol = true;
            }
            else if (k < n - 1 && donAct + max_donaciones[k + 1] > maxDon) {
                asignados[m] = true;
                concierto_rock(n, k + 1, sol, donaciones, asignados, vetos, haySol, donAct, maxDon, max_donaciones);
                asignados[m] = false;
            }
            donAct -= donaciones[m][k];
        }
        
    }
}

void resuelveCaso() {

    int n;
    cin >> n;
    matriz donaciones(n, vector<int>(n));
    matriz vetos(n, vector<int>(n));
    vector<int> max_donaciones(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> donaciones[i][j];
            if (max_donaciones[j] < donaciones[i][j]) { // Poda
                max_donaciones[j] = donaciones[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> vetos[i][j];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        max_donaciones[i] += max_donaciones[i + 1];
    }
    int donAct = 0;
    int maxDon = 0;

    bool haySol = false;
    vector<bool> asignados(n, false);
    vector<int> sol(n);
    concierto_rock(n, 0, sol, donaciones,asignados, vetos, haySol, donAct, maxDon, max_donaciones);
    if (haySol)
        cout << maxDon << "\n";
    else
        cout << "NEGOCIA CON LOS ARTISTAS\n";

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
