#include <iostream>
#include <vector>
using namespace std;

bool suma(vector<vector<int> > &M, vector<int> &A, int n, int k)
{
	// si k llega a cero, se puede formar la suma
	if(k == 0){
		return true;
	}
	// si no quedan elementos o k es negativo, no hay suma
	if (n < 0 || k < 0) 
		return false;
	// no se puede poner antes por si n o k negativos (error de acceso)
	if(M[n][k] != -1)
		return M[n][k]; 
	// opcion 1 se puede sumar si se incluye el elemento actual n, o
	// opcion 2 se puede sumar si no se incluye el elemento actual n
	M[n][k] = suma(M, A, n - 1, k - A[n]) || suma(M, A, n - 1, k);
	return M[n][k];
}



int main()
{
	//Ejemplo
	vector<int> A = { 7, 3, 2, 5, 8 };
	int k = 6;
	int n = A.size();
	// k+1 para que el ultimo valor sea k
	vector<vector<int> > M(n, vector<int>(k+1, -1));

	if (suma(M, A, n - 1, k))
		cout << "Hay una suma igual a " << k << endl;
	
	else 
		cout << "No hay una suma igual a " << k << endl;

	return 0;
}