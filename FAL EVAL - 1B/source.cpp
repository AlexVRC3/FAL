#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// ﻿Nombre del alumno  Alejandro Vida Ramírez de Arellano y Victor Sandu
// Usuario del Juez F99 y F86

// función que resuelve el problema
struct tSol {
    int ini;
    int fin;
    int suma;
};

// Resolvemos el problema recorriendo el vector y guardando la sumaAct siempre que sea positiva. La vamos comparando con la sumaMax y en caso de ser superior
// actualizamos los indices. En caso de ser igual comprobamos si la longitud de la secuencia que ya teniamos era mayor y en caso de serlo nos quedamos con la nueva
// El coste de la función resolver es del orden de O(N) (siendo N el número de elementos del vector)
// ya que recorremos el vector entero para poder sacar el segmento máximo y eso depende del tamaño del vector y dentro del bucle las operaciones 
// son de coste constante
// positivos(v,i)= Ex i: 0 <= i < v.size() : v[i] > 0
// negativos(v,i)= Ex i: 0 <= i < v.size() : v[i] < 0
// P = { Pt i: 0 <= i < datos.size() : Ex j: i <= j < datos.size() : datos[j] > 0 /\ positivos(v,i) /\ negativos(v,i)


tSol resolver(const vector<int>& datos) {
    int ini = 0;
    int fin = 0;
    int sumaAct = 0;
    int sumaMax = 0;
    int tempIni = 0;
    tSol sol{ 0,0,0 };

    for (int i = 0; i < datos.size(); i++) // Función de cota: datos.size() - i que es positiva al principio del bucle y decrece con cada iteración y asegura que termina el bucle
    {
        sumaAct += datos[i];
        if (sumaAct <= 0) {
            sumaAct = 0;
            tempIni = i + 1;
        }
        else if (sumaAct > sumaMax) {       // I = { 0 <= i <= datos.size() /\ sumaAct = [ (sumaAct>0) --> (sum j: 0 <= j < datos.size() : datos[j]) || (sumaAct<=0) --> (sum = 0) ] 
                                            // /\ sumaMax = (sumaAct > sumaMax) --> sumaMax = sumaAct /\ ini = tempIni /\ fin = i // longitud(p,q) = q - p
            sumaMax = sumaAct;              // 0 <= ini <= fin < datos.size() /\ sumaAct == sumaMax --> [(longitud(tempIni, i) < longitud(fin,ini)) --> ini = tempIni /\ fin = i]
            ini = tempIni;                  // 0 <= tempIni < datos.size()
            fin = i;
        }
        else if (sumaAct == sumaMax) {
            if (i - tempIni < fin - ini) {
                ini = tempIni;
                fin = i;
            }
        }
    }
    return { ini, fin - ini + 1, sumaMax };

}
// Q = { 0 <= ini <= fin < datos.size() /\ sumaMax = (sumaAct > sumaMax) --> [sumaMax = sumaAct /\ ini = tempIni] /\ longitud(ini,fin) + 1}
// Devuelve el inicio de la secuencia, su longitud y su sumaMaxima

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!std::cin)
        return false;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    tSol sol = resolver(v);

    cout << sol.suma << " " << sol.ini << " " << sol.fin << endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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