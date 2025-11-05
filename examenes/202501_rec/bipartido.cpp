/*
grafo bipartido: 
es bipartifo si se puede colorear con dos colores sin que
nodos adyacentes tengan el mismo color
*/

#include <iostream>
#include <ctime>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define SIZE 10

void print(vector<vector<int> > &g) {
    // heading
    cout << "\t";
    for(int i = 0; i < SIZE; i++)
        cout << i << " ";
    cout << endl;
    // table
    for(int i = 0; i < SIZE; i++) {
        cout << i << ":\t";
        for(int j = 0; j < SIZE; j++)
            cout << g[i][j] << " ";
        cout << endl;
    }
}


// devuelve la lista de vecinos de un nodo 
vector<int> neighbors(vector<vector<int> > &g, int u) {
    vector<int> neig;
    for(int i = 0; i < SIZE; i++)
        if(g[u][i])
            neig.push_back(i);
    return neig;
}


// genera un grafo aleatorio de n nodos con probabilidad p
void graph(vector<vector<int> > &g, int n, float p){
    int m = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            if( i == j) g[i][j] = 0;
            g[i][j] = (rand() / (float)RAND_MAX) < (p * 0.5);
            if(g[i][j] == 1){
                g[j][i] = 1;
                m += 2;
            }
        }
    }
    cout << "density " << m / (float)(n * n) << endl;
}

// genera un grafo bipartido
void bipartite(vector<vector<int> > &g, int n) {
    int m = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            g[i][j] = 0;
    for(int i = 0; i < n / 2; i++)
        for(int j = n / 2; j < n; j++) {
            g[i][j] = (rand() / (float)RAND_MAX) < 0.5;
            if(g[i][j] == 1){
                g[j][i] = 1;
                m += 2;
            }
        }
    cout << "density " << m / (float)(n * n) << endl;

}

// Esta es la función que hay que implementar
// Uso un vector para asignar el conjunto a los nodos
bool bipartido(vector<vector<int> > &g, vector<int> &s) {
    queue<int> q;
    q.push(0);
    s[0] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        //current set opposite to u
        int set = (s[u] == 0) ? 1 : 0;
        for(int v: neighbors(g, u)) {
            if(s[v] == s[u])
                return false;
            if(s[v] == -1) {
                s[v] = set;
                q.push(v); 
            }
        }
    }
    return true;
}



int main() {
    vector<vector<int> > g(SIZE, vector<int>(SIZE, 0));
    srand(time(NULL));
    // genera un grafo aleatorio
    //graph(g, SIZE, 0.3);
    // genera un grafo bipartido
    bipartite(g, SIZE);
    print(g);
    vector<int> set(SIZE,-1);
    bool es_bip = bipartido(g, set);
    if(!es_bip){
        cout << "No Es bipartido" << endl;
        return 0;
    }
    cout << "set 1: ";  
    for(int i = 0; i < SIZE; i++)
        if(set[i] == 0)
            cout << i << " ";
    cout << endl << "set 2: ";
    for(int i = 0; i < SIZE; i++)
        if(set[i] == 1)
            cout << i << " ";
    cout << endl;
    return 0;
}

