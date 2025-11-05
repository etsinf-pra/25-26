/*
problema de las 8 reinas
*/


#include <iostream>
#include <cstdlib>

using namespace std;

bool segura(int tablero[], int fila, int columna) {
    for(int i = 0; i < fila; i++) {
        // si hay otra reina en la misma columna
        if(tablero[i] == columna)
            return false;
        // si hay otra reina en la misma diagonal
        // ej {4,0,3} ¿fila 2, columna 1 es segura?
        // abs(4 - 1) == abs(0 - 2) -> 3 == 2 -> false
        // abs(0 - 1) == abs(1 - 2) -> 1 == 1 -> true
        // abs(3 - 1) == abs(2 - 2) -> 2 == 0 -> false
        if(abs(tablero[i] - columna) == abs(i - fila))
            return false;
    }
    return true;
}


bool reinas(int tablero[], int fila) {
    if(fila == 8)
        return true;
    for(int columna = 0; columna < 8; columna++) {
        if(segura(tablero, fila, columna)) {
            tablero[fila] = columna;
            if(reinas(tablero, fila + 1))
                return true; 
            tablero[fila] = -1;
        }
    }
    return false;
}

void print(int tablero[]) {
    cout << "Tablero: ";
    for(int i = 0; i < 8; i++)
        cout << tablero[i] << " ";
    cout << endl;

    for (int i = 0; i < 8; i++, cout << endl){
        for(int j = 0; j < 8; j++){
            if(tablero[i] == j)
                cout << "R ";
            else
                cout << ". ";
        }
    }
}


int main() {
    int tablero[8] = {-1,-1,-1,-1,-1,-1,-1,-1};

    //coloca la primera reina al azar
    srand(time(NULL));
    tablero[0] = rand() % 8;
    reinas(tablero, 1);

    print(tablero);
    return 0;
}