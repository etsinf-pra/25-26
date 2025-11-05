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
    print(root->left, level + 1);
    cout << root->key << "(" << level << ") ";
    print(root->right, level + 1);
}


void generate_tree(node *&root, int n) {
    for(int i = 0; i < n; i++)
        insert(rand() % 100, root);    
}

// esta es la función para la pregunta del parcial
int altura  = 0;
int high(node *root) {
    if(root == NULL){
        printf("leaf -> altura: %d\n ", altura);
        return 0;
} 
    else{
        printf("high(%d) -> altura: %d\n ", root->key, altura);
        altura = max(high(root->right), high(root->left));
        altura = altura + 1;

    } 
}


int main() {
    node *root = NULL;

    generate_tree(root, 10);
    print(root, 1);
    cout << endl << "Altura: " << high(root) << endl;
    return 0;
}
