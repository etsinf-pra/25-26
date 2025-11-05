#include <iostream>
#include <stdlib.h>
#include <time.h>

#define N 10
#define min(a,b) ((a) < (b) ? (a) : (b))
using namespace std; 

int jump(int a[], int cur, int end){ 
    if (cur == end)
        return 0;
    int saltos = INT_MAX;
    for(int i = 1; i <= a[cur]; i++){
        if (cur + i <= end)
            saltos = min(saltos, 1 + jump(a, cur + i, end));
    }
    return saltos;
}


int main(void) {
    int a[N];

    srand(time(NULL));
    for(int i = 0; i < N; i++){
        a[i] = rand() % 4 + 1;
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "saltos = " << jump(a, 0, N-1) << endl;
    return 0;
}