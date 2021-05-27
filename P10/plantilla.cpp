// Ari Rubén Simao Chaves
// Miguel Pomboza Guadalupe
// Juez: C89

#include <sstream> //para strinstream
#include <iostream>
#include <fstream>
#include <string>
#include "TreeMap.h"
#include "List.h"

//Hay que elegir un diccionario.
//¿Necesitamos que esté ordenado? ¿Que no lo esté?

//Método para leer un diccionario
void leerDiccionario(TreeMap<string, int>& diccionario) {
    string linea;
    int valor;
    getline(cin, linea);
    stringstream lin(linea); //procesar la línea
    string clave;
    while (lin >> clave) {
        lin >> valor;
        diccionario.insert(clave, valor);
    }
}

class Actualizacion {
public:
    List<string> nuevas;
    List<string> eliminadas;
    List<string> modificadas;
};

//Método que hace el problema. Recibe los diccionarios antiguo y nuevo.
//Debe devolver los cambios en alguna/s estructura/s adecuada/s
void calcularCambios(const TreeMap<string, int>& DiccionarioAntiguo, const TreeMap<string, int>& DiccionarioNuevo, Actualizacion& lista) {

    TreeMap <string, int> ::ConstIterator it = DiccionarioNuevo.cbegin();
    // Recorremos el diccionarioNuevo de principio a fin
    while (it != DiccionarioNuevo.cend()) {
        // Comprobamos si la clave actual (del diccionarioNuevo) se encuntra en el diccionarioAntiguo
        if (DiccionarioAntiguo.contains(it.key())) {
            // Si lo esta comprobamos si sus valores son distintos
            if (DiccionarioAntiguo.at(it.key()) != it.value()) {
                //  Si lo son lo añadimos a la lista de claves modificadas
                lista.modificadas.push_back(it.key());
            }
        }
        // Si no lo esta añadimos a la lista de nuevas la nueva clave
        else {
            lista.nuevas.push_back(it.key());
        }
        it.next();
    }

    TreeMap <string, int> ::ConstIterator it2 = DiccionarioAntiguo.cbegin();
    // Recorremos el diccionarioNuevo de principio a fin
    while (it2 != DiccionarioAntiguo.cend()) {
        // Comprobamos si no esta la clave actual (del diccionarioAntiguo) en el diccionarioNuevo
        if (!DiccionarioNuevo.contains(it2.key())) {
            // Si no lo esta, signific que ha sido eliminada y la añadimos a la lista de eliminadas
            lista.eliminadas.push_back(it2.key());
        }
        it2.next();
    }
}

//Método para escribir por pantalla los cambios en los diccionarios.
void printCambios(Actualizacion listas) {
    if (listas.nuevas.empty() && listas.eliminadas.empty() && listas.modificadas.empty()) {
        std::cout << "Sin cambios" << endl;
    }
    else {
        if (!listas.nuevas.empty()) {
            List<string> ::ConstIterator it = listas.nuevas.cbegin();

            std::cout << "+ ";
            while (it != listas.nuevas.cend()) {
                std::cout << it.elem() + " ";
                it.next();
            }
            std::cout << endl;
        }

        if (!listas.eliminadas.empty()) {
            List<string> ::ConstIterator it2 = listas.eliminadas.cbegin();

            std::cout << "- ";
            while (it2 != listas.eliminadas.cend()) {
                std::cout << it2.elem() + " ";
                it2.next();
            }
            std::cout << endl;
        }

        if (!listas.modificadas.empty()) {
            List<string> ::ConstIterator it3 = listas.modificadas.cbegin();

            std::cout << "* ";
            while (it3 != listas.modificadas.cend()) {
                std::cout << it3.elem() + " ";
                it3.next();
            }
            std::cout << endl;
        }

    }

    std::cout << "---" << endl;


}

//Esqueleto para resuelve caso: leemos los diccionarios, calculamos
//los cambios y los sacamos por pantalla.
void resuelveCaso() {
    TreeMap <string, int> DiccionarioAntiguo;
    TreeMap <string, int> DiccionarioNuevo;
    Actualizacion listas;

    leerDiccionario(DiccionarioAntiguo);
    leerDiccionario(DiccionarioNuevo);
    calcularCambios(DiccionarioAntiguo, DiccionarioNuevo, listas);
    printCambios(listas);
}

//Método main.
int main() {
#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    int numCasos;
    std::cin >> numCasos;
    std::cin.ignore(1); //ignorar salto de línea
    for (int i = 0; i < numCasos; i++) {
        resuelveCaso();
    }

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
