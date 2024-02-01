// Alejandro Vida Ramírez de Arellano F99

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

using matriz = vector<vector<bool>>;

using marcador = vector<bool>;

// Calcula la diagonal ascendente de la casilla [f,c]
int d_asc(const int f, const int c, const int n) {
    return c + f + 2 * n - 1;
}

// Calcula la diagonal descendente de la casilla [f,c]
int d_desc(const int f, const int c, const int n) {
    return c - f + n - 1;
}

// Comprueba que la casilla no este rota, que no haya una figura ya en esa fila y que no haya una reina en esa diagonal
bool casilla_valida(matriz const& invalidas, const int fila, const int col, const int n, const marcador& filas, const marcador& diag_reinas) {
    return !invalidas[fila][col] && !filas[fila] && !diag_reinas[d_asc(fila, col, n)] && !diag_reinas[d_desc(fila, col, n)];
}

// Comprueba que hayamos colocado todas las figuras
bool es_solucion(const int k, const int n) {
    return k == n - 1;
}

// Comprueba que todavia queden figuras por colocar
bool es_completable(const int k, const int n) {
    return k < n - 1;
}

// Comprueba si ya habia torres en las diagonales de la casilla
bool hay_torres_diag(const int k, const int n, const vector<int>& sol, const marcador& diag_torres) {
    return diag_torres[d_asc(sol[k], k, n)] || diag_torres[d_desc(sol[k], k, n)];
}

// Marca o desmarca los marcadores pasados como parametro
void marcar_y_desmarcar(const bool marca_f, const bool marca_d_asc, const bool marca_d_desc, marcador& filas, marcador& diagonales, const int fila, const int col, const int n) {
    filas[fila] = marca_f;
    diagonales[d_asc(fila, col, n)] = marca_d_asc;
    diagonales[d_desc(fila, col, n)] = marca_d_desc;
}



void torres_reinas(int & torres, int& reinas, const int n, const matriz & invalidas, int k, vector<int> &sol, int& nSols, marcador &filas, marcador& diag_torres, marcador& diag_reinas) {
    for (int i = 0; i < n; i++)
    {
        if (casilla_valida(invalidas, i, k, n, filas, diag_reinas)) {
            sol[k] = i; // Colocamos la figura en la posicion del tablero [i,k]
            //colocamos una torre
            if (torres > 0) {
                torres--;
                if (es_solucion(k, n))
                    nSols++;
                else if (es_completable(k, n)) {
                    // guardamos los marcadores anteriores por si habia una torre en esa diagonal
                    bool anterior_asc = diag_torres[d_asc(i, k, n)];
                    bool anterior_desc = diag_torres[d_desc(i, k, n)];
                    marcar_y_desmarcar(true, true, true, filas, diag_torres, i, k, n);
                    torres_reinas(torres, reinas, n, invalidas, k + 1, sol, nSols, filas, diag_torres, diag_reinas);
                    marcar_y_desmarcar(false, anterior_asc, anterior_desc, filas, diag_torres, i, k, n);
                }
                torres++;
            }
            // colocamos una reina
            if (reinas > 0) {
                reinas--;
                if (es_solucion(k, n) && !hay_torres_diag(k,n,sol,diag_torres))
                    nSols++;
                else if (es_completable(k, n) && !hay_torres_diag(k, n, sol, diag_torres)) {
                    
                    marcar_y_desmarcar(true, true, true, filas, diag_reinas, i, k, n);
                    torres_reinas(torres, reinas, n, invalidas, k + 1, sol, nSols, filas, diag_torres, diag_reinas);
                    marcar_y_desmarcar(false, false, false, filas, diag_reinas, i, k, n);
                }
                reinas++;
            }
        }
    }
}

int resolver(const int T, const int R, const int N, const matriz& invalidas) {
    int torres = T;
    int reinas = R;
    int k = 0;
    vector<int> sol(N);
    int nSols = 0;
    if (N > 0) {
        marcador filas(N, false);
        marcador diag_torres(4 * N - 2, false);
        marcador diag_reinas(4 * N - 2, false);

        torres_reinas(torres,reinas,N,invalidas,k,sol,nSols,filas,diag_torres,diag_reinas);
    }

    return nSols;
}


bool resuelveCaso() {
    int T, R, nCasillas;
    cin >> T >> R;

    if (!std::cin)
        return false;

    cin >> nCasillas;
    int fil, col;
    int N = T + R;
    matriz tablero(N, vector<bool>(N, false));
    for (int i = 0; i < nCasillas; i++)
    {
        cin >> fil >> col;
        tablero[fil - 1][col - 1] = true;
    }

    cout << resolver(T, R, N, tablero) << endl;

    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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
