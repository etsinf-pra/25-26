#include <iostream>
#include <stdlib.h>
#include <time.h>

#define min(a,b) ((a) < (b) ? (a) : (b))    
#define ROW 5  
#define COL 8
using namespace std;

int minpath(int coste[][COL], int row, int col, int M[][COL]){
    if (row < 0 || col < 0)
        return INT_MAX;
    if(M[row][col] != -1)
        return M[row][col];
    if (row == 0 && col == 0)
        M[row][col] =  coste[0][0];
    else
        M[row][col] = coste[row][col] + min(minpath(coste, row - 1, col, M), minpath(coste, row, col - 1, M));
    return M[row][col];
}


void show_path(int coste [][COL], int M[][COL]){
    int i = 0, j = 0;
    while(i < ROW-1 || j < COL-1){
        cout << "(" << i << "," << j << ") [" << coste[i][j] << "] -> ";
        // Se selecciona el menor de los vecinos de la derecha y de abajo
        if(i < ROW-1 && M[i+1][j] < M[i][j+1])
            i++;
        else if (j < COL-1)
            j++;
    }
    cout << "(" << i << "," << j << ") [" << coste[i][j] << "]" << endl;
}


int main(void){
    int coste[ROW][COL], M[ROW][COL] ;

    srand(time(NULL));
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            coste[i][j] = rand() % 9 + 1;
            M[i][j] = -1;
            cout << coste[i][j] << " ";
        }
        cout << endl;
    }
    cout << "coste = " <<  minpath(coste, ROW-1, COL-1, M) << endl;
    // Esto no lo pide el ejercicio, pero lo pongo para ver la matriz M
    // y el camino que se ha tomado
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
    show_path(coste, M);
    return 0;
}


