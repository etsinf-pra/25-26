/*
3.
Una fábrica produce una pieza que debe pasar por varias máquinas. Cada máquina realiza una operación en un tiempo de procesamiento determinado. Algunas operaciones no pueden comenzar hasta que otras hayan terminado. Se pueden ejecutar varias operaciones en paralelo si no hay dependencias entre ellas.

Escribe el pseudocódigo de un algoritmo que devuelva el tiempo mínimo necesario para obtener la pieza final procesada.

Ejemplo:
Máquinas y tiempos:  {A(3), B(2), C(4), D(5), E(2)}
Dependencias: {A -> C, B -> C, C -> D, C -> E}
Respuesta: {12}

(algoritmo de Kahn para ordenación topológica con cálculo de tiempos mínimos)
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int tiempoMinimo(
    const vector<int>& dur,
    const vector<vector<int>>& adj) {
    int nelem = dur.size();
    vector<int> t(nelem, 0);
    vector<int> indeg(nelem, 0);
    for (int u = 0; u < nelem; ++u)
        for (int v : adj[u])
            indeg[v]++;

    queue<int> q;
    for (int i = 0; i < nelem; i++) {
        if (indeg[i] == 0) {
            //opcion 2 
            //t[i] = dur[i];
            q.push(i);
        }
    }

    while (!q.empty()) {
        int maquina = q.front();
        q.pop();
        // opcion 2: comentar esta línea
        t[maquina] += dur[maquina];
        for (int u : adj[maquina]) {
            // opcion 2
            // t[u] = max(t[u], t[maquina] + dur[u]);
            t[u] = max(t[u], t[maquina]);
            if (--indeg[u] == 0) {
                q.push(u);
            }
        }
    }
    return *max_element(t.begin(), t.end());
}

int main() {
    // Ejemplo: A(3), B(2), C(4), D(5), E(2)
    vector<int> dur = {3, 2, 4, 5, 2};
    // 0:A, 1:B, 2:C, 3:D, 4:E
    vector<vector<int>> adj(5);
    adj[0].push_back(2); // A -> C
    adj[1].push_back(2); // B -> C
    adj[2].push_back(3); // C -> D
    adj[2].push_back(4); // C -> E
    cout << tiempoMinimo(dur, adj) << endl; // Debe mostrar 12
    return 0;
}
