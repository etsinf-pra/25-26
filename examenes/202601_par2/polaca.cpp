/*
2.
La notación polaca es una forma alternativa de representar expresiones aritméticas. En ella, se indican primero los operadores y luego los valores. Por ejemplo: 2 + 3 ⇒ +2 3. 
Es una notación que no tiene ambigüedad y no necesita paréntesis. 
(2 + 3) * 5 -> x + 2 3 5 = 25
2 + 3 * 5 -> + 2 x 3 5 = 17
Este tipo de expresiones se pueden almacenar en un árbol binario. Se pide
 a) Escribe el pseudocódigo de una función recursiva que genera el árbol que representa una expresión aritmética en notación polaca. Puedes asumir que la expresión ya está tokenizada en elementos.
 b) Escribe el pseudocódigo de una función recursiva que a partir del árbol escribe la expresión correspondiente en notación convencional, utilizando paréntesis aunque no sean necesarios.
*/

#include <iostream>
#include <vector>
#include <string>   
using namespace std;

struct Node {
    string valor;
    Node* izq;
    Node* der;
    Node(const string& val) : valor(val), izq(nullptr), der(nullptr) {}
};

bool esOperador(const string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

Node* construir(const vector<string>& tokens, int& i) {
    string t = tokens[i++];
    Node* nodo = new Node(t);
    if (esOperador(t)) {
        nodo->izq = construir(tokens, i);
        nodo->der = construir(tokens, i);
    }
    return nodo;
}

void mostrar(Node* nodo) {
    if (!nodo) return;

    if (esOperador(nodo->valor))
        cout << "(";

    mostrar(nodo->izq);
    cout << nodo->valor;
    mostrar(nodo->der);

    if (esOperador(nodo->valor))
        cout << ")";
}


int main() {
    // TODO: construir y recorrer el árbol de una expresión en notación polaca.
    // ejemplo 1: + 2 * 3 5
    vector<string> tokens = {"+", "2", "*", "3", "5"};
    int index = 0;
    Node* raiz = construir(tokens, index);
    mostrar(raiz);
    cout << endl;   
    // ejemplo 2: * + 2 3 5
    tokens = {"*", "+", "2", "3", "5"};
    index = 0;
    raiz = construir(tokens, index);
    mostrar(raiz);
    cout << endl;   
    return 0;
}
