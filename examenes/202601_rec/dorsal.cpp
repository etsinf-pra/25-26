/*
problema 2
Se utiliza un árbol binario de búsqueda para registrar el orden
de llegada de quienes participan en la maratón de Valencia. En el árbol
se inserta el número de dorsal. Por ejemplo, para la secuencia de llegada
{5382, 1247, 7821, 3056, 2199}
(a) Escribe el pseudocódigo de un algoritmo recursivo que inserta un nuevo
dorsal en el árbol (solo uno, no la lista completa).
(b) Escribe el pseudocódigo de un algoritmo recursivo que obtiene el nú-
mero de dorsal más bajo que ha entrado en meta, o -1 si el dorsal no
existe. En el ejemplo, el algoritmo devolverá 1247
*/

// No resolver todavía. Aquí irá la implementación en C++ más adelante.

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Función (a): insertar recursiva según el pseudocódigo
void insertar(Node*& root, int dorsal) {
    if (root == nullptr) {
        root = new Node(dorsal); // creaNodo(dorsal)
        return;
    }
    if (dorsal < root->val) {
        insertar(root->left, dorsal);
    } else {
        insertar(root->right, dorsal);
    }
}

// Función auxiliar para imprimir inorder (prueba)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Funcion (b) : minimo recursiva
int minimo(Node* root) {
    if (root->left == nullptr)
        return root->val;
    return minimo(root->left);
}

int main() {
    // Ejemplo del enunciado
    Node* root = nullptr;
    int arrivals[] = {5382, 1247, 7821, 3056, 2199};
    for (int v : arrivals) insertar(root, v);

    // Mostrar recorrido
    cout << "Preorder (llegada): ";
    preorder(root);
    cout << "\n";  
    
    cout << "Inorder (ordenado): ";
    inorder(root);
    cout << "\n";

    cout << "Minimo: " << minimo(root) << " (esperado: 1247)" << endl;

 

    return 0;
}
