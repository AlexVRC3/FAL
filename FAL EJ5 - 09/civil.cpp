
/*@ <authors>
 *
 * Alejandro Vida Ramírez de Arellano F99
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;


/*@ <answer>
 Para resolver el problema intentamos asignar una ciudad a cada patrulla o no asignarle ninguna. El espacio de soluciones es un arbol de profundidad m(numero de patrullas) y anchura
 n (numero de ciudades). Los marcadores utilizados estan explicados en la funcion resuelveCaso y en cuanto a la poda utilizamos dos variables int que guardan las personas totales
 que quedan por asignar y el menor salario posible. De esta manera si el valor de nuestra solucion parcial + suponer que podamos asignar el menor sueldo a los restantes es menor que
 la mejor solucion obtenida hasta el momento, nos interesa continuar. En otro caso realizamos la poda.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int poda(const int restantes, const int min) {
    return restantes * min;
}

void proteccion_civil(const int n, const int m, const int r, const int k, const vector<int>& L, const vector<int>& G, const vector<int>& S, const vector<int>& P
    , int &costeActual, int &costeMinimo, int& ciudades, vector<int> &personas, int& restantes, const int min) {
 
    for (int i = 0; i < n; i++) // Intentamos asignar a la patrulla k la ciudad i
    {
        costeActual += P[k] * S[i];
        restantes -= P[k];
        if (personas[i] + P[k] <= G[i]) { // Si no nos pasamos del limite de personas
        
            if (personas[i] < L[i] && (personas[i] + P[k] >= L[i])) { // Hay una ciudad mas satisfecha
                ciudades++;
            }
            personas[i] += P[k]; 
            if (k == m - 1) {
                if (ciudades == n) {
                    if (costeActual < costeMinimo)
                        costeMinimo = costeActual;
                }
            }
            else {
                if (poda(restantes, min) + costeActual < costeMinimo) {
                    proteccion_civil(n, m, r, k + 1, L, G, S, P, costeActual, costeMinimo, ciudades, personas, restantes, min);
                }
            }
            personas[i] -= P[k];
            if (personas[i] < L[i] && (personas[i] + P[k] >= L[i]))
                ciudades--;
        }
        costeActual -= P[k] * S[i];
        restantes += P[k];
    }
    // No se asigna a ninguna ciudad
    costeActual += P[k] * r;
    restantes -= P[k];
    if (k == m - 1) {
        if (ciudades == n) {
            if (costeActual < costeMinimo)
                costeMinimo = costeActual;
        }
    }
    else {
        if (poda(restantes, min) + costeActual < costeMinimo) {
            proteccion_civil(n, m, r, k + 1, L, G, S, P, costeActual, costeMinimo, ciudades, personas, restantes, min);
        }
    }
    costeActual -= P[k] * r;
    restantes += P[k];
}


void resuelveCaso() {

    int n, m , r;
    cin >> n >> m >> r;
    
    vector<int> L(n);
    vector<int> G(n);
    vector<int> S(n);
    vector<int> P(m);
    int min = r; // variable en la que guardamos el menor salario de todas las ciudades
    int restantes = 0; // numero de personas que quedan por asignar
    for (int i = 0; i < n; i++)
    {
        cin >> L[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> G[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> S[i];
        if (S[i] < min)
            min = S[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> P[i];
        restantes += P[i];
    }
   
    vector<int> personas(n, 0); // numero de personas asignadas por ciudad
    int ciudades = 0; // marcador para saber cuantas ciudades estan satisfechas
    int costeMinimo = INT_MAX;
    int costeActual = 0;
    proteccion_civil(n, m, r, 0, L, G, S, P, costeActual, costeMinimo, ciudades, personas, restantes, min);
    if (costeMinimo == INT_MAX)
        cout << "NO" << endl;
    else 
        cout << costeMinimo << endl;
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
