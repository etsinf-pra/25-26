/* 
    búsqueda del mínimo en un vector
    versión recursiva con recursión final (tail recursion)
    la última instrucción de la funciónes la llamada recursiva
*/

#include <iostream>
#include <vector>

int minimo(const std::vector<int>& v, size_t i = 0, int min = INT_MAX){
    if (i == v.size()-1) {
        return min;
    }
    if (v[i] < min) {
        min = v[i];
    }
    return minimo(v, i + 1, min);
    //return minimo(v, i + 1, std::min(v[i], min)); // otra forma
}

int main() {
    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    std::cout << "El mínimo es: " << minimo(v) << std::endl;
    return 0;
}