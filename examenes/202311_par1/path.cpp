#include <iostream>
#include <stdlib.h>
#include <time.h>

#define min(a,b) ((a) < (b) ? (a) : (b))    
#define ROW 3
#define COL 3
using namespace std;

int minpath(int coste[][COL], int row, int col){
    if (row < 0 || col < 0)
        return INT_MAX;
    if (row == 0 && col == 0)
        return coste[0][0];
    return coste[row][col] + min(minpath(coste, row - 1, col), minpath(coste, row, col - 1));
}

int main(void){
    int coste[ROW][COL];

    srand(time(NULL));
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            coste[i][j] = rand() % 9 + 1;
            cout << coste[i][j] << " ";
        }
        cout << endl;
    }
    cout << "coste = " <<  minpath(coste, ROW-1, COL-1) << endl;
    return 0;
}


