#include <iostream>
#include <stdlib.h>
#include <time.h>

#define N 10
using namespace std; 

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}   


void print(int a[]) {
    for (int i = 0; i <  N; i++){
        cout << a[i] << " ";    
    }
    cout << endl;
}


void mixer(int a[], int inf, int sup) { 
    cout << "mixer(" << inf << ", " << sup << ")\n";
    print(a);
    if (inf > sup || sup - inf <= 1) 
        return;

    int mid = (inf + sup) / 2;
    int i = (inf + mid) / 2 + 1;
    int j = mid + 1;
    while (i <= mid) 
        swap(a[i++], a[j++]);
    cout << "swapped: ";
    print(a);
    mixer(a, inf, mid);
    mixer(a, mid + 1, sup);
}


int main(void) {
    int a[N] = {[0 ... N/2-1] = 1, [N/2 ... N-1] = 2};

    print(a);
    cout << "begining mixer...\n";
    mixer(a, 0, N-1);
    cout << "...end mixer\n";
    print(a);

    return 0;
}