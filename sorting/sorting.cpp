#include <iostream>

SortNet::SorNet(int len){
    this->len = len;
    this->a = new int(len);
} 

SortNet::SortNet(int *v){
    len = sizeof(v) / sizeof(v[0]);
    a = new int(len);
    for(int i = 0; i < len; i++)
        a[i] = v[i];  
} 

~SortNet::SortNet(){
    delete[] a; 
} 

int SortNet::input(int *v){
    int n = sizeof(v) / sizeof(v[0]);
    if (n == len){ 
        for(int i = 0; i < len; i++)
            a[i] = v[i]; 
        return 0;
    } 
    else 
        return -1;
} 

void SortNet::print(){
    for(int i = 0; i < len; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
} 

void SortNet::sort(){
    swap(0, 1);
    swap(1, 2);
    swap(0, 2);
} 

void SortNet::swap(int i, int j){
    int aux;
    aux = a[i];
    a[i] = a[j];
    a[j] = aux;   
}  





