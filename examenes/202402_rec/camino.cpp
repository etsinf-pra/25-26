/*
comprueba si hay un ciclo en una lista de enlaces de un grafo

Usa una matriz de adyacencia
*/

#include <iostream>
#include <ctime>
#include <vector>
#include <queue>
using namespace std;

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
int path(vector<vector<int> > &g, int u, int v) {
    struct node {
        int id, level;
        node(int i, int l) : id(i), level(l) {}
    };  
    vector<bool> visited(g.size());
    queue<node> q;
    q.push(node(u,0));
    while(!q.empty()) {
        node cur = q.front();
        q.pop();
        visited[cur.id] = true;
        for(int n : neighbors(g, cur.id)) {
            if(n == v)
                return cur.level + 1;
            if(!visited[n])
                q.push(node(n, cur.level + 1));
        }
    }
    return 0;
}



// genera un grafo aleatorio dirigido de n nodos con probabilidad p
void digraph(vector<vector<int> > &g, int n, float p){
    g.resize(n);
    for(int i = 0; i < n; i++) {
        g[i].resize(n);
        for(int j = 0; j < n; j++)
            g[i][j] = (rand() / (float)RAND_MAX) < p;
    }
}


int main() {
    vector<vector<int> > g;
    srand(time(NULL));
    digraph(g, 10, 0.3);
    print(g);
    // genera dos nodos al azar
    int v, u = rand() % 10;
    do{
        v = rand() % 10;
    } while(u == v);
    // busca el camino
    int len = path(g, u, v);
    cout << "Camino de " << u << " a " << v << endl;
    cout << "Longitud del camino: " << len << endl;
}

