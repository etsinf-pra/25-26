/* 
    hash.cpp
    Implementación de las funciones de la tabla hash para un acortador de URL
*/


#include "hash.h"
#include <iostream>
#include <cstring>
using namespace std;

// Función hash simple basada en la suma de los valores ASCII de los caracteres
int HashTable::hash(const std::string& key) {
    unsigned long hashValue = 0;
    for (char ch : key) {
        hashValue += ch;
    }
    return hashValue % tableSize;
}

// Constructor
HashTable::HashTable() {
    for (int i = 0; i < tableSize; ++i) {
        table[i] = nullptr;
    }
}

// Destructor
HashTable::~HashTable() {
    for (int i = 0; i < tableSize; ++i) {
        delete table[i];
    }
}       

// Insertar un par clave-valor en la tabla hash
void HashTable::insert(const std::string& key, const std::string& value)
{
    // Obtiene el índice en la tabla
    int index = hash(key);
    // Busca una posición libre usando sondeo lineal    
    while(table[index] != nullptr) {
        index = (index + 1) % tableSize; // Sondeo lineal
    }
    // Inserta el nuevo nodo (asumimos que siempre se puede)
    table[index] = new HashNode{key, value};
}

// Buscar un valor por su clave en la tabla hash
std::string HashTable::search(const std::string& key) {
    int index = hash(key);
    while (table[index] != nullptr) {
        if (table[index]->key == key) {
            return table[index]->value; // Retorna el valor si la clave coincide
        }
        index = (index + 1) % tableSize; // Sondeo lineal
    }
    return ""; // Retorna cadena vacía si no se encuentra
}   


