#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std; 

int peak(int a[], int inf, int sup){ 
    int mid = (inf + sup) / 2;
    if (mid == inf || mid == sup || (a[mid] >= a[mid - 1] && a[mid] >= a[mid + 1]))
        return a[mid];
    else if (a[mid] < a[mid - 1])
        return peak(a, inf, mid - 1);
    else
        return peak(a, mid + 1, sup);
}


int main(void) {
    int a[10];

    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        a[i] = rand() % 100;
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "peak = " << peak(a, 0, 9) << endl;
    return 0;
}