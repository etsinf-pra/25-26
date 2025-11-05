#include <iostream>
#include <vector>

using namespace std;


int rodcut(int price[], int L, vector<int>&M) {
    // price es el vector con los precios de los cortes
    // L es la longitud actual a cortar
    // M[L] es el mejor precio posible para un tubo de longitud L 
  
    // corte de recursión por la función de memoria.
    if (M[L] >= 0) return M[L];

    // caso base (tubo de longitud 0).
    if (L == 0) return 0;

    // recursion:
    M[L] = -1;
    // todas los tamaños posibles de 1 a L
    for (int i = 1; i <= L; i++) 
        // la llamada recursiva se usa para ver cómo se puede cortar el resto
        // una vez quehemos quitado un trozo de longitud i
        // se queda con la mejor división (la que maximiza el precio)
        M[L] = max(M[L], price[i] + 
                   rodcut(price, L - i, M));
 
    return M[L];
}

// Este programa solo imprime el mejor precio, no el corte
// opcional: piensa cómo almacenar el mejor corte posible
int main() {
    int price[] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int size = sizeof(price) / sizeof(price[0]);
    // crea la función de memoria inicializada a -1
    vector<int> M(size, -1);
    // el vector tiene un elemento de más para que los precios estén 
    // en el tamaño del tubo y no haya que sumar 1 cada vez para acceder
    cout << rodcut(price, size-1, M) << endl;
    return 0;
}
