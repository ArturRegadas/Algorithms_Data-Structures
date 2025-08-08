#include <iostream>

// a1 -> primeiro numero da PA
// r  -> razao da PA
// n  -> quntidade de numeros na PA
int lastNumberOfPA(int a1, int r, int n){
    return a1 + (n-1)*r;
}

int sumPA(int a1, int r, int n){
    return (n/2) * (a1+lastNumberOfPA(a1, r, n));
}