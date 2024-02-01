
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;



// función que resuelve el problema
void resolver(const vector<vector<int>>& matriz, vector<int>& sol, vector<bool>& marcas, const int k, int& sumaActual, int& sumaMaxima, const int m, const int n, const vector<int>& maxSatisf) {
    if (k == n) {
        if (sumaActual > sumaMaxima) {
            sumaMaxima = sumaActual;
        }
    }
    else {
        resolver(matriz, sol, marcas, k + 1, sumaActual, sumaMaxima, m, n, maxSatisf);


        for (int juguete = 0; juguete < m; juguete++) {
            sol[k] = juguete;

            if (!marcas[juguete]) {
                sumaActual += matriz[k][juguete];
                marcas[juguete] = true;

                if (sumaActual + maxSatisf[k] > sumaMaxima) {
                    resolver(matriz, sol, marcas, k + 1, sumaActual, sumaMaxima, m, n, maxSatisf);
                }

                sumaActual -= matriz[k][juguete];
                marcas[juguete] = false;

            }
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int m, n;
    cin >> m >> n;
    if (!cin)
        return false;

    vector<vector<int>> matriz(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matriz[i][j];
        }
    }

    vector<bool> usados(m, false);

    vector<int> sol(n);

    int satisfActual = 0;

    int satisfMax = 0;

    for (int i = 0; i < n; i++) {
        satisfMax += matriz[i][i];
    }


    vector<int> maxSatisf(n);
    int max = 0;
    for (int i = 0; i < n; i++) {
        max = matriz[i][0];
        for (int j = 0; j < m; j++) {
            if (matriz[i][j] > max) {
                max = matriz[i][j];
            }
        }
        maxSatisf[i] = max;
    }

    for (int i = (int)maxSatisf.size() - 1; i > 0; i--) {
        maxSatisf[i - 1] += maxSatisf[i];
    }


    resolver(matriz, sol, usados, 0, satisfActual, satisfMax, m, n, maxSatisf);

    // escribir sol
    cout << satisfMax << endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}