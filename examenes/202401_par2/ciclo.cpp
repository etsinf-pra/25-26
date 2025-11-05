/*
comprueba si hay un ciclo en una lista de enlaces de un grafo
*/

#include <iostream>
#include <cstdlib>
#include <set>
#include <stack>

using namespace std;

void print(set <pair<int, int> > edges) {
    //for(set <pair<int, int> >::iterator it = edges.begin(); it != edges.end(); it++)
    for(auto it: edges)
        cout << it.first << " -> " << it.second << endl;
    cout << "----" << endl;
}


bool cyclerec(set <pair<int, int> > edges, int u, bool *visited) {
    if(visited[u])
        return true;
    visited[u] = true;
    for(auto it: edges) {
        if(it.first == u) {
            if(cyclerec(edges, it.second, visited))
                return true;
        }
    }
    visited[u] = false;
    return false;
}

int main() {
    set <pair<int, int> > edges;
    int nnodes = 6;
    int nedges = 8;
    srand(time(NULL));
    for(int i = 0; i < nedges; i++) {
        int u = rand() % nnodes;
        int v = rand() % nnodes;
        if(u == v)
            continue;
        edges.insert(make_pair(u, v));
    }
    print(edges);
    
    map<string, bool> visited;
    for(auto &e: edges){
        visited[e.first] = false;
        visited[e.second] = false;
    }

    bool detected = cyclerec(edges, 0, visited);
    cout << "Ciclo (rec): " << detected << endl;
}

