/*
    encuentra la probabilidad de dar n pasos dentro de una isla
    sin salir de ella
*/

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

#define MAX 50

// up, down, left, right
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

pair<int,int> operator+(const pair<int,int> & l,const std::pair<int,int> & r) {   
    return make_pair(l.first+r.first,l.second+r.second);                                    
} 

// comprueba que el punto está dentro de la matriz
bool outside(pair<int, int> pos){
    return pos.first < 1 || pos.first >= MAX-1 || pos.second < 1 || pos.second >= MAX-1;
}

// genera una isla aleatoria
void genera_isla(vector<string> &isla, int area){
    //posición inicial
    pair<int, int> pos = make_pair(MAX/2, MAX/2);
    isla[pos.first][pos.second] = '*';
    //genera el tamaño de la isla
    vector<pair<int, int> > lista;
    //da un paso en cualquier direccion y los añade a lista
    while(area > 0){
        int k = rand() % 4;
        pair<int, int> pos2 = pos + make_pair(dx[k], dy[k]);
        if(outside(pos2)) continue;
        if(isla[pos2.first][pos2.second] == '.'){
            isla[pos2.first][pos2.second] = '*';
            lista.push_back(make_pair(pos2.first, pos2.second));
            area--;
        }
        pos = lista[rand() % lista.size()];
    }
}

// genera una isla cuadrada
void genera_isla_regular(vector<string> &isla, int lado){
    for(int i = 1; i <= lado; i++)
        for(int j = 1; j <= lado; j++)
            isla[i][j] = '*';
}

//imprime la isla y el recorrido (opcional)
void imprime_isla(vector<string> &isla){
    for(int i = 0; i < isla.size(); i++)
        cout << isla[i] << endl;
}

void print_prob(vector<vector<vector<float> > > &M, int n){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            for(int k = 0; k <= n; k++)
                if(M[i][j][k] > 0)
                    cout << i << "|" << j << "|" << k << ": " << M[i][j][k] << endl;
        }
    }
}

// esta es la función que corresponde al ejercicio
float paseo(vector<vector<vector<float> > >&M, vector<string> &isla, int i, int j, int n){
    if(M[i][j][n] > 0)
        return M[i][j][n];
    // caso base 1: nos salimos de la isla
    if(isla[i][j] == '.' || isla[i][j] == 'x'){
        isla[i][j] = 'x';
        return 0;
    }
    // caso base 2: hemos dado n pasos
    if(n == 0){
        M[i][j][n] = 1;
    }
    else{
        isla[i][j] = 'o';
        float prob = 0;
        // la isla siempre está rodeada por mar 
        // (no hace falta comproabar coordenadas) 
        prob += 0.25 * paseo(M, isla, i-1, j, n-1);
        prob += 0.25 * paseo(M, isla, i+1, j, n-1);
        prob += 0.25 * paseo(M, isla, i, j-1, n-1);
        prob += 0.25 * paseo(M, isla, i, j+1, n-1);
        M[i][j][n] = prob;
    }
    return M[i][j][n];
}


int main(){
    srand(time(NULL));
    vector<string> isla(MAX, string(MAX, '.'));
    vector<vector<vector<float> > > M(MAX, vector<vector<float> >(MAX, vector<float>(MAX, 0)));
    genera_isla(isla,200);
    //genera_isla_regular(isla, 3);
    imprime_isla(isla);
    // empieza en (10, 10)y dar 10 pasos
    cout << paseo(M, isla, MAX/2, MAX/2, 10) << endl;
    //cout << paseo(M, isla, 1, 1, 3) << endl;
    imprime_isla(isla);
    print_prob(M, 3);
    return 0;
}