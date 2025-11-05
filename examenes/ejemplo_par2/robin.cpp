/*
implementation of robin hood hashing
*/

#include <iostream>
#include <ctime>

// compila con la opción -dDEBUG para ver los mensajes de depuració
#define DEBUG    

struct entry {
    int val;        // value of the entry
    int jumps;      // number of jumps (for robin hood hashing)
    entry() : val(-1), jumps(99) {}
    entry(int v) : val(v), jumps(0) {}
    bool operator==(const entry &e) {return val == e.val;}
};  

std::ostream& operator<<(std::ostream &os, entry &e) {
    return os << e.val << " (" << e.jumps << ")";
}


inline int hash(int key) { return key % 10; }


void print(entry T[]) {
    std::cout << "T: ";
    for(int i = 0; i < 10; i++)
        if(T[i].val == -1) 
            std::cout << "-- ";
        else
            std::cout << T[i] << " ";
    std::cout << std::endl;
}

void swap(entry &a, entry &b) {
    entry temp(a);
    a = b;
    b = temp;
}


// esta es la función para la pregunta del parcial
void insert(int x, entry T[]) {
    int h, temp;
    entry item(x);
#ifdef DEBUG
    std::cout << "inserting " << x << std::endl;
#endif
    h = hash(x);
 #ifdef DEBUG
    std::cout << "hash(" << x << ") = " << h << std::endl;
#endif   
    while(T[h].val != -1){       
        if(item.jumps > T[h].jumps){
#ifdef DEBUG
            std::cout << "  T occuped by " << T[h] << " -> out" << std::endl;
#endif
            swap(item, T[h]);
        }
        item.jumps++;
        h = (h + 1) % 10;
    }
    
    T[h] = item;
#ifdef DEBUG
    std::cout << "  free. inserting in T" << std::endl;
    print(T);
#endif
}




int main() {
    entry T[10];
    int input[] = {9, 67, 42, 53, 92};
    // generate random values for the keys
    srand(time(NULL));
    for(int i = 0; i < 5; i++) {
        //uncomment for random generation
        //int x = rand() % 100;
        //insert(x, T);
        insert(input[i], T);
    }

    return 0;
}