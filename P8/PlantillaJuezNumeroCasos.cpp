// Ari Rubén Simao Chaves
// Miguel Pomboza Guadalupe
// Juez: C89

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbin.h"
#include "List.h"

// función que resuelve el problema
// coste lineal O(n) siendo 'n' el número de nodos del árbol, porque en el peor de los casos recorre todos lo nodos de este, que será cuando SI sea genealógico
int resolver(Arbin<int> arbol, bool &es, int gens) {
    if (arbol.esVacio()) {
        return 0;
    }
    
    if (!arbol.hijoDr().esVacio()) {
        if (arbol.hijoIz().esVacio()) {
            es = false;
            return 0;
        }
        if (arbol.raiz() - arbol.hijoIz().raiz() < 18) {
            es = false;
            return 0;
        }
        if (arbol.hijoIz().raiz() - arbol.hijoDr().raiz() < 2) {
            es = false;
            return 0;
        }
    }
    else if (!arbol.hijoIz().esVacio()) {
        if (arbol.raiz() - arbol.hijoIz().raiz() < 18){
            es = false;
            return 0;
        }
    }

    int maxI = resolver(arbol.hijoIz(), es, gens+1);
    int maxD = resolver(arbol.hijoDr(), es, gens+1);

    if (maxI > gens)
        gens = maxI;
    if (maxD > gens)
        gens = maxD;

    return gens;
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
    //int gens = 0;
    bool genealogico = true;

    int gens = resolver(arbol, genealogico, 1);
    if (genealogico)
        std::cout << "SI" << " " << gens << std::endl;
    else
        std::cout << "NO" << std::endl;
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