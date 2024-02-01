
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
                    { c1 si             n == 2
            T(n) =  {                                Como a = 4, b = 2 y k = 0: el coste seria del orden de O(n^log2 4) = O(n^2) = O(N^2)
                    { 4T(n/2) + c2 si   n > 2
 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

using matriz = vector<vector<int>>;


bool equilibrada(const matriz& mat,int dim ,int fila_ini, int fila_fin, int col_ini, int col_fin, int& suma) {
    if (dim == 2) {
        if (mat[fila_ini][col_ini] == 1)suma++;
        if (mat[fila_ini][col_fin] == 1)suma++;
        if (mat[fila_fin][col_ini] == 1)suma++;
        if (mat[fila_fin][col_fin] == 1)suma++;
        
        if (suma >= 1 && suma <= 3) return true;
        else return false;
    }
    else {
        int fila_m = (fila_ini + fila_fin) / 2, col_m = (col_ini + col_fin) / 2;
        int superior_izq = 0, inferior_izq = 0, superior_der = 0, inferior_der = 0;
        bool propiedad1 = equilibrada(mat, dim / 2, fila_ini, fila_m, col_ini, col_m, superior_izq) &&
            equilibrada(mat, dim / 2, fila_m + 1, fila_fin, col_ini, col_m, inferior_izq) &&
            equilibrada(mat, dim / 2, fila_ini, fila_m, col_m + 1, col_fin, superior_der) &&
            equilibrada(mat, dim / 2, fila_m + 1, fila_fin, col_m + 1, col_fin, inferior_der);

        if (propiedad1) {
            bool propiedad2 = abs(superior_izq - superior_der) <= 2 &&
                abs(inferior_izq - inferior_der) <= 2 &&
                abs(superior_izq - inferior_izq) <= 2 &&
                abs(superior_der - inferior_der) <= 2 &&
                abs(superior_izq - inferior_der) <= 2 &&
                abs(superior_der - inferior_izq) <= 2;
            if (propiedad2) return true;
            else return false;
        }
        else return false;
    }
}

bool resolver(const matriz& mat) {
    if (mat.size() == 1) return true;
    else {
        int fila_ini = 0, fila_fin = mat.size() - 1, col_ini = 0, col_fin = mat.size() - 1, suma = 0, dim = mat.size();
        return equilibrada(mat,dim, fila_ini, fila_fin, col_ini, col_fin, suma);
    }
}

void resuelveCaso() {

    int N;
    cin >> N;
    matriz mat(N, vector<int> (N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> mat[i][j];
        }
    }
    if (resolver(mat))
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
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
