// Ari Rub�n Simao Chaves
// Miguel Pomboza Guadalupe
// Juez: C89

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <string>
#include "HashMap.h"
#include "TreeMap.h"

class ConteoVotos {

private:
    using Estado = string;
    using Partido = string;

    struct InfoEstado {
        int compromisarios = 0;
        HashMap<Partido, int> votos;
        string partidoMax;
        int max = 0;
    };

    HashMap<string, InfoEstado> Estados;

    TreeMap<string, int> Partidos;

    // funci�n que se encarga de sacar los partidos que han ganado en alg�n estado y de sumarles los compromisarios ganados por ello
    // En el peor de los casos, el coste es cuadrático ya que recorre todos los estados y dentro de estos recorre todos los partidos
    void calculaResultados() {
        TreeMap<string, int> resultados;
        HashMap <string, InfoEstado>::Iterator ite = Estados.begin();

        while (ite != Estados.end()) {
            if (!resultados.contains(ite.value().partidoMax))
                resultados.insert(ite.value().partidoMax, ite.value().compromisarios);
            else {
                resultados.find(ite.value().partidoMax).value() += ite.value().compromisarios;
            }
            ite.next();
        }

        Partidos = resultados;
    }

public:

    // Coste lineal O(n) siendo 'n' el n�mero de nodos del HashMaps, porque en el peor de los casos habr� recorrido todo el HashMap si no existi el elemento buscado
    // e 'insert' tiene el mismo coste por lo que se mantiene lineal
    void nuevo_estado(const Estado& nombre, int num_compromisarios) {
        if (Estados.find(nombre) != Estados.end())
            throw domain_error("Estado ya existente");

        InfoEstado info;
        info.compromisarios = num_compromisarios;
        Estados.insert(nombre, info);
    }

    // El coste es cuadràtico ya que en el peor de los casos la funcion que determina el tiempo de ejecución del algoritmo es la de mayor 
    // coste, en este caso calculaResultados(). No se toma en cuenta el coste de insert() ya que en el peor de los casos sería
    // de coste lineal
    void sumar_votos(const Estado& estado, const Partido& partido, int num_votos) {
        HashMap <string, InfoEstado>::Iterator it = Estados.find(estado);
        if (it == Estados.end())
            throw domain_error("Estado no encontrado");

        HashMap <string, int>::Iterator itp = it.value().votos.find(partido);
        if (itp == it.value().votos.end()) {
            it.value().votos.insert(partido, num_votos);
            if (num_votos > it.value().max) {
                it.value().max = num_votos;
                it.value().partidoMax = partido;
            }
        }
        else {
            itp.value() += num_votos;
            if (itp.value() > it.value().max) {
                it.value().max = itp.value();
                it.value().partidoMax = partido;
            }
        }

        calculaResultados();
    }

    // coste lineal O(n) siendo 'n' el n�mero de nodos en el HashMap, porque en el peor de los casos recorrer� todo el HashMap al no encontrar el elemento buscado
    // el coste de sacar y devolver el valor una vez encontrado el elemento es constante, por lo que prevalece el lineal para funci�n al ser mayor al constante
    Partido ganador_en(const Estado& estado) const {
        HashMap <string, InfoEstado>::ConstIterator it = Estados.find(estado);
        if (it == Estados.cend())
            throw domain_error("Estado no encontrado");
        return it.value().partidoMax;
    }

    // coste lineal O(n) siendo 'n' el n�mero de nodos en el TreeMap, porque recorremos siempre todos los nodos que contiene para insert�rselos en el vector
    vector<pair<Partido, int>> resultados() const {
        TreeMap <string, int>::ConstIterator it = Partidos.cbegin();

        vector<pair<Partido, int>> resultado;
        while (it != Partidos.cend()) {
            resultado.push_back(std::make_pair(it.key(), it.value()));
            it.next();
        }

        return resultado;
    }
};


bool resuelveCaso() {
    using Estado = string;
    using Partido = string;
    string comando;
    cin >> comando;
    if (!cin) return false;

    ConteoVotos elecciones;

    while (comando != "FIN") {
        try {
            if (comando == "nuevo_estado") {
                Estado estado;
                int num_compromisarios;
                cin >> estado >> num_compromisarios;
                elecciones.nuevo_estado(estado, num_compromisarios);
            }
            else if (comando == "sumar_votos") {
                Estado estado;
                Partido partido;
                int num_votos;
                cin >> estado >> partido >> num_votos;
                elecciones.sumar_votos(estado, partido, num_votos);
            }
            else if (comando == "ganador_en") {
                Estado estado;
                cin >> estado;
                Partido ganador = elecciones.ganador_en(estado);
                cout << "Ganador en " << estado << ": " << ganador << "\n";
            }
            else if (comando == "resultados") {
                for (const auto& res : elecciones.resultados()) {
                    cout << res.first << " " << res.second << "\n";
                }
                // El for de arriba est� sustituyendo al de abajo porque el de abajo daba error y no hab�a forma de solucionarlo.
                // El c�digo de arriba se nos ha sido proporcionado por el profesor al explicarle el problema, y nos lo di� como soluci�n.
                /*for (const auto& [partido, num_comp] : elecciones.resultados()) {
                    cout << partido << " " << num_comp << "\n";
                }*/
            }
        }
        catch (std::exception& e) {
            cout << e.what() << "\n";
        }
        cin >> comando;
    }

    cout << "---\n";
    return true;
}

int main() {
#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {}

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
