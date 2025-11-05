/*
suma el valor de todos los nodos de un árbol
*/

#include <iostream>
#include <iomanip>

using namespace std;

struct node{
    int value;
    node *left;
    node *right;
};


void insert(int x, node *&root) {
    if(root == NULL) {
        root = new node;
        root->value = x;
        root->left = NULL;
        root->right = NULL;
        return;
    }
    if(x < root->value)
        insert(x, root->left);
    else
        insert(x, root->right);
}

void print(node *root, int level) {
    if(root == NULL)
        return;
    print(root->left, level + 1);
    cout << setw(level) << root->value << endl; 
    print(root->right, level + 1);
}


void generate_tree(node *&root, int n) {
    for(int i = 0; i < n; i++)
        insert(rand() % 100, root);    
}

// esta es la función para la pregunta del parcial
int suma(node *root) {
    if(root == NULL)
        return 0;
    root->value += suma(root->right);
    root->value += suma(root->left);
    return root->value;
}


int main() {
    node *root = NULL;

    generate_tree(root, 10);
    print(root, 1);
    suma(root);
    cout << endl << "Suma: " << root->value << endl;
    print(root, 1);
    return 0;
}
