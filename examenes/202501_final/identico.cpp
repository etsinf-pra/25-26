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
    print(root->right, level + 1);}


void generate_tree(node *&root, int n) {
    for(int i = 0; i < n; i++)
        insert(rand() % 100, root);    
}

void copy(node *a1, node *&a2) {
    if(a1 == NULL) {
        a2 = NULL;
        return;
    }
    a2 = new node;
    a2->key = a1->key;
    copy(a1->left, a2->left);
    copy(a1->right, a2->right);
}


// esta es la función para la pregunta del parcial
bool identicos(node *a1, node *a2) {
    if(a1 == NULL && a2 == NULL)
        return true;
    //para evitar que una rama se acabe antes que otra
    if(a1 == NULL || a2 == NULL)
        return false;    
    bool left = identicos(a1->left, a2->left);
    bool right = identicos(a1->right, a2->right);
    return a1->key == a2->key && left && right;
}


int main() {
    node *a1 = NULL, *a2 = NULL;
    generate_tree(a1, 10);
    generate_tree(a2, 10);
    print(a1, 1);
    print(a2, 1);
    cout << endl << "Identicos: " << identicos(a1,a2) << endl;
    node *a3 = NULL;
    copy(a1, a3);
    print(a1, 1);
    print(a3, 1);
    cout << endl << "Identicos: " << identicos(a1,a3) << endl;
    return 0;
}
