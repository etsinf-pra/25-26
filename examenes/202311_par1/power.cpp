#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std; 

long int power(int x, int n){ 
    if (n == 1) 
        return x;
    if (n % 2 == 0)
        return power(x, n / 2) * power(x, n / 2);
    else
        return power(x, n / 2) * power(x, n / 2) * x;
}


int main(void) {
    int x, n;

    srand(time(NULL));
    x = rand() % 10;
    n = rand() % 20;
    cout << "power(" << x << "," << n << ") = " << power(x, n) << endl;
    return 0;
}