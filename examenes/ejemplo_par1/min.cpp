#include <iostream>
#include <stdlib.h>
using namespace std; 

#define min(a,b) ((a) < (b) ? (a) : (b))


int minvalue(int a[], int inf, int sup){ 
    if (inf == sup) 
        return a[inf];
    int mid = (inf + sup) / 2;
    return min(minvalue(a, inf, mid), minvalue(a, mid + 1, sup));
}


int main(void) {
    int a[10];

    for(int i = 0; i < 10; i++){
        a[i] = rand() % 100;
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "min = " << minvalue(a, 0, 9) << endl;
    return 0;
}