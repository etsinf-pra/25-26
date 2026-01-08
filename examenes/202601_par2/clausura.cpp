/*
4.
Dado un grafo dirigido G, se define la clausura transitiva de G 
como otro grafo G' que cumple: dos nodos (i,j) están conectados 
en G' si existe un camino entre ellos en G. Se considera que 
siempre hay un camino de un nodo a sí mismo.

Escribe el pseudocódigo de una función 
que obtenga la clausura transitiva de un grafo.
*/
#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int V;                   // número de vértices
    vector<vector<int>> adj; // lista de adyacencia
    vector<vector<bool>> tc; // matriz de clausura transitiva
public:
    Graph(int V){
        this->V = V;
        adj.resize(V);
        tc.resize(V, vector<bool>(V, false));
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }
    void dfs(int s, int v);
    void closure();
    void printTC() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << tc[i][j] << " ";
            }
            cout << endl;
        }
    }
};




// Función recursiva para dfs que busca todos los nodos 
// alcanzables desde s. 
void Graph::dfs(int s, int v) {
    // marca en la clausura que el nodo v es alcanzable desde s
    tc[s][v] = true;
    // Explora todos los vecinos de s
    for (int u : adj[v]) {
        // si no se ha visitado, se llama recursivamente
        if (!tc[s][u]) 
            dfs(s, u);
    }
}
// Función que genera la clausura transitiva
void Graph::closure()
{
    // Busca todos los caminos posibles desde cada nodo usando dfs
    for (int i = 0; i < V; i++)
        dfs(i, i); // Un nodo es alcanzable desde sí mismo
}


int main() {
    // 1 -> 0, 0 -> 2, 3 -> 1
    Graph g(4);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(3, 1);
    cout << "Matriz de clausura transitiva es \n";
    g.closure();
    g.printTC();

    return 0;
}
