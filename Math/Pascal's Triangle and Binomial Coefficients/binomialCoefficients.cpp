#include <iostream>

using namespace std;

int fact(int n){
    if(n <= 1)
        return 1;
    return n*fact(n-1);
}

int getPascalPosition(int n, int k){
    k--;
    return fact(n) / (fact(k) * fact(n-k));
}