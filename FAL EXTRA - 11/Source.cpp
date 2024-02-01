
/*@ <authors>
 *
 * Alejandro Vida Ramírez de Arellano F99
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


/*
            { c1                si n == 2
    T(n) =  {                                       Aplicando el teorema de la division a = 2, b = 2, k = 0 como a > b^k entonces el coste es de la forma O(n^log b a) = O(n)
            { T(n/2) + c2 si   si n > 2

*/


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct tSol {
    bool extranyo;
    int sp;
    int pi;
    int si;
    int pp;
};

tSol resolver(const vector<int>& v, const int ini, const int fin) {
    if (ini == fin) {
        int val = v[ini];
        if (val % 2 == 0)
            return { true,val,1,0,val };
        else
            return { true,0,val,val,1 };
    }
    else {
        int mit = (ini + fin) / 2;
        tSol izq = resolver(v, ini, mit);
        tSol der = resolver(v, mit + 1, fin);

        bool cond = (izq.extranyo || der.extranyo) && izq.sp + izq.pi <= der.si + der.pp;

        return { cond, izq.sp + der.sp, izq.pi * der.pi, izq.si + der.si, izq.pp * der.pp };
        
    }
}

void resuelveCaso() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    tSol sol = resolver(v, 0, n - 1);
    if (n == 0 || sol.extranyo)
        cout << "SI\n";
    else
        cout << "NO\n";
    
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
