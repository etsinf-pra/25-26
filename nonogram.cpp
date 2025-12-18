#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Nonograma {
private:
    int N; // Tamaño del tablero
    vector<vector<int>> solucion;
    vector<vector<int>> tablero_usuario;

public:
    Nonograma() : Nonograma(5) {} // Tamaño por defecto 5x5
    Nonograma(int size);

    void generar_solucion();
    vector<int> calcular_pistas(const vector<int>& linea);
    void imprimir_pistas_columnas();
    void imprimir_tablero(vector<vector<int>>& tab);
    void imprimir_solucion();
    void imprimir_usuario();
    bool pedir_jugada();
    bool comprobar_solucion();

    // TODO: implementar el método de resolución automática
    void resolver(); 
};

// ======================== Implementaciones ========================

Nonograma::Nonograma(int size) {
    N = size;
    solucion = vector<vector<int>>(N, vector<int>(N, 0));
    tablero_usuario = vector<vector<int>>(N, vector<int>(N, 0));
}

void Nonograma::generar_solucion() {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            solucion[i][j] = ((rand() / (double)RAND_MAX) < 0.55) ? 1 : 0; // 60% probabilidad de 1
        }
    }
}

vector<int> Nonograma::calcular_pistas(const vector<int>& linea) {
    vector<int> pistas;
    int count = 0;
    for (int val : linea) {
        if (val == 1) count++;
        else {
            if (count > 0) {
                pistas.push_back(count);
                count = 0;
            }
        }
    }
    if (count > 0) pistas.push_back(count);
    return pistas;
}

void Nonograma::imprimir_pistas_columnas() {
    for (int j = 0; j < N; j++) {
        vector<int> col(N);
        for (int i = 0; i < N; i++) col[i] = solucion[i][j];
        vector<int> pistas_col = calcular_pistas(col);
        cout << "C" << j + 1 << ": ";
        for (int val : pistas_col) cout << val << " ";
        if (j != N - 1) cout << "| ";
    }
    cout << endl;
}

void Nonograma::imprimir_tablero(vector<vector<int>>& tab) {
    imprimir_pistas_columnas();
    for (int i = 0; i < N; i++) {
        // Imprimir pistas de fila
        vector<int> pistas_fila = calcular_pistas(solucion[i]);
        for (int val : pistas_fila) cout << val << " ";
        cout << "\t ";
        // Imprimir fila del tablero del usuario
        for (int j = 0; j < N; j++) {
            cout << (tab[i][j] ? '#' : '.') << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Nonograma::imprimir_solucion() {
    imprimir_tablero(solucion);
}

void Nonograma::imprimir_usuario() {
    imprimir_tablero(tablero_usuario);
}

bool Nonograma::pedir_jugada() {
    int fila, col;
    cout << "Fila: "; cin >> fila;
    cout << "Columna: "; cin >> col;
    // Tablero finalizado
    if (fila == 0 && col == 0) return false;
    // Validar coordenadas
    if (fila < 1 || fila > N || col < 1 || col > N) {
        cout << "Coordenadas fuera de rango. Intenta de nuevo." << endl;
        return true;
    }
    // Alternar el estado de la casilla
    tablero_usuario[fila - 1][col - 1] = (tablero_usuario[fila - 1][col - 1] + 1) % 2;
    return true;
}

bool Nonograma::comprobar_solucion() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (solucion[i][j] != tablero_usuario[i][j]) return false;
    return true;
}

// ======================== Main ========================

int main(int argc, char* argv[]) {
    Nonograma juego;
    if (argc > 1)
        juego = Nonograma(atoi(argv[1]));
    else
        juego = Nonograma();

    // Generamos solución y mostramos pistas
    juego.generar_solucion();

    cout << "Introduce la fila y la columna para marcar una casilla" << endl;
    cout << "Introduce 0 0 para finalizar." << endl;
    cout << "Para borrar, vuelve a introducir la misma casilla." << endl;

    while(true) {
        juego.imprimir_usuario();
        if (!juego.pedir_jugada()) break; // Salir si el usuario introduce 0,0
    }
    // sustituir por el juego automático
    // juego.resolver();
    
    if (juego.comprobar_solucion())
        cout << "¡Felicidades! Has resuelto el nonograma." << endl;
    else{
        cout << "La solución no es correcta. Intenta de nuevo." << endl;
        juego.imprimir_solucion(); // Muestra tablero inicial
    }
    return 0;
}
