/*
problema del movimientmo del caballo
*/


#include <iostream>
#include <vector> 
using namespace std;

// tamaño del tablero
#define SIZE 8

int movimientos[8][2] = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};


inline bool inside(int i, int j) {
    return i >= 0 && i < SIZE && j >= 0 && j < SIZE;
}


void print(vector<vector<int> > &tablero) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << tablero[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void caballo(int i, int j, int mov, vector<vector<int> > &tablero) {
    tablero[i][j] = mov;
    //print(tablero);
    if (mov == SIZE*SIZE) 
        return;
    for (int k = 0; k < 8; k++) {
        int ni = i + movimientos[k][0];
        int nj = j + movimientos[k][1];
        if (inside(ni, nj) && tablero[ni][nj] == 0) {
            caballo(ni, nj, mov + 1, tablero);
        }
    }
    tablero[i][j] = 0;
    //cout << "*** Camino inválido. backtrack *** " << endl << endl;
}


int main() {
    vector<vector<int> > tablero(SIZE, vector<int>(SIZE, 0));
    caballo(0, 0, 1, tablero);
    print(tablero);
    return 0;
}