/*
calculo de la altura de un arbol binario
*/

#include <iostream>
#include <cstdlib>

using namespace std;

struct node{
    int key;
    node *left;
    node *right;
};

inline int max(int a, int b){ return a > b ? a : b;} 

void insert(int x, node *&root) {
    if(root == NULL) {
        root = new node;
        root->key = x;
        root->left = NULL;
        root->right = NULL;
        return;
    }
    if(x < root->key)
        insert(x, root->left);
    else
        insert(x, root->right);
}

void print(node *root, int level) {
    if(root == NULL)
        return;
    cout << "|" << string(level, '.') << root->key << endl;
    print(root->left, level + 1);
    print(root->right, level + 1);
}


void generate_tree(node *&root, int n) {
    for(int i = 0; i < n; i++)
        insert(rand() % 100, root);    
}

// esta es la función para la pregunta del parcial
int peso(node *root) {
    if(root == NULL)
        return 0;
    int peso_izq = peso(root->left);
    int peso_der = peso(root->right);
    return peso_izq + peso_der + 1;
}


int main() {
    node *root = NULL;

    generate_tree(root, 25);
    print(root, 0);
    cout << endl << "Peso: " << peso(root) << endl;
    return 0;
}
