/*
    Ejemplo para ver el orden de ejecución 
    de las llamadas recursivas
*/
#include <iostream>
/*
    Uso una variable global para identar n espacios
    cada llamada recursiva.
    - la incremento al entrar en cada llamada
    - la decremento justo antes de salir
    Por defecto identa cada llamada un espacio. Para que sea más visible,
    uso una cte. para que idente 3 espacios cada vez
*/
#define TABSIZE 3
int ident = 0;

int fibonacci(int n) {
    /*
        Imprimo el nombre de la función y el valor de n en cada llamada.
        - %*s imprime una cadena en los espacios indicados en el 1er parámetro
        - TABSIZE*ident es el número de espacios. 
        - incremento ident para que las siguientes llamadas se tabulen una posición
        - "" es la cadena (vacía) que imprimo delante de "Fib(n)".y que ajusta los espacios
        - el resto es el formato habitual de printf
    */
    printf("%*sFib(%d)\n", TABSIZE*ident++, "", n);
    /*
        Planteo la recursión igual, pero en lugar de hacer directamente return
        lo guardo en una variable 
        para poder decrementar el ident antes de salir
    */
    int fib; 
    if (n <= 1)
        fib = n;
    else
        fib = fibonacci(n-1) + fibonacci(n-2);
    /*
        Decremento el ident para que el resto de llamadas
        estén a su mismo nivel
    */
    ident--;
    return fib;
}


int main(void) {
    int fib = fibonacci(5);
    /* 
        Uso una variable porque si no imprimiría la secuencia
        de llamadas recursivas antes del resultado
    */
    std::cout << "Fibonacci(5) = " << fib << std::endl;
    return 0;
}