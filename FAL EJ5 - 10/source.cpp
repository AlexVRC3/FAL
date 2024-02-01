
/*@ <authors>
 *
 * Alejandro Vida Ramírez de Arellano F99
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

using matriz = vector<vector<int>>;

using marcador = vector<bool>;


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool es_solucion(const int n, const int k) {
    return k == n;
}

bool es_completable(const int n, const int k) {
    return k < n - 1;
}

bool puede_circular(const int anchura_carro, const int anchura_camino , const bool marca_camino, const bool marca_carro) {
    return anchura_camino >= anchura_carro && !marca_camino && !marca_carro;
}

bool es_prometedora(const int calidadActual, const int calidadEstimada, const int maxCalidad) {
    return calidadActual + calidadEstimada > maxCalidad;
}

void quitanieves(const int n, const int m, const int k, const int est[], vector<int>& sol, const matriz& calidades, const vector<int>& anchuras_carros, const vector<int>& anchuras_caminos, marcador& caminos, marcador& carros, int& calidadActual, int& maxCalidad) {

    if (es_solucion(n, k)) {
        if (calidadActual > maxCalidad)
            maxCalidad = calidadActual;
    }
    else {
        for (int i = 0; i < m; i++)
        {
            if (puede_circular(anchuras_carros[k], anchuras_caminos[i], caminos[i], carros[k])) {
                sol[k] = i; // Asignamos el camino i a la 
                calidadActual += calidades[k][i];
                carros[k] = true;
                caminos[i] = true;
               
                if (es_prometedora(calidadActual,est[k],maxCalidad)) {
                    
                    quitanieves(n, m, k + 1, est,sol, calidades, anchuras_carros, anchuras_caminos, caminos, carros, calidadActual, maxCalidad);
                    
                }
                carros[k] = false;
                caminos[i] = false;
                calidadActual -= calidades[k][i];
            }
        }
        quitanieves(n, m, k + 1, est, sol, calidades, anchuras_carros, anchuras_caminos, caminos, carros, calidadActual, maxCalidad);
    }
    
}

void resuelveCaso() {

    // leer los datos de la entrada
    int n, m;
    cin >> n >> m;

    vector<int> anchuras_carros(n);
    vector<int> anchuras_caminos(m);
    matriz calidades(n, vector<int>(m));
    vector<int> mejores_calidades(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> anchuras_carros[i];
    }
    for (int j = 0; j < m; j++)
    {
        cin >> anchuras_caminos[j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> calidades[i][j];
        }
    }

    //Estimaciones para la poda:
     int maxCalidades[500];
     int max = 0;
     for (int i = 0; i < n; i++) {
         max = calidades[i][0];
         for (int j = 1; j < m; j++) {
             if (calidades[i][j] > max) 
                 max = calidades[i][j];
            
        }
         maxCalidades[i] = max;
     }
    
     int est[500];
     int suma = maxCalidades[n - 1];
     est[n - 1] = suma;
     for (int i = n - 2; i >= 0; i--) {
         suma += maxCalidades[i];
         est[i] = suma;
    }
        
  

    marcador carros(n, false);
    marcador caminos(m, false);
    vector<int> sol(n, -1);
    int calidadActual = 0;
    int maxCalidad = -1;
    
    quitanieves(n, m, 0,est, sol,calidades, anchuras_carros, anchuras_caminos, caminos, carros, calidadActual, maxCalidad);
    cout << maxCalidad << endl;

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
