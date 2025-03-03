#include <iostream>
#include <cstdio>
#define ll long long int 
#define MAXN (int)1e5
using namespace std;

ll dp[MAXN]={0};

/*
exponencial +- O(2**x)
int fibonacci(int n){
    if(n<=1)return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}
*/
// O(n)
int fibonacci(int n){
    if(dp[n]!= 0)return dp[n];
    dp[n] = fibonacci(n-1)+fibonacci(n-2);
    return dp[n];
}

int main(){
    dp[0] = 1; dp[1] = 1;
    int n;
    scanf("%d", &n);
    printf("%d\n", fibonacci(n));
    return 0;
}


