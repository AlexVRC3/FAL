#include <iostream>
#include <iomanip>
#include <fstream>          ﻿// Alejandro Vida Ramírez de Arellano
// F99
#include <vector>

using namespace std;

//P={ 0<=v.size()<=2000 /\ l>=1 /\ Pti: 0<=i<l: (v[i]!=0 && v[i]!= 1) }
int numSegmentos(const vector<int>& v, int l) {
    int cuenta = 1;
    int ceros = 0;
    int unos = 0;

    for (int i = l; i < v.size(); i++) {//v.size()-i
        //Invariante = { (l<=i<=N) /\ (ceros = #s: i-l<s<=i:v[s]=0) /\ (unos = #s: i-l<s<=i:v[s]=1)  /\
                                                           #(p,q):0<=p<q<i /\ q-p=l:cerosUnos(v,p,q) /\ cerosUnos(v,p,q) = (#s:p<=s<q:v[s]=1) = (#s:p<=s<q:v[s]=0)}

        if (v[i] == 0) ceros++;
        if (v[i - l] == 0) ceros--;

        if (v[i] == 1) unos++;
        if (v[i - l] == 1) unos--;

        if (ceros == unos) cuenta++;

    }

    return cuenta;
}
//Q={ cuenta = #(p,q):0<=p<q<v.size() /\ q-p=l:cerosUnos(v,p,q) /\ cerosUnos(v,p,q) = (#s:p<=s<q:v[s]=1) = (#s:p<=s<q:v[s]=0) }


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tam, longitud, dato;
    vector<int>v;
    cin >> longitud >> tam;
    for (int i = 0; i < tam; i++) {
        cin >> dato;
        v.push_back(dato);
    }

    int sol = numSegmentos(v, longitud);
    // escribir sol
    cout << sol << endl;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
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