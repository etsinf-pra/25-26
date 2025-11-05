#include <iostream>
#include <stdlib.h>
#include <time.h>

#define N 10
#define min(a,b) ((a) < (b) ? (a) : (b))
using namespace std; 

int jump(int a[], int cur, int end, int M[]){ 
    if (cur == end)
        return 0;
     if (M[cur] > 0)
        return M[cur];
    int num_jump = INT_MAX;
    for(int i = 1; i <= a[cur]; i++){
        if (cur + i <= end)
            num_jump  = min(num_jump , 1 + jump(a, cur + i, end, M));
    }
    M[cur] = num_jump ;
    return M[cur];
}

void show_path(int a[], int M[]){
    // Recupera el camino óptimo a partir de los valores de M
    // M[0] contiene el número mínimo de saltos
    int tile = M[0];
    cout << "0 (" << a[0] << ")";
    for(int i = 1; i < N; i++){
        // El salto es al primer elemento con el valor de M[i] 
        // inmediatamente inferior al actual
        // Ej: si M[i] = 3, el salto es al primer elemento con M[j] = 2
        if (M[i] == tile - 1){
            cout << " -> " << i << " (" << a[i] << ")";
            tile--;
        }
    }
    cout << endl;
}


int main(void) {
    int a[N];
    int M[N] = {0};

    srand(time(NULL));
    for(int i = 0; i < N; i++){
        a[i] = rand() % 4 + 1;
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "saltos = " << jump(a, 0, N-1, M) << endl;

    // Esto no lo pide el problema
    // Muestra la función de memoria y el camino óptimo
    cout << "M = ";
    for(int i = 0; i < N; i++)
        cout << M[i] << " ";    
    cout << endl;
    cout << "path = ";
    show_path(a, M);
    return 0;
}