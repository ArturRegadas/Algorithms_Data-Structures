#include <iostream>

//implementar DP
int fact(int n){
    if(n <= 1){
        return 1;
    }
    return n*fact(n-1);
}

//Você tem 5 livros e quer escolher 2 para levar.
int combination(int n, int k){
    return fact(n) / (fact(k) * fact(n-k));
}