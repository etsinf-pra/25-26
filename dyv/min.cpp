/* 
    búsqueda del mínimo en un vector
*/

#include <iostream>
#include <vector>

int minimo(const std::vector<int>& v) {
    int min = v[0];
    for (size_t i = 1; i < v.size(); ++i) {
        if (v[i] < min) {
            min = v[i];
        }
    }
    return min;
}

int main() {
    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    std::cout << "El mínimo es: " << minimo(v) << std::endl;
    return 0;
}
