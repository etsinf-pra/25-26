#include <iostream>

using namespace std;

int calatan(int n, int M[]) {
    if(M[n] > 0) 
        return M[n];
    if (n <= 1) 
        M[n] = 1;
    else {
        M[n] = 0;
        for (int i = 0; i < n; i++) 
            M[n]  += calatan(i,M) * calatan(n - i - 1,M);
    }
    return M[n];
}

int main(void){
    int M[10] = {0};
    
    for (int i = 0; i < 10; i++) 
        cout << "catalan(" << i << ") = " <<  calatan(i, M) << endl;
    return 0;
}


