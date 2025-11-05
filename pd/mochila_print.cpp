#include <iostream>
#define max(a, b) (a > b ? a : b)   
#define NITEMS 4

using namespace std;

int w[NITEMS] = {2, 1, 3, 2};
int v[NITEMS] = {10, 12, 20, 15};
int ident = 0;

int mochila(int item, int capacidad) {
    int res;
    printf("%*smochila(%d, %d)\n", 2*ident++, " ", item, capacidad);
    if (item < 0 || capacidad == 0)
        res = 0;
    else if (w[item] > capacidad) 
        res =  mochila(item - 1, capacidad);
    else res = max(mochila(item - 1, capacidad), 
                v[item] + mochila(item - 1, capacidad - w[item]));
    ident--;
    return res;
}


int main(void) {
    cout << mochila(NITEMS-1, 5) << endl;
    return 0;
}