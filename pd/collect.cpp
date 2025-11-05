#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
#define ROW 6
#define COL 5

int collect(int coin[ROW][COL], int i, int j)
{
    //si he llegado al origen, termino
    if (i == 0 && j == 0)
        return coin[i][j];
    //si estoy en la primera fila, solo puedo ir a la izquierda
    if (i == 0)
        return coin[i][j] + collect(coin, i, j - 1);
    //si estoy en la primera columna, solo puedo ir arriba
    if (j == 0)
        return coin[i][j] + collect(coin, i - 1, j);
    // caso general: la mejor opción entre ir arriba o a la izquierda
    return coin[i][j] + max(collect(coin, i - 1, j), collect(coin, i, j - 1));
}

int main(){
    int coin[ROW][COL];

    // comenta srand si quieres repetir el mismo ejemplo para validarlo
    srand(time(NULL));
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            /* 
                generación al azar de monedas
               modifica el 0.3 para cambiar la densidad de monedas
               cuanto más cerca de 1, más monedas
            */
            coin[i][j] = rand() / (double)RAND_MAX < 0.3 ? 1 : 0;
            cout << coin[i][j] << " ";
        }
        cout << endl;
    }
    /*
        Indicamos la celda destino
        Eso me permite construir el camino a cualquier sitio
        Reconstruyo el caminmo de atras hacia adelante, hasta el (0,0)
    */
    cout << collect(coin, ROW-1, COL-1) << endl;
    return 0;
}