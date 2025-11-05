#include <iostream>
#include <vector>

using namespace std;


int rodcut(int price[], int L) {
    // price es el vector con los precios de los cortes
    // L es la longitud actual a cortar

    // caso base (tubo de longitud 0).
    if (L == 0) return 0;

    // recursion:
    int best = -1;
    // todas los tamaños posibles de 1 a L
    for (int i = 1; i <= L; i++) 
        // la llamada recursiva se usa para ver cómo se puede cortar el resto
        // una vez que hemos quitado un trozo de longitud i
        // se queda con la mejor división (la que maximiza el precio)
        best = max(best, price[i] + 
                   rodcut(price, L - i));
 
    return best;
}

// Este programa solo imprime el mejor precio, no el corte
// Versión sin función de memoria
// opcional: piensa cómo almacenar el mejor corte posible
int main() {
    int price[] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int size = sizeof(price) / sizeof(price[0]);

    // el vector tiene un elemento de más para que los precios estén 
    // en el tamaño del tubo y no haya que sumar 1 cada vez para acceder
    cout << rodcut(price, size-1) << endl;
    return 0;
}
