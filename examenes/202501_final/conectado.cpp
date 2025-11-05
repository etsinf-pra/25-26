/*
comprueba si el grqfo está conectado

Usa una matriz de adyacencia
*/

#include <iostream>
#include <ctime>
#include <vector>
#include <queue>
#include <set>
using namespace std;

#define SIZE 10 

void print(vector<vector<int> > &g) {
    cout << "\t0 1 2 3 4 5 6 7 8 9" << endl;
    for(int i = 0; i < g.size(); i++) {
        cout << i << ":\t";
        for(int j = 0; j < g[i].size(); j++)
            cout << g[i][j] << " ";
        cout << endl;
    }
}


// devuelve la lista de vecinos de un nodo 
vector<int> neighbors(vector<vector<int> > &g, int u) {
    vector<int> neig;
    for(int i = 0; i < g.size(); i++)
        if(g[u][i])
            neig.push_back(i);
    return neig;
}


// busca un camino entre dos nodos
bool conectado(vector<vector<int> > &g) {
    //crea el conjunto de vértices
    set<int> V;
    for(int i = 0; i < g.size(); i++)
        V.insert(i);
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        V.erase(u);
        for(int n : neighbors(g, u))
            //inserta nuevos nodos en la cola
            if(V.find(n) != V.end())
                q.push(n);
    }
    //si V está vacío, se han visitado todos los nodos
    return V.empty();
}



// genera un grafo aleatorio dirigido de n nodos con probabilidad p
void graph(vector<vector<int> > &g, int n, float p){
    g.resize(n);
    for(int i = 0; i < n; i++)
        g[i].resize(n, 0);
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++){
            g[i][j] = (rand() / (float)RAND_MAX) < (p*0.5);
            if(g[i][j] == 1) g[j][i] = 1;
        }
    }
}


int main() {
    vector<vector<int> > g;
    srand(time(NULL));
    //usa un valor menor  para que el grafo esté desconectado
    graph(g, SIZE, 0.7);
    print(g);
    // busca el camino
    int connected = conectado(g);
    cout << "Conectado: " << connected << endl;
}

