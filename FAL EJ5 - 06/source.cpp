
/*@ <authors>
 *
 * Alejandro Vida Ramírez de Arellano F99
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


/*@ <answer>

Explicación poda:

- Se ordena en orden decreciente el vector de objetos segun la relacion superficie/coste y se estima la maxima superficie restante que se puede llegar a obetener para poder podar soluciones
  que no pueden llegar a ser mejores que la que tenemos.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>


struct Objeto {
    int coste;
    int superficie;
};

bool operator>(const Objeto o1, const Objeto o2) {
    float num1 = (float)o1.superficie / o1.coste;
    float num2 = (float)o2.superficie / o2.coste;
    return num1 > num2;
}

bool es_solucion(const int k, const int n) {
    return k == n - 1;
}

bool es_valida(const int gastoActual, const int presupuesto) {
    return gastoActual <= presupuesto;
}

bool es_mejor(const int supActual, const int maxSup) {
    return supActual > maxSup;
}

bool es_completable(const int k, const int n) {
    return k < n - 1;
}

bool es_prometedora(const int i, const int n, const int presupuesto, const int gastoActual, const vector<Objeto>& objetos, const int supActual, const int maxSup) {
    int supRestante = 0;
    int coste = gastoActual;
    int cont = i + 1;

    while (cont < n && coste < presupuesto) {
        supRestante += objetos[cont].superficie;
        coste += objetos[cont].coste;
        cont++;
    }

    if (cont < n + 1 && coste > presupuesto) {
        supRestante -= objetos[cont - 1].superficie * (coste - presupuesto) / objetos[cont - 1].coste;
    }

    return supActual + supRestante > maxSup;
}


void adornosNavidad(const int i, const int n, const int presupuesto, int &gastoActual, const vector<Objeto>& objetos, int& supActual, int& maxSup) {

    // no cogemos el objeto
    if (es_solucion(i, n) && es_mejor(supActual, maxSup)) {
        maxSup = supActual;
    }
    else if (es_completable(i, n) && es_prometedora(i,n,presupuesto,gastoActual,objetos,supActual,maxSup)) {
        adornosNavidad(i + 1,n,presupuesto,gastoActual,objetos,supActual, maxSup);
    }

    // lo cogemos

    gastoActual += objetos[i].coste;
    supActual += objetos[i].superficie;
    if (es_valida(gastoActual, presupuesto)) {
        if (es_solucion(i, n) && es_mejor(supActual, maxSup))
            maxSup = supActual;
        else 
            adornosNavidad(i + 1, n, presupuesto, gastoActual, objetos, supActual, maxSup);
    }
    gastoActual -= objetos[i].coste;
    supActual -= objetos[i].superficie;
}

int inicializar_sol(vector<Objeto> const& objetos, const int n, const int presupuesto) {
    
    int supInicial = 0;
    int coste = 0;
    int cont = 0;

    while (cont < n && coste < presupuesto) {
        supInicial += objetos[cont].superficie;
        coste += objetos[cont].coste;
        cont++;
    }

    if (cont < n + 1 && coste > presupuesto) {
        supInicial -= objetos[cont - 1].coste;
    }

    return supInicial;
}



bool resuelveCaso() {
    int n, presupuesto;
    cin >> n >> presupuesto;

    if (!std::cin)  // fin de la entrada
        return false;

    vector<Objeto> objetos(n);
    for (int i = 0; i < n; i++) {
        cin >> objetos[i].coste >> objetos[i].superficie;
    }

    sort(objetos.begin(), objetos.end(), greater<Objeto>());
    int supActual = 0;
    int gastoActual = 0;
    int maxSup = inicializar_sol(objetos,n,presupuesto);

    adornosNavidad(0,n, presupuesto, gastoActual, objetos, supActual, maxSup);

    cout << maxSup<< endl;
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
