#include <iostream>
using namespace std; 

int coef(int n, int k){ 
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
    return coef(n - 1, k - 1) + coef(n - 1, k);
}


int main(int argc, char *argv[]) {
    int n, k;

    n = atoi(argv[1]);
    k = atoi(argv[2]); 
    cout << "C(n,k) = " << coef(n,k) << endl;
    return 0;
}