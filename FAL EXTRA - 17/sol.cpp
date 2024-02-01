#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

struct tDatos {
    vector<int> mascarillasRequeridas;
    vector<int> stockMascarillas;
    vector<int> precioMascarillas;
};

// función que resuelve el problema
void resolver(const tDatos& datos, vector<int>& sol, vector<bool>& marcas, vector<int>& mascarillasFacultades, int& precioActual, int& precioMin, const int k, bool& exito, const vector<int>& estimacion) {
    if (k == datos.mascarillasRequeridas.size()) {
        if (precioActual < precioMin) {
            precioMin = precioActual;
            exito = true;
        }
    }
    else {
        for (int suministrador = 0; suministrador < datos.stockMascarillas.size(); suministrador++) {
            if (!marcas[suministrador] && mascarillasFacultades[k] > 0) { // Si el suministrador no ha suministrado a otro facultad y la facultad requiere de mascarillas
                sol[k] = suministrador;

                if (datos.stockMascarillas[suministrador] >= mascarillasFacultades[k]) { // si hay stock suficiente del suministrador para esa facultad
                    marcas[suministrador] = true;
                    precioActual += (mascarillasFacultades[k] * datos.precioMascarillas[suministrador]);

                    if (k == datos.mascarillasRequeridas.size() - 1) {
                        exito = true;
                        if (precioActual < precioMin) {
                            precioMin = precioActual;
                        }
                    }
                    else {
                        if (k < datos.mascarillasRequeridas.size() - 1 && precioActual + estimacion[k + 1] < precioMin) {
                            resolver(datos, sol, marcas, mascarillasFacultades, precioActual, precioMin, k + 1, exito, estimacion);
                        }
                    }
                    marcas[suministrador] = false;
                    precioActual -= (mascarillasFacultades[k] * datos.precioMascarillas[suministrador]);

                }
                else {
                    marcas[suministrador] = true;
                    precioActual += (datos.stockMascarillas[suministrador] * datos.precioMascarillas[suministrador]);
                    mascarillasFacultades[k] -= datos.stockMascarillas[suministrador];

                    resolver(datos, sol, marcas, mascarillasFacultades, precioActual, precioMin, k, exito, estimacion);

                    marcas[suministrador] = false;
                    precioActual -= (datos.stockMascarillas[suministrador] * datos.precioMascarillas[suministrador]);
                    mascarillasFacultades[k] += datos.stockMascarillas[suministrador];
                }
            }
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, m;
    cin >> n >> m;

    tDatos datos;
    datos.mascarillasRequeridas.resize(n);
    vector<int> mascarillasFacultades(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> datos.mascarillasRequeridas[i];
        mascarillasFacultades[i] = datos.mascarillasRequeridas[i];
    }

    datos.stockMascarillas.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> datos.stockMascarillas[i];
    }

    datos.precioMascarillas.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> datos.precioMascarillas[i];
    }

    vector<int> sol(n);
    vector<bool> marcas(m, false);

    int precioActual = 0;
    int precioMin = INT_MAX;
    bool exito = false;

    vector<int> estimacion(n);
    int min;
    for (int i = 0; i < n; i++) {
        estimacion[i] = datos.mascarillasRequeridas[i] * datos.precioMascarillas[0];
    }

    resolver(datos, sol, marcas, mascarillasFacultades, precioActual, precioMin, 0, exito, estimacion);
    // escribir sol
    if (exito) {
        cout << precioMin << endl;
    }
    else {
        cout << "NO" << endl;
    }

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}