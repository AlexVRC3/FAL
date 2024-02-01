#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

struct tDatos {
    vector<int> C;// mascarillas que necesita la facultad i
    vector<int> S; // stock de mascarillas que tiene el suministrador i
    vector<int> P; // precio de las mascarillas del suministrador i
};
/*
arbol de exploracion  = voy recorriendo todas las facultades y a cada facultad le asigno un suministrador


poda = miro a ver si el percio de la solucion actual + la estimacion de lo que falta es menor que el percio minimo
        tambien si



*/

bool comprobar(const vector<int>& mascarillasFacultades) {
    for (int i = 0; i < mascarillasFacultades.size(); i++) {
        if (mascarillasFacultades[i] > 0) {
            return false;
        }
    }
    return true;
}
// función que resuelve el problema
void resolver(const tDatos& datos, vector<int>& sol, vector<bool>& marcas, vector<int>& mascarillasFacultades, int& precioActual, int& precioMin, const int k, bool& exito, vector<int>& estimacion, int& facultades) {
    if (k == datos.S.size()) {
        if (precioActual < precioMin && comprobar(mascarillasFacultades)) { // si es menor de lo que ya hay
            precioMin = precioActual;
            exito = true;
        }
    }
    else {
        for (int facultad = 0; facultad < datos.C.size(); facultad++) {

            if (mascarillasFacultades[facultad] > 0) {
                sol[k] = facultad;
                int minimo = (min(mascarillasFacultades[facultad], datos.S[k]));
                precioActual += (minimo * datos.P[k]);
                mascarillasFacultades[facultad] -= (minimo);
                if (mascarillasFacultades[facultad] < 0)
                    facultades++;
                if (k == datos.S.size() - 1) {
                    if(facultades == datos.C.size())
                    if (precioActual < precioMin) { // si es menor de lo que ya hay
                        precioMin = precioActual;
                        exito = true;
                    }
                }
                else {
                    if (k < datos.S.size() - 1 && precioActual + (estimacion[facultad] - minimo) * datos.P[k + 1] < precioMin) { // podo si no llego a una solucion mejor
                        resolver(datos, sol, marcas, mascarillasFacultades, precioActual, precioMin, k + 1, exito, estimacion, facultades);
                    }
                }
                if (mascarillasFacultades[facultad] < 0)
                    facultades--;
                precioActual -= (minimo * datos.P[k]);
                mascarillasFacultades[facultad] += (minimo);
            }
        }

        resolver(datos, sol, marcas, mascarillasFacultades, precioActual, precioMin, k + 1, exito, estimacion,facultades); // no se asigna ese suministrador

    }


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, m;
    cin >> n >> m;

    tDatos datos;
    datos.C.resize(n);
    vector<int> mascarillasFacultades(n, 0);
    vector<int> estimacion(n);
    for (int i = 0; i < n; i++) {
        cin >> datos.C[i];
        mascarillasFacultades[i] = datos.C[i];
        estimacion[i] = datos.C[i];
    }

    datos.S.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> datos.S[i];
    }

    datos.P.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> datos.P[i];
    }

    vector<int> sol(m);
    vector<bool> marcas(m, false);

    int precioActual = 0;
    int precioMin = INT_MAX;
    bool exito = false;
    int facultades = 0;

    if ((int)estimacion.size() - 1 > 0) {
        for (int i = (int)estimacion.size() - 1; i > 0; i--) {
            estimacion[i - 1] += estimacion[i];
        }
    }

    resolver(datos, sol, marcas, mascarillasFacultades, precioActual, precioMin, 0, exito, estimacion,facultades);
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