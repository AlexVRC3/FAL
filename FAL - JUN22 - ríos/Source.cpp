
/*@ <authors>
 *
 * Alejandro Vida Ramírez de Arellano F99
 *
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

int calcularMinimo(const vector<int>& v, int ini, int fin) {
    if (ini == fin) {
        return v[ini];
    }
    else if (ini + 1 == fin) {
        return v[ini] < v[fin] ? v[ini] : v[fin];
    }
    else {
        int m = (ini + fin) / 2;
        if (v[m - 1] >= v[m] && v[m] <= v[m+1]) {
            return v[m];
        }

        if (v[m] > v[m + 1])
            return calcularMinimo(v, m + 1, fin);
        else
            return calcularMinimo(v, ini, m - 1);
    }
}

int calcularLongitud(const vector<int>& v, int minimo) {
    int l = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == minimo)
            l++;  
    }
    return l;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == -1)
        return false;
    vector<int> v(n);
    for (int& i : v)
        cin >> i;

    int minimo = calcularMinimo(v,0,n - 1);
    
    int longitud = calcularLongitud(v, minimo);
    cout << longitud << endl;
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
