
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
                    { c1 si                                 si   n <= 1
            T(n) =  {                                                           Como a = 2, b = 2, k = 1 obtenemos aplicando el teorema de la division que el coste asintotico en tiempo de la funcion recursiva es del orden de O(N log N)
                    { 2T(n/2) + c2 * N + c3 * N + c4 * N    si   n > 1
 @ </answer> */



 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

using solucion = pair<int, vector<int>>;

vector<int> mezcla_ordenada(vector<int> const& izq, vector<int> const& der) {
    vector<int> ord(izq.size() + der.size());

    int cont = 0, cont_izq = 0, cont_der = 0;

    while (cont_izq < izq.size() && cont_der < der.size()) {
        if (izq[cont_izq] < der[cont_der]) {
            ord[cont] = izq[cont_izq];
            cont_izq++;
        }
        else {
            ord[cont] = der[cont_der];
            cont_der++;
        }
        cont++;
    }
    // Añadimos los que faltan
    while (cont_izq < izq.size()) {
        ord[cont] = izq[cont_izq];
        cont_izq++;
        cont++;
    }
    while (cont_der < der.size()) {
        ord[cont] = der[cont_der];
        cont_der++;
        cont++;
    }

    return ord;
}

solucion reestructurar(const vector<int>& naves, int ini, int fin) {
    int N = fin - ini;
    vector<int> ordenado(N);
    int intercambios;

    if (ini == fin)
        return { 0, ordenado };
    if (ini == fin - 1) {
        ordenado[0] = naves[ini];
        intercambios = 0;
        return { intercambios,ordenado };
    }
    else {
        int mit = (ini + fin) / 2;
        solucion izq = reestructurar(naves, ini, mit);
        solucion der = reestructurar(naves, mit, fin);


        //Ordenacion con mezcla

        ordenado = mezcla_ordenada(izq.second, der.second); // O(N)

        intercambios = izq.first + der.first;
        int cont = 0, cont_der = 0;
        bool ya_colocados = false;
        while (cont < ordenado.size() && cont_der < der.second.size() && !ya_colocados) { // como max N/2 vueltas
            if (ordenado[cont] < der.second[cont_der]) {
                cont++;
            }
            else {
                if (mit + cont_der == cont)
                    ya_colocados = true;
                else
                    intercambios += mit + cont_der - (cont + ini);
                cont++;
                cont_der++;
            }
        }

        return { intercambios,ordenado };
    }
}





int resolver(const vector<int>& naves) {
    return reestructurar(naves, 0, naves.size()).first;
}


bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    cin >> n;

    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> naves(n);
    for (int i = 0; i < n; i++)
    {
        cin >> naves[i];
    }
    int sol = resolver(naves);
    cout << sol << endl;

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
