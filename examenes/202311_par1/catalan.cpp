#include <iostream>

using namespace std;

int calatan(int n) {
    if (n <= 1) 
        return 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += calatan(i) * calatan(n - i - 1);
    }
    return sum;
}

int main(void){
    for (int i = 0; i < 10; i++) 
        cout << "catalan(" << i << ") = " <<  calatan(i) << endl;
    return 0;
}


