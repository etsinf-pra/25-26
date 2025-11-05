#include <iostream>

using namespace std; 

int coef(int n, int k, int **M){
    if(M[n][k] > 0)
        return M[n][k];
    if (k > n)
        return 0;
    if (k == 0 || k == n){
        M[n][k] = 1;
        return 1;   
    }
    if(M[n][k] == -1)
        M[n][k] = coef(n - 1, k - 1, M) + coef(n - 1, k, M);   
    return M[n][k];
}


int main(int argc, char *argv[]) {
    int n, k;

    n = atoi(argv[1]);
    k = atoi(argv[2]); 
    cout << "n = " << n << endl << "k = " << k << endl; 
    
    int **M = new int*[n + 1];
    for(int i = 0; i <= n; i++){
        M[i] = new int[k + 1];
        for(int j = 0; j <= k; j++)
            M[i][j] = -1;
    }
    
    cout << "C(n,k) = " << coef(n,k,M) << endl;

    for(int i = 0; i <= n; i++)
        delete [] M[i]; 
    delete [] M;
    return 0;
}