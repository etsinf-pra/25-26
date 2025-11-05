/*
Coloreado de grafos:

Dos nodos adyacentes tienen que estar pintados con colores distintos
True si se puede colorear el grafo con 4 colores, False en caso contrario
*/

#include <iostream>
#include <ctime>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define SIZE 5
#define NOCOLOR 0
#define R 1
#define G 2
#define B 3
#define Y 4


inline char letracolor(int c) {
    string letra = "RGBY";
    return letra[c];
}   



void print(int g[][SIZE]) {
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

void print(map<int, int> assign) {
    for(auto p: assign)
        cout << p.first << " = " << letracolor(p.second) << ", ";
    cout << endl;
}

// devuelve la lista de vecinos de un nodo 
vector<int> neighbors(int g[][SIZE], int u) {
    vector<int> neig;
    for(int i = 0; i < SIZE; i++)
        if(g[u][i])
            neig.push_back(i);
    return neig;
}


// genera un grafo aleatorio de n nodos con probabilidad p
void graph(int g[][SIZE], int n, float p){
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

// devuelve true si no hay nodos adyacentes con el mismo color
bool is_safe(int g[][SIZE], map<int, int> c, int i, int col) {
    for(int n: neighbors(g, i))
        if(c[n] == col)
            return false;
    return true;
}

// colorea el grafo con 4 colores. Esta es la función que hay que implementar
void colorea(int g[][SIZE], map<int, int> assign, int i) {
    print(assign);
    if(assign.size() == SIZE)
        return;
    for(int col = R; col < Y; col++){
        if(!is_safe(g, assign, i, col))
            return;
        assign[i] = col;
        for(int n: neighbors(g, i))
            for(int ncol = R; ncol < Y; ncol++){
                if(col != ncol && is_safe(g, assign, n, ncol))
                    colorea(g, assign, n);
            }
        assign.erase(i);
    }
}



int main() {
    int g[SIZE][SIZE];
    srand(time(NULL));
    graph(g, SIZE, 0.7);
    print(g);
    map<int, int> col;
    colorea(g, col, 0);
    for(int i = 0; i < SIZE; i++)
        cout << letracolor(col[i]) << " ";
    return 0;
}

