/*
problema 3
En una red de routers, cada uno identificado por una IP numérica,
un virus puede propagarse solo hacia routers con IP mayor que la del router
infectado.
Se pide escribir un pseudocódigo de un algoritmo que calcule la probabilidad
de que cada router se infecte a partir de un router r si cada conexión
propaga el virus con una probabilidad p = 0, 5.
El cálculo de un nodo v se actualiza a partir de cada vecino u con la siguiente
fórmula
P[v]nuevo = 1 − (1 − P[v]actual) × (1−P[u] × p)

Ejemplo
router: 10 (infectado), 15, 20
conexiones: 10 -> 15, 10 -> 20, 15 -> 20
P[10] = 1 (infectado)
P[15] = 1  - (1 - 0) x (1 - 1 x 0.5) = 0.5
P[20] (desde 10) = 1  - (1 - 0) x (1 - 1 x 0.5) = 0.5
P[20] (desde 15) = 1  - (1 - 0.5) x (1 - 0.5 x 0.5) = 0.625
*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Router {
    int ip;
    bool visited;
    vector<Router*> in;   // vecinos con IP menor (entrantes)
    vector<Router*> out;  // vecinos con IP mayor (salientes)
    Router(int ip_) : ip(ip_), visited(false) {}
};

// Agrega una conexión dirigida u -> v (u.ip < v.ip)
void addEdge(Router* u, Router* v) {
    u->out.push_back(v);
    v->in.push_back(u);
}

// Calcula probabilidades usando una cola de prioridad (orden por IP ascendente)
// Los vecinos se generan con enlaces salientes y el cálculo usa enlaces entrantes.
void infectado(Router* start, map<int, double>& P) {
    auto cmp = [](Router* a, Router* b) { return a->ip > b->ip; };
    priority_queue<Router*, vector<Router*>, decltype(cmp)> pq(cmp);
    pq.push(start);

    while (!pq.empty()) {
        Router* v = pq.top();
        pq.pop();
        if (v->visited) continue;
        v->visited = true;

        // Actualizar v a partir de sus enlaces entrantes
        for (Router* u : v->in) {
            P[v->ip] = 1.0 - (1.0 - P[v->ip]) * (1.0 - P[u->ip] * 0.5);
        }

        // Generar vecinos usando enlaces salientes
        for (Router* w : v->out) {
            if (!w->visited) {
                pq.push(w);
            }
        }
    }
}



int main() {
    // Construir ejemplo: nodos con IP 10,15,20
    vector<Router*> routers;
    routers.push_back(new Router(10));
    routers.push_back(new Router(15));
    routers.push_back(new Router(20));

    int n = routers.size();
    // conexiones: 10 ->15, 10 ->20, 15 ->20
    addEdge(routers[0], routers[1]);
    addEdge(routers[0], routers[2]);
    addEdge(routers[1], routers[2]);
    map<int, double> P;
    for (int i = 0; i < n; ++i) {
        P[routers[i]->ip] = 0.0;
    }

    // router 10 infectado inicialmente
    P[10] = 1.0;

    // ejecutar el procedimiento desde el router 10
    infectado(routers[0], P);

    // mostrar probabilidades
    cout.setf(std::ios::fixed); cout.precision(4);
    for (int i = 0; i < n; ++i) {
        cout << "P[" << routers[i]->ip << "]: P = " << P[routers[i]->ip] << "\n";
    }

    
    return 0;
}
