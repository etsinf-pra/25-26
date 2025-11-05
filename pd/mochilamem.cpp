#include <iostream>
#define max(a, b) (a > b ? a : b)   

using namespace std;

int w[4] = {2, 1, 3, 2};
int v[4] = {10, 12, 20, 15};
int F[4][5]; // el lugar de pasarlo, uso una variable global

int mochila(int item, int capacidad) {
    if (item < 0 || capacidad == 0) {
        return 0;
    }
    if (w[item] > capacidad) 
        F[item][capacidad] = mochila(item - 1, capacidad);
    else
        F[item][capacidad] = max(mochila(item - 1, capacidad), 
                v[item] + mochila(item - 1, capacidad - w[item]));
    return F[item][capacidad];
}


int main(void) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 5; j++)
            F[i][j] = 0;
    }
    cout << mochila(4, 5) << endl;
    // La solución no queda exactamente como en clase
    // - no necesita terminar todas las recursiones,
    //   por eso quedan elementos a cero
    // - algunos elementos no son óptimos (ej, valor de 10 que puede ser 12)
    // - la matriz queda al revés
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 5; j++)
            cout << F[i][j] << " ";
        cout << endl; 
    }
    return 0;
}