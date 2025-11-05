#include <iostream>
using namespace std;

#define min(a,b) ((a) < (b) ? (a) : (b))

#define NCOINS 6
int d[NCOINS] = {1,2,5,10,20,50};
int indent = 0;


int exchange(int tot, int m) {
    if (tot == 0) return 0;
    /*
        si se devuelve INT_MAX, al sumarle 1
        se desborda y se convierte en INT_MIN (negativo)
    */
    else if (tot < 0 || m < 0) return INT_MAX / 2;
    return  min(exchange(tot, m-1), 1 + exchange(tot-d[m], m));
}


int  main(void) {

    int total; 
    cout << "ATENCIÓN: el coste es 2^n. No pongas un número muy grande" << endl;
    cout << "Total: ", cin >> total;

    // 5 es el último índice de d
    cout << exchange(total, NCOINS-1) << endl;    
    return 0;
}