/*
    implementación de una tabla hash para un acortador de URL
*/

#include <string>


class HashTable {
private:
    static const int tableSize = 213; // Tamaño de la tabla hash
    struct HashNode {
        std::string key;   // URL original
        std::string value; // URL acortada
    };
    HashNode* table[tableSize]; // Tabla hash
    int hash(const std::string& key); // Función hash
    int linearProbing(int ncollisions); // Manejo de colisiones por sondeo lineal
    int quadraticProbing(int ncollisions); // Manejo de colisiones por sondeo cuadrático
    int doubleHashing(int ncollisions, const std::string& key); // Manejo de colisiones por doble hashing
public:
    HashTable(); // Constructor
    ~HashTable(); // Destructor
    void insert(const std::string& key, const std::string& value); // Insertar
    std::string search(const std::string& key); // Buscar
    void remove(const std::string& key); // Eliminar
};


