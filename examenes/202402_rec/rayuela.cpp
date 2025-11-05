/*
implementation of rayuela hashing
*/

#include <iostream>
#include <ctime>

// compila con la opción -dDEBUG para ver los mensajes de depuració
#define DEBUG  
#define H 3  
#define EMPTY -1


inline int hash(int key) { return key % 10; }


void print(int T[]) {
    std::cout << "T: ";
    for(int i = 0; i < 10; i++)
        if(T[i] == EMPTY) 
            std::cout << "[ ] "; //posicion vacia de la tabla hash
        else
            std::cout << T[i] << " ";
    std::cout << std::endl;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}


// esta es la función para la pregunta del parcial
void insert(int x, int T[]) {
    int h;
#ifdef DEBUG
    std::cout << "inserting " << x << std::endl;
#endif
    h = hash(x);
 #ifdef DEBUG
    std::cout << "hash(" << x << ") = " << h << std::endl;
#endif
    if(T[h] == EMPTY)
        T[h] = x;
    else{
        int j = h;
        while(T[j] != EMPTY){     
#ifdef DEBUG  
            std::cout << "  pos " << j << " occuped by " << T[j] << std::endl;
#endif  
            j = (j + 1) % 10;
        }
        // j <= h + H, pero teniendo en cuenta que la tabla es circular
        if((j - h + 10) % 10 <= H)
            T[j] = x;
        else{
#ifdef DEBUG  
            std::cout << "  pos " << j << " too far away. Moving " << T[h] << std::endl;
#endif
            // busca un elemento que se tenga que mover menos de H posiciones desde j
            // (asumimos que siempre hay uno)
            while(hash(T[h]) > (j+H) % 10)
                h = (h + 1) % 10;
            
#ifdef DEBUG  
            std::cout << "  insert at " << h << ". Moving " << T[h] << std::endl;
#endif
            swap(x, T[h]);
            insert(x, T);
        }
    }
#ifdef DEBUG
    std::cout << "  pos " << h << " selected" << std::endl;
    print(T);
#endif
}




int main() {
    int T[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    // generate random values for the keys
    srand(time(NULL));
    for(int i = 0; i < 7; i++) {
        insert(rand() % 100, T);
    }

    return 0;
}