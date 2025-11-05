/*
Un vector circular de tamaño N se rellena de forma ascendente, 
sobrescribiendo los elementos antiguos cuando se llena. Escribe el
pseudocódigo de una función que devuelva cuántos elementos se han 
sobrescrito (sin tener en cuenta vueltas completas).

Por ejemplo, en el vector V = [18, 21, 32, 12, 15, 16] se han sobrescrito 3 elementos. 
Utiliza una estrategia de divide y vencerás.
*/

#include <iostream>
#include <vector>
using namespace std;

int sobrescritos(const vector<int> &v, int inf, int sup) {
     // Caso base: un solo elemento, no hay sobrescritura
    if (inf == sup)
        return 0;
    // Caso base: cuando quedan dos elementos con ruptura
    if (inf + 1 == sup)
        return sup;
    
    int m = (inf + sup) / 2;
    // Buscar la ruptura 
    if (v[inf] < v[sup])
       // Si el segmento está ordenado ascendentemente, no hay ruptura aquí
        return 0;
    else if (v[m] > v[sup])
        // La ruptura está a la derecha
        return sobrescritos(v, m, sup);
    else
        // La ruptura está a la izquierda
        return sobrescritos(v, inf, m);
}


int main() {
    // Caso 1: Vector del ejemplo
    vector<int> v1 = {18, 21, 32, 12, 15, 16};
    cout << "Vector: {18, 21, 32, 12, 15, 16}" << endl;
    cout << "Elementos sobrescritos: " << sobrescritos(v1, 0, v1.size() - 1) << " (esperado: 3)\n" << endl;
    
    // Caso 2: Sin sobrescritura
    vector<int> v2 = {1, 2, 3, 4, 5, 6};
    cout << "Vector: {1, 2, 3, 4, 5, 6}" << endl;
    cout << "Elementos sobrescritos: " << sobrescritos(v2, 0, v2.size() - 1) << " (esperado: 0)\n" << endl;
    
    // Caso 3: Sobrescritura al principio
    vector<int> v3 = {50, 1, 2, 3, 4, 5};
    cout << "Vector: {50, 1, 2, 3, 4, 5}" << endl;
    cout << "Elementos sobrescritos: " << sobrescritos(v3, 0, v3.size() - 1) << " (esperado: 1)\n" << endl;
    
    // Caso 4: Sobrescritura cerca del final
    vector<int> v4 = {10, 20, 30, 40, 50, 5, 8};
    cout << "Vector: {10, 20, 30, 40, 50, 5, 8}" << endl;
    cout << "Elementos sobrescritos: " << sobrescritos(v4, 0, v4.size() - 1) << " (esperado: 5)\n" << endl;
     
    // Caso 5: Solo un elemento sobrescrito
    vector<int> v5 = {99, 1};
    cout << "Vector: {99, 1}" << endl;
    cout << "Elementos sobrescritos: " << sobrescritos(v5, 0, v5.size() - 1) << " (esperado: 1)\n" << endl;

    // Caso 6: Vector de un elemento
    vector<int> v6 = {1};
    cout << "Vector: {1}" << endl;
    cout << "Elementos sobrescritos: " << sobrescritos(v6, 0, v6.size() - 1) << " (esperado: 0)\n" << endl;

    return 0;
}