/* 
    búsqueda del mínimo en un vector
    versión recursiva estrategia tipo divide y vencerás
    caso base: si el tamaño del vector es 1, devolver el único elemento
    dividir: dividir el vector en dos mitades
    conquistar: encontrar el mínimo en cada mitad y devolver el menor de los dos
*/

#include <iostream>
#include <vector>

int minimo(const std::vector<int>& v, size_t ini, size_t fin) {
    if (ini == fin) {
        return v[ini];
    }
    int mid = ini + (fin - ini) / 2;
    return std::min(minimo(v, ini, mid), minimo(v, mid + 1, fin));
}

int main() {
    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    std::cout << "El mínimo es: " << minimo(v, 0, v.size() - 1) << std::endl;
    return 0;
}