#include <iostream>
using namespace std;

int unos(int A[], int inf, int sup){
    //caso base: todo ceros
    if(A[sup] == 0)
        return 0;
    //caso base: todo unos
    if(A[inf] == 1)
        return sup - inf + 1;
    //caso general
    int mitad = (inf + sup) / 2;
    return unos(A, inf, mitad) + unos(A, mitad + 1, sup);
}

void print(int A[]){
    for(int i = 0; i < 11; i++)
        cout << A[i] << " ";
}


int main(){
    int A[11] ={0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1};
    cout << "El vector ";
    print(A);
    cout << " tiene " << unos(A, 0, 10) << " unos" << endl;
}
