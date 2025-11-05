/*
Caso especial para ver cuando v[inf] < v[sup] se alcanza DURANTE recursion
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
         << ") segmento: {";
    for (int i = inf; i <= sup; i++) {
        cout << v[i];
        if (i < sup) cout << ", ";
    }
    cout << "}" << endl;
    
    // Caso base: un solo elemento
    if (inf == sup) {
        cout << indent() << "  inf == sup -> return 0" << endl;
        nivel--;
        return 0;
    }
    
    // Caso base: dos elementos con ruptura
    if (sup - inf == 1) {
        cout << indent() << "  inf + 1 == sup -> return " << sup << endl;
        nivel--;
        return sup;
    }
    
    // Segmento ordenado (SIN ruptura)
    if (v[inf] < v[sup]) {
        cout << indent() << "  v[" << inf << "]=" << v[inf] 
             << " < v[" << sup << "]=" << v[sup] 
             << " -> return 0 (este segmento NO tiene la ruptura)" << endl;
        nivel--;
        return 0;
    }
    
    int m = (inf + sup) / 2;
    cout << indent() << "  m = " << m << ", v[m] = " << v[m] << endl;
    
    int resultado;
    if (v[m] > v[sup]) {
        cout << indent() << "  v[m]=" << v[m] << " > v[sup]=" << v[sup] 
             << " -> la ruptura esta a la DERECHA" << endl;
        resultado = sobrescritos(v, m, sup);
    } else {
        cout << indent() << "  v[m]=" << v[m] << " <= v[sup]=" << v[sup] 
             << " -> la ruptura esta a la IZQUIERDA" << endl;
        resultado = sobrescritos(v, inf, m);
    }
    
    cout << indent() << "<- retorna " << resultado << endl;
    nivel--;
    return resultado;
}

int main() {
    // Vector donde el algoritmo explora la rama DERECHA primero
    // y encuentra un segmento ordenado
    vector<int> v = {40, 50, 10, 20, 30};
    cout << "===============================================" << endl;
    cout << "Vector: {40, 50, 10, 20, 30}" << endl;
    cout << "Indices: 0   1   2   3   4" << endl;
    cout << "Ruptura entre indice 1 y 2 (50 -> 10)" << endl;
    cout << "Segmento [2-4] = {10,20,30} esta ORDENADO" << endl;
    cout << "===============================================\n" << endl;
    int resultado = sobrescritos(v, 0, v.size() - 1);
    cout << "\nRESULTADO FINAL: " << resultado << " elementos sobrescritos\n" << endl;
    
    cout << "\n" << endl;
    cout << "EXPLICACION:" << endl;
    cout << "1. Primera llamada: v[0]=40 >= v[4]=30, hay ruptura" << endl;
    cout << "2. m=2, v[2]=10 <= v[4]=30, busca IZQUIERDA sobrescritos(0,2)" << endl;
    cout << "3. En (0,2): v[0]=40 >= v[2]=10, hay ruptura" << endl;
    cout << "4. m=1, v[1]=50 > v[2]=10, busca DERECHA sobrescritos(1,2)" << endl;
    cout << "5. En (1,2): sup-inf==1, retorna 2" << endl;
    cout << "\nNOTA: La rama derecha inicial (2,4) NO se explora porque" << endl;
    cout << "el algoritmo ya encontro la respuesta en la izquierda." << endl;
    cout << "Pero si la ruptura estuviera en otra posicion, podria" << endl;
    cout << "explorar (2,4) y ahi v[2]=10 < v[4]=30 retornaria 0." << endl;

    return 0;
}
