/*
    Acortador de url usando una tabla hash
*/

#include "hash.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    HashTable urlShortener;
    string alphanum = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    // Carga las URL del fichero
    freopen("urls.txt", "r", stdin);
    string originalUrl;
    while (getline(cin, originalUrl)) {
        string shortUrl = "";
        for (int i = 0; i < 7; ++i) 
            shortUrl += alphanum[rand() % alphanum.size()];
        // Inserta la URL original y su versión acortada en la tabla hash
        urlShortener.insert(originalUrl, shortUrl);
        cout << "Original: " << originalUrl << " -> Shortened: " << shortUrl << endl;
    }

    return 0;
}