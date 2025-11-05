/*
calculo de la altura de un arbol binario
*/

#include <iostream>
#include <ctime>
#include <random>

using namespace std;

struct node{
    string name;
    int size;
    node *content;
    node *next;
    node(string n) : name(n), size(0), content(NULL), next(NULL) {}
    node(string n, int s) : name(n), size(s), content(NULL), next(NULL) {}
    node(string n, node *d) : name(n), size(0), content(NULL), next(d) {}
    bool operator<(const node &n) const { return name < n.name; }
};


string gen_name(int len) {
    const string chars = "abcdefghijklmnopqrstuvwxyz";
    // create a random number generator
    random_device rd;
    mt19937 gen(rd());
    // unifor distribution to select chars
    uniform_int_distribution<> unif(0, chars.size() - 1);
    // generate the random string of len characters
    string str;
    for (int i = 0; i < len; ++i) 
        str += chars[unif(gen)];
    return str;
}


void insert(string name, node *&parent) {
    if(parent == NULL) {
        // inserta un nodo hoja (fichero)
        parent = new node(name, rand() % 1000);
        return;
    }
    // parent es un directorio (le borra el tamaño)
    parent->size = 0;
    if(name < parent->name)
        insert(name, parent->content);
    else
        insert(name, parent->next);
}


void print(node *n, int level = 1) {
    if(n == NULL)
        return;
    cout << string(level, ' ') << n->name << (n->size == 0 ? " [  ]" : "\t " + to_string(n->size) + " KB") << endl;
    print(n->content, level + 1);
    print(n->next, level + 1);
}


void generate_tree(node *&root, int n) {
    // genera un arbol binario con n nodos.
    // las hojas son los ficheros y los nodos intermedios directorios
    for(int i = 0; i < n; i++)
        insert(gen_name(3), root);
}

// esta es la función para la pregunta del parcial
// obtiene la ocupación del disco (du)
int du(node *n) {
    if(n == NULL)
        return 0; 
    n->size += du(n->content);
    n->size += du(n->next);
    return n->size;
}


int main() {
    node *root = NULL;
    srand(time(NULL));
    generate_tree(root, 10);
    cout << "Estructura del disco ([ ] es una carpeta):" << endl;
    print(root);
    cout << "Ocupacion del disco:" << endl;
    du(root);
    print(root);
    return 0;
}
