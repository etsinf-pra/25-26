#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;
 
// calcula las combinaciones de N elementos tomados de K en K
vector<vector<int>> comb(int N, int K)
{
    vector<vector<int>> combs;
    // first mask 11100 for N=5 K=3
    vector<int> bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's
  
    do {
        combs.push_back(bitmask);
    } while (prev_permutation(bitmask.begin(), bitmask.end()));
    return combs;
}

// Expande las secuencias separando los 1's con un 0 a la fuerza
vector<vector<int>> gen_sequences( vector<vector<int>> &c){
    vector<vector<int>> q;
    for(auto &comb : c){
        vector<int> seq;
        for(auto &bit : comb){
            if(bit == 1){
                seq.push_back(1);
                seq.push_back(0);
            }
            else
                seq.push_back(0);
        }
        seq.pop_back(); // siempre hay un 0 de más    
        q.push_back(seq);
    }
    return q;
}
 
vector<vector<int>> expand(const vector<vector<int>>& sequences, 
                           const vector<int>& pista)
{
    cout << endl;
    vector<vector<int>> rows;
    for(const auto& seq : sequences) {
        vector<int> row;
        size_t pista_index = 0;
        size_t count = 0;
        for(size_t i = 0; i < seq.size(); ++i) {
            if(seq[i] == 1) {
                // Agregar bloque de 1's según la pista
                for(int j = 0; j < pista[pista_index]; ++j) {
                    row.push_back(1);
                }
                pista_index++;
            } else {
                // Agregar 0's restantes
                row.push_back(0);
            }
        }
        rows.push_back(row);
    }
    return rows;
}


void print_list(const vector<vector<int>>& vec)
{
    for(const auto& item : vec) {
        for(int bit : item) {
            cout << bit << " ";
        }
        cout << endl;
    }
}
int main()
{
    // Ejemplo: tenemos una pista 3 6 2 en una fila de 15 posiciones
    vector<int> pista = {3, 6, 2};
    // calcular suma de bloques (3+6+2) + espacios mínimos (2)
    int sum = reduce(pista.begin(), pista.end(), 0) + (pista.size() - 1);
    cout << "Sum: " << sum << endl;
    int esp = 15 - sum; // espacios libres
    int K = pista.size(); // numero de pistas
    cout << "N: " << K + esp << " K: " << K << endl;
    
    vector<vector<int>> combs = comb(K+esp, K);
    cout << "Generated combinations:" << endl;
    print_list(combs);
    
    vector<vector<int>> sequences = gen_sequences(combs);
    cout << "Generated sequences:" << endl;
    print_list(sequences);

    vector<vector<int>> rows = expand(sequences, pista);
    cout << "Expanded rows for clue {";
        for(int p: pista) {
        cout << p << " ";
    }
    cout << "} :" << endl;   
    print_list(rows);
    return 0;
}