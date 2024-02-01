
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

// noMas(v,i,j,l) del bool b : b = (#c : i <= c < j : v[c] % 2 == 1) <= l

// P = {l >= 0 /\ 0 <= k <= n /\ Pt i: 0 <= i <= k: v[i] % 2 == 0}
int resolver(const vector<int>& v, const int k, const int l) {
    int nSeg = 1;
    int impares = 0;
    for (int i = k; i < v.size(); i++) // Cota: v.size() - i que decrece en cada iteracion y asegura la terminacion del bucle
    {
        if (v[i] % 2 == 1)  // I = { k <= i <= v.size() /\ nSeg = (#p,q) : 0 <= p <= q < v.size() : noMas(v,p,q,l) /\ impares = (#c : i <= c < j : v[c] % 2 == 1 /\ j - i = l)
            impares++;
        if (v[i - k] % 2 == 1)
            impares--;
        if (impares <= l)
            nSeg++;
    }

    return nSeg;
}

// Q = {nSeg = (#p,q) : 0 <= p <= q < v.size() : noMas(v,p,q,l)}

void resuelveCaso() {

    // leer los datos de la entrada
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> v(n);
    for (int& i : v)
        cin >> i;

    cout << resolver(v, k, l) << "\n";
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
