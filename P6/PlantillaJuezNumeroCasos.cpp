// Ari Rubén Simao Chaves
// Miguel Pomboza Guadalupe
// Juez: C89

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree.h"

// función que resuelve el problema
void resolver(bintree<int> arbol, bool &control) {
    
    if (arbol.left().empty() && arbol.right().empty()) {
        if (!control) {
            std::cout << arbol.root();
            control = true;
        }
        else {
            std::cout << " " << arbol.root();
        }
    }
    else {
        if(!arbol.left().empty())
            resolver(arbol.left(), control);
        if (!arbol.right().empty())
            resolver(arbol.right(), control);
    }
}

bintree<int> leerArbol(const int& repVacio) {
    int elem;
    std::cin >> elem;
    if (elem == repVacio)
        return bintree<int>();
    else {
        bintree<int> hi = leerArbol(repVacio);
        bintree<int> hd = leerArbol(repVacio);
        return bintree<int>(hi, elem, hd);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arbol = leerArbol(-1);
    bool control = false;
    if (arbol.empty()) {
        std::cout << endl;
    }
    else {
        resolver(arbol, control);
        std::cout << endl;
    }
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