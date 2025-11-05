/*
    encontrar el prefijo común más largo en una lista de palabras
    usa do divide y vencerás
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string extract(string s1, string s2){
    string res = "";
    int i = 0;
    while(s1[i] == s2[i] && i < s1.size() && i < s2.size()){
        res += s1[i];
        i++;
    }
    return res;
}

string prefijo(vector<string> &palabras, int ini, int fin){
    if(ini > fin)
        return "";
    if(ini == fin)
        return palabras[ini];
    int mitad = (ini + fin) / 2;
    string pref1 = prefijo(palabras, ini, mitad);
    string pref2 = prefijo(palabras, mitad+1, fin);
    return extract(pref1, pref2);
}


int main(){
    const char *aux[] = {"franja", "frase", "francia", "fraude", "fracaso", "fragua", "fractal"};
    vector<string> palabras(aux, aux + 7);
    string pref = prefijo(palabras, 0, palabras.size()-1);
    cout << "Prefijo: " << pref << endl;
}