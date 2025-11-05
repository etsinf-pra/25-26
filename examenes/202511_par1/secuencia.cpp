/*
Escribe el pseudocódigo de una función que, dada una matriz
de caracteres de tamaño N x M, devuelva la longitud de la cadena más
larga de caracteres consecutivos moviéndose a uno de sus cuatro vecinos.
Ejemplo:
G I C L W
F E D O P
M D C B A
F E D E Z
El camino que empieza en C (2,2) tiene longitud 5: C(2,2), D(2,1), E(1,1),
F(0,1), G(0,0). No tiene por qué ser único
*/

#include <iostream>
#include <vector>
using namespace std;

// Sobrecarga del operador << para vector<vector<int>>
ostream& operator<<(ostream& os, const vector<vector<int>>& M) {
    for (size_t i = 0; i < M.size(); i++) {
        for (size_t j = 0; j < M[i].size(); j++) {
            if (M[i][j] == -1)
                os << "- ";
            else
                os << M[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

int secuencia(const vector<vector<char>> &matrix, vector<vector<int>> &M, int x, int y, char currentChar) {
    int nrow = matrix.size();
    int ncol = matrix[0].size();
    // caso base 1: celda no válida (fuera de límites o carácter no coincide)
    if (x < 0 || x >= nrow || y < 0 || y >= ncol || matrix[x][y] != currentChar)
        return 0;
    // Mejor camino conocido (memoización)
    // No se puede hacer antes del caso base porque podría acceder a una celda inválida
    if (M[x][y] != -1)
        return M[x][y];

    int maxLength = 0;   
    char nextChar = currentChar + 1;
    // Explorar los cuatro vecinos buscando el siguiente carácter consecutivo
    maxLength = max(maxLength, 1 + secuencia(matrix, M, x + 1, y, nextChar));
    maxLength = max(maxLength, 1 + secuencia(matrix, M, x - 1, y, nextChar));
    maxLength = max(maxLength, 1 + secuencia(matrix, M, x, y + 1, nextChar));
    maxLength = max(maxLength, 1 + secuencia(matrix, M, x, y - 1, nextChar));
    // variante con bucle
    // dx = {1, -1, 0, 0};
    // dy = {0, 0, 1, -1};
    // for (int dir = 0; dir < 4; dir++) {
    //     int newX = x + dx[dir];
    //     int newY = y + dy[dir];
    //     maxLength = max(maxLength, 1 + secuencia(matrix, M,

    M[x][y] = maxLength;
    return maxLength;   
}

int main() {
    vector<vector<char>> matrix = {
        {'G', 'I', 'C', 'L', 'W'},
        {'F', 'E', 'D', 'O', 'P'},
        {'M', 'D', 'C', 'B', 'A'},
        {'F', 'E', 'D', 'E', 'Z'}
    };

    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> M(n, vector<int>(m, -1));
    
    int length = secuencia(matrix, M, 2, 2, 'C'); // Iniciar desde C
    cout << "Longitud de la cadena más larga de caracteres consecutivos: " << length << endl;
    
    // Imprimir la tabla de memoización
    cout << "\nMatriz de caracteres:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nTabla M (- = no visitado):" << endl;
    cout << M;
    
    return 0;
}   