
/*@ <authors>
 *
 * Alejandro Vida Ram�rez de Arellano F99
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

// P = { 0 < n <= 10^6 /\ Pt i: 0 <= i < n : INT_MIN <= v[i] <= INT_MAX }

// Predicados aux:
// minimo(v,i,j) = min k: 0 <= i <= k < j: v[k]
// nVeces(v,i,j) = #k : 0 <= i < k < j: v[k] == minimo(v,i,j)


bool es_minimalista(const vector<int>& v, const int n) {
    if (v.size() == 1)
        return true;
    int i = 1;
    int minimo = v[0];
    // I = { 0 < i <= n /\ minimo = minimo(v,i,n-1) /\ b = Pt i,j: 0 <= i < j < n: nVeces(v,i,j) == 1 ? true : false

    while (i < n) { // Funcion de cota: n - i que decrece en cada iteracion y demuestra la terminaci�n del bucle
        if (v[i] == minimo)
            return false;
        else if (v[i] < minimo) {
            minimo = v[i];
        }
        i++;
    }
    return true;
}
// Q = {b = Pt i,j: 0 <= i <= j < n: nVeces(v,i,j) == 1 ? true : false}

bool resuelveCaso() {

    int n;
    cin >> n;
    if (n == -1)
        return false;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    if (es_minimalista(v, n)) 
        cout << "SI";
    else
        cout << "NO";
    cout << endl;
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
