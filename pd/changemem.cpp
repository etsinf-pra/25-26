#include <iostream>
using namespace std;

#define min(a,b) ((a) < (b) ? (a) : (b))
#define NCOINS 6    
int d[NCOINS] = {1,2,5,10,20,50};

int exchange(int tot, int m, int **M) {
    /* si uno de los parametros, tot o m, es < 0 
       no es un índice válido para la matriz M.
       Es lo primero que hay que comprobar */
    if (tot < 0 || m < 0) 
        return INT_MAX / 2;
    if (M[tot][m] != 0) 
        return M[tot][m];
    if (tot == 0) 
        M[tot][m] = 0;
    else    
        /*
            ¿Cómo sé si M es un vector o una matriz?
            - mira las llamadas recursivas
            - si modificas 1 parámetro, basta con un vector
            - si modificas 2 parámetros, necesitas una matriz
            - en este caso cambias tot y m -> matriz
        */
        M[tot][m] = min(exchange(tot, m-1, M), 1 + exchange(tot-d[m], m, M));
    return M[tot][m];
}

int  main(void) {
    int total; 
    cout << "Total: ", cin >> total;
    
    int **M = new int*[total+1];
    for (int i = 0; i <= total; i++) 
        // con () llama al constructor de enteros por defecto, que inicializa a 0
        M[i] = new int[NCOINS]();

    cout << exchange(total, NCOINS-1, M) << endl;   

    for (int i = 0; i <= total; i++) 
        delete [] M[i];
    delete [] M; 
    return 0;
}