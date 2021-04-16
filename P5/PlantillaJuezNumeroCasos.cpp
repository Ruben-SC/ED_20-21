// Ari Rubén Simao Chaves
// Miguel Pomboza Guadalupe
// Juez: C89

#include <iostream>
#include <iomanip>
#include <fstream>
#include "List.h"


// función que resuelve el problema
void resolver(List<int> lista) {

    if (lista.empty()) {
        return;
    }

    List<int>::Iterator it = lista.begin();
    int aux = it.elem();
    it.next();

    while (it != lista.end()) {
        if (aux > it.elem()) {
            it = lista.erase(it);
        }
        else {
            aux = it.elem();
            it.next();
        }
    }

    it = lista.begin();
    while (it != lista.end()) {
        if (it != lista.begin())
            std::cout << " ";
        std::cout << it.elem();
        it.next();
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    List<int> lista;
    int aux;

    std::cin >> aux;
    while (aux != -1) {
        lista.push_back(aux);
        std::cin >> aux;
    }

    resolver(lista);
    std::cout << std::endl;
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