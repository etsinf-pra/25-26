/*
problema 1
Se dispone de una tabla que utiliza direccionamiento abierto con
doble hashing para resolver colisiones. Cada celda puede estar vacía, ocu-
pada o marcada como borrada. Se pide escribir la pseudocódigo de una
función que implemente una función de búsqueda de un elemento en la
tabla. La función debe devolver la posición del elemento si se encuentra o
-1 si no está en la tabla.
Por ejemplo, con una tabla de capacidad m = 10, hash1(x) = x mód 10 y
hash2(x) = 7 − (x mód 10), se han insertado por orden los elementos 89, 18,
49, 58, 24, 69, 14. La tabla resultante es [69, -, 58, -, 24, -, 49, 14, 18,
89]. buscar(58,T) debe devolver 2 y buscar(16,T) devolverá -1.
*/

#include <iostream>
#include <vector>
using namespace std;

// status: 0 = empty, 1 = occupied, 2 = deleted

class HashTable {
public:
    vector<int> T;

    // constructor por defecto: tabla de tamaño 10
    HashTable() : T(10, 0) {}

    int hash1(int x) const { return x % 10; }
    int hash2(int x) const { return 7 - (x % 7); }

    int buscar(int x) const {
        int h = hash1(x);
        int step = hash2(x);
        int saltos = 0;
        while (saltos < 10 && T[h] != 0) {
            if (T[h] == x) return h;
            h = (h + step) % 10;
            saltos++;
        }
        return -1;
    }

    void insertar(int x) {
        int h = hash1(x);
        int step = hash2(x);
        while (T[h] > 0) 
            h = (h + step) % 10; 
        T[h] = x;
    }

    void print() const {
        cout << "[";
        for (int i = 0; i < T.size(); i++) {
            cout << (T[i] > 0 ? to_string(T[i]) : "-") << " ";
        }
        cout << "]" << endl;
    }
};

int main() {
    // Ejemplo del enunciado
    HashTable ht; // tabla fija de tamaño 10
    // insertar en el mismo orden del enunciado
    vector<int> items = {89, 18, 49, 58, 24, 69, 14};
    for (int v : items) ht.insertar(v);
    ht.print();

    int pos = ht.buscar(58);
    cout << "buscar(58) = " << pos << " (esperado: 3)" << endl; 
    pos = ht.buscar(16);
    cout << "buscar(16) = " << pos << " (esperado: -1)" << endl; 
    return 0;
}
