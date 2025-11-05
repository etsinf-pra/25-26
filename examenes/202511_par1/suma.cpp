/*
    Escribe el pseudocódigo de una función que sume los elementos
    de un vector utilizando una estrategia de divide y vencerás.
*/

#include <iostream>
#include <vector>
using namespace std;

int suma_vector(const vector<int> &v, int inf, int sup) {
    if (inf > sup)
        return 0;
    if (inf == sup)
        return v[inf];
    int m = (inf + sup) / 2;
    return suma_vector(v, inf, m) + suma_vector(v, m + 1, sup);
}
   

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int resultado = suma_vector(v, 0, v.size() - 1);
    cout << "La suma del vector es: " << resultado << endl;
    return 0;
}