// Ari Rubén Simao Chaves
// Miguel Pomboza Guadalupe
// Juez: C89

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbin.h"
#include "List.h"

// función que resuelve el problema
void resolver(Arbin<int> arbol, List<int> &lista) {

    if (arbol.hijoIz().esVacio() && arbol.hijoDr().esVacio()) {
        lista.push_back(arbol.raiz());
    }
    else {
        if(!arbol.hijoIz().esVacio())
            resolver(arbol.hijoIz(), lista);
        if (!arbol.hijoDr().esVacio())
            resolver(arbol.hijoDr(), lista);
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
    List<int> lista;

    if (arbol.esVacio()) {
        std::cout << std::endl;
    }
    else {
        resolver(arbol, lista);

        List<int>::Iterator it = lista.begin();
        while (it != lista.end()) {
            if (it != lista.begin())
                std::cout << " ";
            std::cout << it.elem();
            it.next();
        }
        std::cout << std::endl;
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