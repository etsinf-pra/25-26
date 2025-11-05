/*
implementation of bucket hashing
*/

#include <iostream>
#include <cstdlib>

// compila con la opción -dDEBUG para ver los mensajes de depuración
#define TABLE_SIZE 10
#define NBUCKET 5
#define BUCKET_SIZE 2


void print(int T[], int OV[]) {
    std::cout << "T: ";
    for(int i = 0; i < TABLE_SIZE; i++)
        std::cout << T[i] << " ";
    std::cout << std::endl;

    std::cout << "OV: ";
    for(int i = 0; i < TABLE_SIZE; i++) 
        std::cout << OV[i] << " ";
    std::cout << std::endl;
}

int hash(int key) {
    return key % NBUCKET;
}


// esta es la función para la pregunta del parcial
void insert(int x, int T[], int OV[]) {
    int h, temp;
#ifdef DEBUG
    std::cout << "inserting " << x << std::endl;
#endif
    h = hash(x) * BUCKET_SIZE;
#ifdef DEBUG
    std::cout << "hash(" << x << ") = " << h << std::endl;
#endif
    if(T[h] == 0) {
        T[h] = x;
        return;
    }
#ifdef DEBUG
    std::cout << " T occuped by " << T[h] << std::endl;
#endif
    int j = 1;
    while(T[h+j] > 0 && j < BUCKET_SIZE)
        j++;
    if(j < BUCKET_SIZE){
#ifdef DEBUG
        std::cout << " free. inserting in T" << std::endl;
#endif
        T[h+j] = x;
        return;
    }
#ifdef DEBUG
    std::cout << " bucket full" << std::endl;
#endif
    j = 0;
    while(OV[j] > 0)
        j++;
    OV[j] = x;
#ifdef DEBUG
    std::cout << " inserted in OV" << std::endl;
#endif
}




int main() {
    int T[TABLE_SIZE] = {0};
    int OV[TABLE_SIZE] = {0};

    // generate random values for the keys
    srand(time(NULL));
    for(int i = 0; i < 10; i++) {
        int x = rand() % 100;
        insert(x, T, OV);
#ifdef DEBUG
        print(T, OV);
#endif
    }
    std::cout << "final tables" << std::endl;
    print(T, OV);

    return 0;
}