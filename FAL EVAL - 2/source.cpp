// Usuarios Juez : F86 y F99
// Nombres de la pareja : VICTOR SANDU y ALEJANDRO VIDA RAMÍREZ DE ARELLANO

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

using lli = long long int;
// Coste complementario

/*

        {  c1 si n < 10
T(n) = {                                Como a = 1 y b = 10 -> Si a < b: T(n) ∈ Θ(n^k) por tanto coste O(n) siendo n numero de digitos
        {  aT(n/10) + c2n^k si n >= 10

*/

lli complementario(lli n) {
    lli sol = 0;
    if (n < 10) {
        sol = 9 - n;
        return sol;
    }
    else {
        return complementario(n / 10) * 10 + (9 - (n % 10));
    }

}

int longitud(lli n) {
    if (n < 10) {
        return 1;
    }
    else {
        return 1 + longitud(n / 10);
    }
}

// Coste inverso
/*

        {  c1 si n < 10
T(n) = {                                Como a = 1 y b = 10 -> Si a < b: T(n) ∈ Θ(n^k) por tanto coste O(n) siendo n numero de digitos
        {  aT(n/10) + c2n^k si n >= 10

*/

lli inverso(lli num, int numInver) {
    lli sol = 0;
    if (num > 0) {
        sol = inverso(num / 10, num % 10 + numInver * 10);
    }
    else {
        sol = numInver;
    }
    return sol;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    lli n;
    cin >> n;

    lli comp = complementario(n);
    lli invertido = inverso(comp, 0);

    int longComp = longitud(comp);
    int longnormal = longitud(n);

    if (longComp != longnormal)
        invertido = invertido * pow(10, longnormal - longComp);

    cout << comp << " " << invertido << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}