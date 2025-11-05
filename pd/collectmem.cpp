#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
#define ROW 6
#define COL 5

int collect(int coin[][COL], int i, int j, int M[][COL])
{
    if(M[i][j] > 0)
        return M[i][j];
    if (i == 0 && j == 0)
        M[i][j] = coin[i][j];
    else if (i == 0)
         M[i][j] =  coin[i][j] + collect(coin, i, j - 1, M);
    else if (j == 0)
         M[i][j] =  coin[i][j] + collect(coin, i - 1, j, M);
    else 
        M[i][j] =  coin[i][j] + max(collect(coin, i - 1, j, M), collect(coin, i, j - 1, M));
    return M[i][j];
}

int main(){
    int coin[ROW][COL];
    int M[ROW][COL];

    //srand(time(NULL));
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            M[i][j] = 0;
            coin[i][j] = rand() / (double)RAND_MAX > 0.7 ? 1 : 0;
            cout << coin[i][j] << " ";
        }
        cout << endl;
    }
    cout << collect(coin, ROW-1, COL-1, M) << endl;


for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }   
    return 0;
}