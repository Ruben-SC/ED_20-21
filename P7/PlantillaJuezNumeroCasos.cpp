// Ari Rubén Simao Chaves
// Miguel Pomboza Guadalupe
// Juez: C89

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbin.h"
#include "List.h"

// función que resuelve el problema

int resolver(Arbin<int> arbol, int &grupos) {
    if (arbol.esVacio()) {
        return 0;
    }
    else if (arbol.hijoIz().esVacio() && arbol.hijoDr().esVacio()) {
        if (arbol.raiz() > 0) grupos += 1;
        return arbol.raiz();
    }
    else {
        int iz = resolver(arbol.hijoIz(), grupos);
        int der = resolver(arbol.hijoDr(), grupos);

        if (iz > 0 && der > 0)
            grupos += 1;

        if (iz + arbol.raiz() > der + arbol.raiz())
            return (iz + arbol.raiz());
        else
            return (der + arbol.raiz());
    }
}

Arbin<int> leerArbol(const int& repVacio) {
    int elem;
    std::cin >> elem;
    if (elem == repVacio)
        return Arbin<int>();
    else {
        Arbin<int> hi = leerArbol(repVacio);
        Arbin<int> hd = leerArbol(repVacio);
        return Arbin<int>(hi, elem, hd);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    Arbin<int> arbol = leerArbol(-1);
    int grupos = 0;
    int max = 0;

    max = resolver(arbol, grupos);
    std::cout << grupos << " " << max << std::endl;
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