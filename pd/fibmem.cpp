/*
    fibonacci usando programación dinámica
*/
#include <iostream>


#define TABSIZE 3
int ident = 0;


int fibonacci(int n, int *M) {
    printf("%*sFib(%d)\n", TABSIZE*ident++, "", n);
    int fib;
    // comprobación con la memoria de número ya calculado
    std::cout << M[n] << std::endl; 
    if (M[n] >= 0 )
        fib = M[n];  
    else if (n <= 1){ 
        fib = n;
        M[n] = fib;
    } 
    else{ 
        fib = fibonacci(n-1,M) + fibonacci(n-2,M);
        M[n] = fib;
    }      
    ident--;
    return fib;
}


int main(void) {
    // M es la función de memoria inicializada a -1
    int M[] = {-1, -1, -1, -1, -1, -1};
    int fib = fibonacci(5,M);
    std::cout << "Fibonacci(5) = " << fib << std::endl;
    return 0;
}