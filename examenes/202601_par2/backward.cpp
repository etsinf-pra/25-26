/*
En el método lineal para el direccionamiento abierto, 
el borrado de elementos de la tabla hash deja huecos. 
Con hashing con retroceso, cuando se borra una celda i, 
se busca en el mismo bloque una celda cuyo valor de hash 
sea anterior o igual a i (es una celda que se ha movido 
por el sondeo lineal), o se encuentra una celda vacía. 
De esta forma, la tabla vuelve a estar compacta y no quedan huecos.

Por ejemplo, con una tabla de capacidad m = 10 y 
hash(x) = x mod 10, se han insertado por orden los elementos 
89, 18, 49, 58, 24, 69, 14. 
La tabla resultante es [49, 58, 69, -, 24, 14, -, -, 18, 89]. 
El resultado de borrar un elemento de esta tabla inicial sería
    • Borrado 49:  [□, 58, 69, -, 24, 14, -, -, 18, 89] ⇒ [58, 69, -, -, 24, 14, -, -, 18, 89]
    • Borrado 18:  [49, 58, 69, -, 24, 14, -, -, □, 89] ⇒ [49, 69, -, -, 24, 14, -, -, 58, 89]
Escribe el pseudocódigo del algoritmo de borrado que implementa este proceso.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class HashTable {
    struct Item {
        int value;
        bool occupied; // para marcar celdas vacias
        Item() : value(0), occupied(false) {}
        operator bool() const { return occupied; }
        Item& operator =(const Item &other) {
            value = other.value;
            occupied = other.occupied;
            return *this;
        }
    };

    vector<Item> table;
    int capacity;
    
    int hash(int key) {
        return key % capacity;
    }
public:
    HashTable(int cap) : capacity(cap) {
        table.resize(capacity);
    }

    // inserción con linear probing
    bool insert(int value) {
        int idx = hash(value);
        while (table[idx].occupied) {
            idx = (idx + 1) % capacity;
        }
        table[idx].value = value;
        table[idx].occupied = true;
        return true;
    }

    // delete con backwards shift
    bool remove(int value) {
        int idx = hash(value);
        // borrar el item
        while (table[idx].value != value) 
            idx = (idx + 1) % capacity;
        table[idx].occupied = false;
        // hacer backwards shift (tapar el hueco)
        int nextIdx = (idx + 1) % capacity;
        while (table[nextIdx].occupied) {
            int origIdx = hash(table[nextIdx].value);
            // si el item en nextIdx debería estar antes que idx:
            // 1. idx < nextIdx < origIdx : la posición que le corresponde está después de nextIdx, por lo que idx está antes de su posición
            // 2. origIdx <= idx < nextIdx  : la posición que le corresponde esta incluso antes del hueco
            // 3. nextIdx < origIdx <= idx  : la posición que le corresponde está después del hueco, pero antes de idx
            // forma comprimida
            // if ((idx - origIdx + capacity) % capacity < (nextIdx - origIdx + capacity) % capacity) {
            if ((idx < nextIdx && nextIdx < origIdx) ||
                (origIdx <= idx && idx < nextIdx) ||
                (nextIdx < origIdx && origIdx <= idx)) {                        // adelantar el item current a hueco
                table[idx] = table[nextIdx];
                table[nextIdx].occupied = false;
                idx = nextIdx;
            }
            nextIdx = (nextIdx + 1) % capacity;
        }
        return true;
    }   

    void print() {
        for (int i = 0; i < capacity; i++) {
            if (table[i].occupied)
                cout  << table[i].value << " ";           
            else
                cout << "- ";
        }
        cout << endl;
    }
};

int main(){
    HashTable ht(10);
    ht.insert(89);
    ht.insert(18);
    ht.insert(49);
    ht.insert(58);
    ht.insert(24);
    ht.insert(69);
    ht.insert(14);
    ht.print();
    cout << "Borrando 49" << endl;
    ht.remove(49);
    ht.print();

    HashTable ht2(10);
    ht2.insert(89);
    ht2.insert(18);
    ht2.insert(49);
    ht2.insert(58);
    ht2.insert(24);
    ht2.insert(69);
    ht2.insert(14);
    cout << "Borrando 18" << endl;
    ht2.remove(18);
    ht2.print();
    return 0;

}