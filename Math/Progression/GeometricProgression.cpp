#include <iostream>
#include <cmath>

using namespace std;

int lastNumberOfPA(int a1, int q, int n){
    return a1 * pow(q, (n-1));
}

int sumPA(int a1, int q, int n){
    if(q == 1)
        return n*a1;
    return a1 * (pow(q, n) - 1) / (q-1);
}