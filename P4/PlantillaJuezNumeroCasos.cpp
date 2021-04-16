// Ari Rubén Simao Chaves
// Miguel Pomboza Guadalupe
// Juez: C89

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Queue.h"


// función que resuelve el problema
void resolver(Queue<int> cola, Queue<int> colegas, int pringao) {

    cola.colarse(colegas, pringao);

    std::cout << cola.front();
    cola.pop_front();

    while (!cola.empty()) {
        std::cout << " " << cola.front();
        cola.pop_front();
    }
    std::cout << std::endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    Queue<int> cola;
    Queue<int> colegas;
    int pringao;
    int aux;

    std::cin >> aux;
    while (aux != -1) {
        cola.push_back(aux);
        std::cout << aux << " ";
        std::cin >> aux;
    }
    std::cout << std::endl;

    std::cin >> pringao;

    std::cin >> aux;
    while (aux != -1) {
        colegas.push_back(aux);
        std::cin >> aux;
    }

    resolver(cola, colegas, pringao);
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