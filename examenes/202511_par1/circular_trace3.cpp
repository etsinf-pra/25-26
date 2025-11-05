/*
Modificacion del algoritmo para FORZAR la exploracion de AMBAS ramas
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int nivel = 0;

string indent() {
    string s = "";
    for (int i = 0; i < nivel; i++) s += "  ";
    return s;
}

// Version modificada que explora AMBAS ramas para demostrar el caso
void sobrescritos_ambas_ramas(const vector<int> &v, int inf, int sup) {
    nivel++;
    cout << indent() << "-> sobrescritos(inf=" << inf << ", sup=" << sup 
         << ") segmento: {";
    for (int i = inf; i <= sup; i++) {
        cout << v[i];
        if (i < sup) cout << ", ";
    }
    cout << "}" << endl;
    
    if (inf == sup) {
        cout << indent() << "  inf == sup -> return 0" << endl;
        nivel--;
        return;
    }
    
    if (sup - inf == 1) {
        cout << indent() << "  inf + 1 == sup -> return " << sup << endl;
        nivel--;
        return;
    }
    
    if (v[inf] < v[sup]) {
        cout << indent() << "  v[" << inf << "]=" << v[inf] 
             << " < v[" << sup << "]=" << v[sup] 
             << " -> return 0 (SEGMENTO ORDENADO, NO HAY RUPTURA)" << endl;
        nivel--;
        return;
    }
    
    int m = (inf + sup) / 2;
    cout << indent() << "  m = " << m << ", v[m] = " << v[m] << endl;
    
    // Exploramos AMBAS ramas para demostracion
    cout << indent() << "  Explorando rama DERECHA:" << endl;
    sobrescritos_ambas_ramas(v, m, sup);
    
    cout << indent() << "  Explorando rama IZQUIERDA:" << endl;
    sobrescritos_ambas_ramas(v, inf, m);
    
    nivel--;
}

int main() {
    vector<int> v = {60, 70, 80, 10, 20, 30, 40, 50};
    cout << "===============================================" << endl;
    cout << "Vector: {60, 70, 80, 10, 20, 30, 40, 50}" << endl;
    cout << "Indices: 0   1   2   3   4   5   6   7" << endl;
    cout << "Ruptura entre indice 2 y 3 (80 -> 10)" << endl;
    cout << "Segmento [3-7] = {10,20,30,40,50} esta ORDENADO" << endl;
    cout << "===============================================\n" << endl;
    
    sobrescritos_ambas_ramas(v, 0, v.size() - 1);
    
    cout << "\n===============================================" << endl;
    cout << "OBSERVA como el segmento [3,7] cumple v[3] < v[7]" << endl;
    cout << "y retorna 0, indicando que NO hay ruptura ahi." << endl;
    cout << "===============================================" << endl;

    return 0;
}
