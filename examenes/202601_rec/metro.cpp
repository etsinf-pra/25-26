/*
problema 4
La red de metro puede modelarse como un grafo dirigido, donde
cada estación es un nodo y cada conexión directa entre estaciones es una
arista.
Se pide escribir el pseudocódigo de un algoritmo que, dadas una estación
de origen y una de destino, devuelva el número mínimo de estaciones que
hay que pasar (incluyendo el origen y el destino) para llegar de una estación
a otra. En la imagen, la distancia entre desde E hasta I es 4 (E-D-G-I)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>

using namespace std;

struct Estacion {
    char nombre;
    vector<Estacion*> vecinos;
};

// Función auxiliar para agregar aristas bidireccionales (grafo no dirigido)
void agregar_arista(map<char, Estacion*>& grafo, char a, char b) {
    grafo[a]->vecinos.push_back(grafo[b]);
    grafo[b]->vecinos.push_back(grafo[a]);
}

// Algoritmo BFS para encontrar distancia mínima entre dos estaciones
// Devuelve el número mínimo de estaciones (incluyendo origen y destino)
int estaciones(map<char, Estacion*>& grafo, char origen, char destino) {
    map<char, int> d;
    
    // Inicializar todas las distancias a -1 (no visitadas)
    for (auto& [nombre, estacion] : grafo) {
        d[nombre] = -1;
    }
    
    queue<char> q;
    q.push(origen);
    d[origen] = 1;  // La distancia incluye el origen
    
    while (!q.empty()) {
        char v = q.front();
        q.pop();
        
        // Iterar sobre todos los vecinos de v
        for (Estacion* u : grafo[v]->vecinos) {
            if (d[u->nombre] == -1) {
                d[u->nombre] = d[v] + 1;
                q.push(u->nombre);
                
                // Si llegamos al destino, podemos retornar directamente
                if (u->nombre == destino) {
                    return d[destino];
                }
            }
        }
    }
    
    return d[destino];  // Retorna -1 si no hay camino, o la distancia si la hay
}

int main() {
    // Construir el grafo del ejemplo
    map<char, Estacion*> grafo;
    
    // Crear estaciones
    vector<char> nombres = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};
    for (const auto& nombre : nombres) {
        grafo[nombre] = new Estacion{nombre, {}};
    }    
  
    // Amarilla A-B-G-H
    agregar_arista(grafo, 'A', 'B');
    agregar_arista(grafo, 'B', 'G');
    agregar_arista(grafo, 'G', 'H');
    
    // Roja B-C-D-E-F
    agregar_arista(grafo, 'B', 'C');
    agregar_arista(grafo, 'C', 'D');
    agregar_arista(grafo, 'D', 'E');
    agregar_arista(grafo, 'E', 'F');
    
    // Verde B-C-G-I
    agregar_arista(grafo, 'C', 'G');
    agregar_arista(grafo, 'G', 'I');
    
    // Azul K-J-D-G-I
    agregar_arista(grafo, 'K', 'J');
    agregar_arista(grafo, 'J', 'D');
    agregar_arista(grafo, 'D', 'G');
    grafo['I']->vecinos.push_back(grafo['G']);

    // Calcular distancias
    int distancia = estaciones(grafo, 'E', 'I');
    cout << "Distancia de E a I: " << distancia << " estaciones\n";
    
    distancia = estaciones(grafo, 'A', 'H');
    cout << "Distancia de A a H: " << distancia << " estaciones\n";
    
    return 0;
}
