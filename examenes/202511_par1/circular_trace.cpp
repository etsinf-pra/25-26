/*
Version con trazas para entender el flujo de recursion
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

int sobrescritos(const vector<int> &v, int inf, int sup) {
    nivel++;
    cout << indent() << "-> sobrescritos(inf=" << inf << ", sup=" << sup 
         << ") v[" << inf << "]=" << v[inf] << ", v[" << sup << "]=" << v[sup] << endl;
    
    // Si el segmento esta ordenado ascendentemente, no hay ruptura aqui
    if (v[inf] < v[sup]) {
        cout << indent() << "  v[inf] < v[sup] -> return 0 (segmento ordenado, NO hay ruptura aqui)" << endl;
        nivel--;
        return 0;
    }
    
    // Caso base: un solo elemento, no hay sobrescritura
    if (inf == sup) {
        cout << indent() << "  inf == sup -> return 0 (un solo elemento)" << endl;
        nivel--;
        return 0;
    }
    
    // Caso base: cuando quedan dos elementos con ruptura
    if (sup - inf == 1) {
        cout << indent() << "  inf + 1 == sup -> return " << sup 
             << " (ruptura encontrada)" << endl;
        nivel--;
        return sup;
    }
    
    int m = (inf + sup) / 2;
    cout << indent() << "  m = " << m << ", v[m] = " << v[m] << endl;
    
    int resultado;
    // Buscar la ruptura (donde v[i] > v[i+1])
    if (v[m] > v[sup]) {
        // La ruptura esta a la derecha
        cout << indent() << "  v[m] > v[sup] -> buscar a la DERECHA" << endl;
        resultado = sobrescritos(v, m, sup);
    } else {
        // La ruptura esta a la izquierda
        cout << indent() << "  v[m] <= v[sup] -> buscar a la IZQUIERDA" << endl;
        resultado = sobrescritos(v, inf, m);
    }
    
    cout << indent() << "<- retorna " << resultado << endl;
    nivel--;
    return resultado;
}

int main() {
    // Caso 1: Vector con ruptura en medio
    vector<int> v1 = {18, 21, 32, 12, 15, 16};
    cout << "===============================================" << endl;
    cout << "Vector: {18, 21, 32, 12, 15, 16}" << endl;
    cout << "Indices: 0   1   2   3   4   5" << endl;
    cout << "===============================================" << endl;
    int resultado = sobrescritos(v1, 0, v1.size() - 1);
    cout << "\nRESULTADO FINAL: " << resultado << " elementos sobrescritos\n" << endl;
    
    // Caso 2: Vector completamente ordenado
    vector<int> v2 = {1, 2, 3, 4, 5, 6};
    cout << "===============================================" << endl;
    cout << "Vector: {1, 2, 3, 4, 5, 6}" << endl;
    cout << "===============================================" << endl;
    resultado = sobrescritos(v2, 0, v2.size() - 1);
    cout << "\nRESULTADO FINAL: " << resultado << " elementos sobrescritos\n" << endl;

    return 0;
}
