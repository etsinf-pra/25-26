/*
implementation of cuckoo hashing
*/

#include <iostream>
#include <cstdlib>

// ompila con la opción -dDEBUG para ver los mensajes de depuración
using namespace std;

void print(int T1[], int T2[]) {
    cout << "T1: ";
    for(int i = 0; i < 10; i++)
        cout << T1[i] << " ";
    cout << endl;

    cout << "T2: ";
    for(int i = 0; i < 10; i++) 
        cout << T2[i] << " ";
    cout << endl;
}

int hash1(int key) {
    return key % 10;
}

int hash2(int key) {
    return (key / 10) % 10;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// esta es la función para la pregunta del parcial
void insert(int x, int T1[], int T2[]) {
    int h, temp;
#ifdef DEBUG
    cout << "inserting " << x << endl;
#endif
    while(true) {
        h = hash1(x);
#ifdef DEBUG
        cout << "hash1(" << x << ") = " << h;
#endif
        if(T1[h] == 0) {
            T1[h] = x;
#ifdef DEBUG
            cout << " free. inserting in T1" << endl;
            print(T1, T2);
#endif
            return;
        }
#ifdef DEBUG
        cout << " T1 occuped by " << T1[h] << " -> out" << endl;
#endif
        swap(x, T1[h]);
        h = hash2(x);
#ifdef DEBUG
        cout << "hash2(" << x << ") = " << h;
#endif
        if(T2[h] == 0) {
            T2[h] = x;
#ifdef DEBUG
            cout << " free. inserting in T2" << endl;
            print(T1, T2);
#endif
            return;
        }
#ifdef DEBUG
        cout << " T2 occuped by " << T2[h] << " -> out" << endl;
#endif
        swap(x, T2[h]);
    }
}




int main() {
    int T1[10] = {0};
    int T2[10] = {0};

    // generate random values for the keys
    srand(time(NULL));
    for(int i = 0; i < 10; i++) {
        int x = rand() % 100;
        insert(x, T1, T2);
    }
    cout << "final tables" << endl;
    print(T1, T2);

    return 0;
}