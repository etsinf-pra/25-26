/* 
    búsqueda del mínimo en un vector
    versión recursiva
*/

#include <iostream>
#include <vector>

int minimo(const std::vector<int>& v, size_t i = 0){
    if (i == v.size()-1) {
        return v[i];
    }
    return std::min(v[i], minimo(v, i + 1));
}

int main() {
    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    std::cout << "El mínimo es: " << minimo(v) << std::endl;
    return 0;
}