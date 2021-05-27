// Ari Rubén Simao Chaves
// Miguel Pomboza Guadalupe
// Juez: C89

#include <iostream>
#include <iomanip>
#include <fstream>
#include "TreeSet.h"


// función que resuelve el problema
int resolver(TreeSet<int> arbol) {
    
    return 0;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    TreeSet<int> arbol;
    int tamA;
    int cotas;

    std::cin >> tamA;
    std::cin >> cotas;

    if (!std::cin)
        return false;

    for (int i = 0; i < tamA; i++) {
        int a;
        std::cin >> a;
        arbol.insert(a);
    }

    for (int i = 0; i < cotas; i++) {
        int low, up;
        std::cin >> low;
        std::cin >> up;
        int sol = arbol.count_interval(low, up);
        std::cout << sol << std::endl;
    }
    // escribir sol

    std::cout << "---" << std::endl;

    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}