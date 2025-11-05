/* 
Los números de Stirling se definen como 
S(n, k) = S(n − 1, k −1) + kS(n − 1, k), 
con S(n, n) = 1 y S(0, k) = S(n, 0) = 0. 
Cuentan el número de formas de dividir un conjunto de n elementos 
en k particiones no vacías.

Por ejemplo, para un conjunto C = {1, 2, 3}, S(3, 2) = 3 son 
las particiones en k = 2 subconjuntos que podemos formar, 
{{1, 2}{3}, {1, 3}{2}, {2, 3}{1}}

Se puede implementar mediante la siguiente función recursiva.
1: function Stirling(n, k)
2: if n = 0 or k = 0 then
3: return 0
4: else if n = k then
5: return 1
6: return Stirling(n − 1, k − 1)+k∗Stirling(n − 1, k)
Modifica la función para que utilice llamadas con memoria siguiendo un
esquema de programación dinámica.
*/

#include <iostream>
#include <vector>
using namespace std;

int stirling(vector<vector<int>> &M, int n, int k) {
    if (M[n][k] != -1) 
        return M[n][k];
    if (n == 0 && k == 0)
        M[n][k] = 1;
    else if (n == 0 || k == 0) 
        M[n][k] = 0;
    else if (n == k) 
        M[n][k] = 1;
    else
        M[n][k] = stirling(M, n - 1, k - 1) + k * stirling(M, n - 1, k);
    return M[n][k];
}

int main() {
 
        // Modo pruebas automáticas
        cout << "=== Casos de prueba de números de Stirling ===\n" << endl;
        
        // Caso ilustrativo con particiones
        cout << "Ejemplo: S(3, 2) con particiones explícitas:" << endl;
        cout << "Conjunto {1, 2, 3} dividido en 2 particiones:" << endl;
        cout << "  1. {{1, 2}, {3}}" << endl;
        cout << "  2. {{1, 3}, {2}}" << endl;
        cout << "  3. {{2, 3}, {1}}" << endl;
        {
            vector<vector<int>> M(4, vector<int>(3, -1));
            cout << "S(3, 2) = " << stirling(M, 3, 2) << "\n" << endl;
        }
        
        cout << "Ejemplo: S(4, 2) con particiones explícitas:" << endl;
        cout << "Conjunto {1, 2, 3, 4} dividido en 2 particiones:" << endl;
        cout << "  1. {{1, 2, 3}, {4}}" << endl;
        cout << "  2. {{1, 2, 4}, {3}}" << endl;
        cout << "  3. {{1, 3, 4}, {2}}" << endl;
        cout << "  4. {{2, 3, 4}, {1}}" << endl;
        cout << "  5. {{1, 2}, {3, 4}}" << endl;
        cout << "  6. {{1, 3}, {2, 4}}" << endl;
        cout << "  7. {{1, 4}, {2, 3}}" << endl;
        {
            vector<vector<int>> M(5, vector<int>(3, -1));
            cout << "S(4, 2) = " << stirling(M, 4, 2) << "\n" << endl;
        }
        
        // Casos base
        {
            vector<vector<int>> M(6, vector<int>(6, -1));
            cout << "Casos base:" << endl;
            cout << "S(0, 0) = " << stirling(M, 0, 0) << " (esperado: 1)" << endl;
            cout << "S(5, 0) = " << stirling(M, 5, 0) << " (esperado: 0)" << endl;
            cout << "S(0, 3) = " << stirling(M, 0, 3) << " (esperado: 0)" << endl;
            cout << "S(4, 4) = " << stirling(M, 4, 4) << " (esperado: 1)" << endl;
            cout << "S(5, 1) = " << stirling(M, 5, 1) << " (esperado: 1)" << endl;
            cout << endl;
        }
        
        // Más casos conocidos
        {
            vector<vector<int>> M(8, vector<int>(8, -1));
            cout << "Casos conocidos:" << endl;
            cout << "S(5, 2) = " << stirling(M, 5, 2) << " (esperado: 15)" << endl;
            cout << "S(5, 3) = " << stirling(M, 5, 3) << " (esperado: 25)" << endl;
            cout << "S(6, 3) = " << stirling(M, 6, 3) << " (esperado: 90)" << endl;
            cout << "S(7, 4) = " << stirling(M, 7, 4) << " (esperado: 350)" << endl;
            cout << endl;
        }
    
    return 0;
}
