/*
direccionamiento abierto lineal FIFO
*/

#include <iostream>
#include <cstdlib>

// compila con la opción -dDEBUG para ver los mensajes de depuración

void print(int T[]) {
    std::cout << "T: ";
    for(int i = 0; i < 10; i++)
        std::cout << T[i] << " ";
    std::cout << std::endl;
}

int hash(int key) {
    return key % 10;
}


void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// esta es la función para la pregunta del parcial
void insert(int x, int T[]) {
    int h, temp;
#ifdef DEBUG
    std::cout << "inserting " << x << std::endl;
#endif
    h = hash(x);
    while(T[h] != 0) {
#ifdef DEBUG
        std::cout << " T occuped by " << T[h] << " -> out" << std::endl;
#endif
        swap(x, T[h]);
        h = (h+1) % 10; //para que no se salga de la tabla
    }
    T[h] = x;
#ifdef DEBUG
        std::cout << " pos " << h << " free -> inserting" << std::endl;
        print(T);
#endif
}




int main() {
    int T[10] = {0};

    // generate random values for the keys
    srand(time(NULL));
    for(int i = 0; i < 10; i++) {
        int x = rand() % 99 + 1;
        insert(x, T);
    }
    std::cout << "final table" << std::endl;
    print(T);

    return 0;
}