/*
comprueba si hay un ciclo en una lista de enlaces de un grafo
*/

#include <iostream>
#include <vector>

using namespace std;

void print(vector <pair<string, string> > edges) {
    for(auto e : edges) {
        cout << e.first << " -> " << e.second << endl;
    }
    cout << "----" << endl;
}

// esta es la función que hay que implementar en el ejercicio
void route (vector <pair<string,string> > edges) {
    if(edges.size() == 1) {
        cout << edges.front().first << " -> " << edges.front().second << endl;
        return;
    }
    pair<string, string> cur;
    do{
        // sacamos el primer enlace
        cur = edges[0];
        edges.erase(edges.begin());
        // buscamos si hay un enlace que empiece donde termina cur
        for(int i = 0; i < edges.size(); i++) {
            if(edges[i].second == cur.first) {
                // muevo el enlace al final y pruebo con el siguiente
                edges.push_back(cur);
                cur.first = "";
                break;
            }
        }
    } while(cur.first == "");
    cout << cur.first << " -> ";
    route(edges);
}

int main() {
    vector <pair<string, string> > edges;
    edges.push_back(make_pair("EWR", "LAX"));
    edges.push_back(make_pair("MAD", "EWR"));
    edges.push_back(make_pair("LAX", "AKL"));
    edges.push_back(make_pair("VLC", "MAD"));
    print(edges);
    route(edges);
}

