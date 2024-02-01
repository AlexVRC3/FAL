
/*@ <authors>
 *
 * Alejandro Vida Ram�rez de Arellano F99
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

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

using matriz = vector<vector<int>>;

bool es_solucion(const int m, const int c, const vector<int>& sol, const vector<int>& marcador){
    return c == m - 1 && marcador[sol[c]] < 3;
}

bool es_completable(const int m, const int c, const vector<int> & sol, const vector<int> & marcador) {
    return c < m - 1 && marcador[sol[c]] < 3;
}

bool es_mejor(const int costeActual, const int costeMinimo) {
    return costeMinimo == -1 || costeActual < costeMinimo;
}

bool es_prometedora(const int costeActual, const int mejorPrecio, const int costeMinimo) {
    return costeMinimo == -1 || costeActual + mejorPrecio < costeMinimo;
}

void supermercado(const int n, const int m, const int c, const matriz& mat, vector<int> & marcador_super, int& costeActual, int& costeMinimo, vector<int>& sol, vector<int> & mejor_sol, const vector<int> & mejores_precios) {
    for (int f = 0; f < n; f++)
    {
        sol[c] = f;
        costeActual += mat[f][c];
        if (es_solucion(m, c,sol,marcador_super) && es_mejor(costeActual, costeMinimo)) {
            mejor_sol = sol;
            costeMinimo = costeActual;
        }
        else if (es_completable(m, c,sol,marcador_super) && es_prometedora(costeActual, mejores_precios[c + 1], costeMinimo)) {
            marcador_super[f]++;
            supermercado(n, m, c + 1, mat, marcador_super, costeActual, costeMinimo, sol, mejor_sol, mejores_precios);
            marcador_super[f]--;
        }
        costeActual -= mat[f][c];
    }
}

void resuelveCaso() {

    int n, m;
    cin >> n >> m;

    matriz precios(n,vector<int>(m));
    vector<int> mejores_precios(m, INT_MAX);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> precios[i][j];
            if (precios[i][j] < mejores_precios[j])
                mejores_precios[j] = precios[i][j];
        }
    }
    vector<int> comprados_super(n, 0);
    vector<int> sol(m), mejor_sol(m);

    for (int i = m-2; i >= 0; --i)
    {
        mejores_precios[i] += mejores_precios[i + 1];
    }

    int costeActual = 0;
    int costeMinimo = -1;

    supermercado(n, m, 0 , precios, comprados_super, costeActual, costeMinimo, sol, mejor_sol, mejores_precios);
    if (costeMinimo == -1)
        cout << "Sin solucion factible" << endl;
    else
        cout << costeMinimo << endl;
    
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
