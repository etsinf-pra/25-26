#include <iostream>
#define max(a, b) (a > b ? a : b)   
#define NITEMS 4

using namespace std;

int w[NITEMS] = {2, 1, 3, 2};
int v[NITEMS] = {10, 12, 20, 15};

int mochila(int item, int capacidad) {
    if (item < 0 || capacidad == 0)
        return 0;
    if (w[item] > capacidad) 
        return  mochila(item - 1, capacidad);
    return max(mochila(item - 1, capacidad), 
                v[item] + mochila(item - 1, capacidad - w[item]));
}


int main(void) {
    cout << mochila(NITEMS-1, 5) << endl;
    return 0;
}