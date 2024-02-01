/*@ <authors>
 *
 * Alejandro Vida Ramírez de Arellano F99
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct tSol {
    int ini;
    int lon;
    int perdida;
};

// P = { -1000 <= limite <= -1 /\ 0 < nDias < 100000 /\ Pt i: 0 <= i < nDias: -1000 <= gastosDia[i] <= 1000}
// Predicado aux diasPerdiendo(v, limite) = max q,p : Pt k: 0 <= p <= k <= q < v.size() v[k] < limite : dev q y p
tSol resolver(const vector<int>& beneficios_dia, const int limite, const int nDias) {
    tSol sol = { 0,0,0 };
    int beneficio = 0;
    int maxPerdida = 0;
    int ini = 0;
    for (int i = 0; i < nDias; i++) // Cota nDias - i que decrece en cada iteracion y asegura la terminación del bucle
    {
        beneficio = beneficios_dia[i];
        if (beneficio < limite) { // es una secuencia prometedora
            int lon = i - ini + 1;
            maxPerdida = min(beneficio, maxPerdida);
            if ((maxPerdida <= sol.perdida && lon >= sol.lon)) {      //I = {0 <= i <= nDias /\ 0 <= ini <= ini + lon <= nDias /\ beneficio = Pt j: 0 <= j < nDias: beneficios_dia[j]
                sol.perdida = maxPerdida;                             // maxGasto = max k: 0 <= k < nDias /\ beneficios_dia[k] < limite 
                sol.ini = ini;                                          // perdida = max k: 0 <= k < nDias /\ diasPerdiendo(v,limite) /\ p <= k <= q : beneficios_dia[k]
                sol.lon = lon;
            }
        }
        else {
            ini = i + 1;
            beneficio = 0;
            maxPerdida = 0;
        }
    }
    return sol;
}
// Q = { 0 <= ini <= ini + lon <= nDias /\ perdida = max k: 0 <= k < nDias /\ diasPerdiendo(v,limite) /\ p <= k <= q : beneficios_dia[k]}

bool resuelveCaso() {

    // leer los datos de la entrada
    int nDias, limite;
    cin >> nDias >> limite;
    if (nDias == 0)
        return false;
    
    vector<int> gastosDia(nDias);
    for (int i = 0; i < nDias; i++)
    {
        cin >> gastosDia[i];
    }

    tSol sol = resolver(gastosDia, limite,nDias);
    if (sol.perdida >= limite)
        cout << "SIN PERDIDAS";
    else
        cout << sol.lon << " " << sol.ini << " " << sol.perdida;
    cout << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

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
