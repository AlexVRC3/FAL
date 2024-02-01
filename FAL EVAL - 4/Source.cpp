/*
 * Plantilla para la práctica 4
 * Escribid vuestro nombre y usuarios:
 *   - Victor Sandu F86
 *   - Alejandro Vida Ramírez de Arellano F99
 *
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/* Para los colores usamos 3 valores enteros:
 *    0 -> azul
 *    1 -> rojo
 *    2 -> verde
 * Esta función devuelve un string según el valor del entero
 */
string color(const int i) {
    switch (i) {
    case 0:
        return "azul";
    case 1:
        return "rojo";
    case 2:
        return "verde";
    }
}

/*
*  En cada etapa k(posicion de la torre hasta H) asignamos una pieza del color i. El espacio de busqueda tiene anchura numColores y longitud numPosicioness
 * El vector<int> sol en el cual cada posicion k con 0 <= k < H es el color en numero que se coloca en cada posicion de la torre. Utilizamos un
 * vector<int> marcas el cual contiene en cada posicion el numero de piezas de cada color colocadas.
 *
 */

bool es_valido(const vector<int>& colores, const int k, const vector<int>& sol, const int H, const vector<int>& marcas, const int i) {
    if (colores[1] == 0)
        return false; // No hay piezas rojas
    if (k == 0)
        return sol[k] == 1; // Si la primera pos es roja
    if (colores[i] == marcas[i]) // No me quedan piezas verdes o azules para poner
        return false;
    if (sol[k] == 2) { // Si el color actual es verde
        if (sol[k - 1] == 2) // No puede haber dos verdes consecutivas
            return false;
        if (marcas[2] >= marcas[0]) // No puede haber mas verdes que azules
            return false;
    }

    return true;
}

bool es_valida_final(const vector<int>& marcas) {
    int sumaRojos = marcas[1];
    int sumaAzul_Verdes = marcas[0] + marcas[2];
    return sumaRojos > sumaAzul_Verdes;
}

void mostrar_soluciones(const vector<int>& sol) {
    for (int i = 0; i < sol.size(); i++)
    {
        cout << color(sol[i]) << " ";
    }
    cout << endl;
}


void torres_colores(const vector<int>& colores, const int k, vector<int>& sol, const int H, vector<int>& marcas, bool& exito) {
    for (int i = 0; i < 3; i++)
    {
        sol[k] = i; // Colocamos el color i en la posicion k de la torre
        if (es_valido(colores, k, sol, H, marcas, i)) {
            marcas[i]++;
            if (k == H - 1) {
                if (es_valida_final(marcas)) {
                    exito = true;
                    mostrar_soluciones(sol);
                }
            }
            else if (k < H - 1) {
                torres_colores(colores, k + 1, sol, H, marcas, exito);
            }
            marcas[i]--;
        }
    }
}


bool resuelveCaso() {
    int H, A, R, V; //Altura, Azul, Rojo y Verde
    cin >> H >> A >> R >> V;
    if (H == 0 && A == 0 && R == 0 && V == 0)
        return false;

    vector<int> colores(3);
    colores[0] = A;
    colores[1] = R;
    colores[2] = V;

    vector<int> sol(H);
    vector<int> marcas(3, 0);
    bool exito = false;

    torres_colores(colores, 0, sol, H, marcas, exito);
    if (!exito)
        cout << "SIN SOLUCION" << endl;
    cout << endl;

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}