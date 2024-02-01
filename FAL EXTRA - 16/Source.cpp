
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

    Elegimos para cada equipo que proyecto le asignamos. El espacio de busqueda es un arbol de profundidad m(numero de equipos de trabajo) y anchura n(numero de proyectos).
    Los marcadores utilizados son: restantes, sueldoAct, equipos y personas que estan explicados en su inicializacion en resuelveCaso. Para la poda calculamos el salario minimo
    y mantenemos una cuenta de las personas totales que quedan por asignar por proyecto. En caso de que el valor de la solucion parcial + el valor de la poda que seria repartir a todos
    los restantes el salario minimo sea menor que la mejor solucion obtenida hasta el momento, nos interesa seguir. En cualquier otro caso no.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
using marcador = vector<bool>;

int poda(const int restantes, const int min) {
    return restantes * min;
}
// Comprobamos que al añadir las personas del equipo k al proyecto i estemos dentro del limite
bool es_compatible(const int k, const int i, const vector<int>& G, const vector<int>& E, const vector<int>& personas) {
    return personas[i] + E[k] <= G[i];
}

void consultoria_informatica(const int n, const int m, const int k, const vector<int>& E, const vector<int>& L, const vector<int>& G,
    const vector<int>& S, int& sueldoAct, int& minSueldo, int& restantes, int& proyectos, const int min, vector<int> &personas) {

    for (int p = 0; p < n; p++) // Se prueba a asignar el proyecto i al equipo k
    {
        sueldoAct += E[k] * S[p]; // Se suman los sueldos de los integrantes del equipo
        restantes -= E[k]; 
        if (es_compatible(k,p,G,E,personas)) { 
            if (personas[p] < L[p] && (personas[p] + E[k] >= L[p])) { // hay un proyecto mas en el cual las condiciones estan satisfechas
                proyectos++;
            }
            personas[p] += E[k]; // Se añaden las personas al proyecto
            if (k == m - 1) {
                if (proyectos == n && sueldoAct < minSueldo) {
                    minSueldo = sueldoAct;
                }
            }
            else {
                if (poda(restantes, min) + sueldoAct < minSueldo) {
                    consultoria_informatica(n, m, k + 1, E, L, G, S, sueldoAct, minSueldo, restantes, proyectos, min, personas);
                }
            }
            personas[p] -= E[k];
            if (personas[p] < L[p] && (personas[p] + E[k] >= L[p])) // desmarcamos
                proyectos--;
        }
        sueldoAct -= E[k] * S[p]; // desmarcamos
        restantes += E[k];
    } 
}

void resuelveCaso() {

    int m, n;
    cin >> m >> n;
    vector<int> E(m);
    vector<int> L(n);
    vector<int> G(n);
    vector<int> S(n);
    int restantes = 0; // Para saber cuantas personas quedan por asignar (poda)
    int min = INT_MAX; // Para tener el sueldo minimo (poda)
    for (int i = 0; i < m; i++)
    {
        cin >> E[i];
        restantes += E[i];
    }
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

    int minSueldo = INT_MAX;
    int sueldoAct = 0;
    vector<int> personas(n, 0); // numero de personas por proyecto
    int proyectos = 0; // marcador para saber cuantos proyectos estan satisfechos
    consultoria_informatica(n, m, 0, E, L, G, S, sueldoAct, minSueldo, restantes, proyectos, min, personas);

    if (minSueldo == INT_MAX)
        cout << "NO\n";
    else 
        cout << minSueldo << "\n";

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
