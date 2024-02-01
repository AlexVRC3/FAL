/*
 * Plantilla para la Práctica 3
 * Escribid vuestro nombre y usuarios:
 *   - Victor Sandu F86
 *   - Alejandro Vida Ramírez De Arellano F99
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct sol {
    bool propiedad;
    int sumaIz;
    int sumaDr;
};
using matriz = vector<vector<int>>;

/*
*                     {     c0                     si n = 1
               T(n) = {
                      {     2T(n/2) + c1 * n^0     si n > 1

                Aplicando el teorema de la division con a = 2 , b = 2 y k = 0 entonces a > b^k por lo tanto el coste
                asintotico en tiempo del algoritmo es del orden de O(n^log en base b de a) = O(n^log en base 2 de 2) = O(n)
                Siendo n el numero de elementos del vector (cada fila de la matriz)
 */

sol es_degradado(const vector<int>& v, int ini, int fin) {
    if (ini == fin) { // n = 1 hay solo 1 elemento y por tanto cumple la propiedad y la sumaIz y sumaDr es el propio elemento
        return { true,v[ini],v[ini] };
    }
    else { // Caso recursivo n >= 1
        int mit = (ini + fin) / 2;
        sol izq = es_degradado(v, ini, mit);        // 2 llamadas una para la mitad izquierda y otra para la mitad derecha
        sol der = es_degradado(v, mit + 1, fin);

        bool b = izq.propiedad && der.propiedad && izq.sumaIz < der.sumaDr; // Si las dos mitades son un degradado y ademas e la suma de los colores
        // de la mitad izquierda de la imagen es menor que la suma de los valores de la mitad derecha
        return { b,izq.sumaIz + izq.sumaDr, der.sumaIz + der.sumaDr };
    }
}

/*
 * Función iterativa que llama a una función recursiva que comprueba si la fila es un degradado.
 * ¡¡¡COMPLETALA!!
 */
bool comprueba_matriz(const matriz& v, const int N, const int M) {
    bool lo_es = true;
    int i = 0;
    while (lo_es && i < N) {
        //LLama a la función recursiva y actualiza las variables
        lo_es = es_degradado(v[i], 0, v[i].size() - 1).propiedad;
        i++;
    }

    return lo_es;
}

//--- NO MODIFIQUES NADA AQUÍ -----//
//------------------------------------------------------
bool resuelveCaso() {

    //Lectura de datos
    int N, M; //filas y columnas
    cin >> N >> M;
    if (!cin)
        return false;

    matriz imagen;
    for (int i = 0; i < N; i++) {
        vector<int> fila(M); //para leer la fila
        for (int j = 0; j < M; j++)
            cin >> fila[j];
        imagen.push_back(fila);
    }

    //En imagen hay N filas y cada una de ellas es un vector de tamaño M

    bool sol = comprueba_matriz(imagen, N, M);

    if (sol)
        cout << "SI\n";
    else
        cout << "NO\n";

    return true;

}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}