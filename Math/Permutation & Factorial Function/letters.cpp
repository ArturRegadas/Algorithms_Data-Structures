#include <algorithm>
#include <iostream>
#include <string>
#include<vector>

using namespace std;

int dp[1000] = {0};

int fact(int n){
    if(dp[n] != 0){
        return dp[n];
    }
    dp[n] = n * fact(n-1);
    return dp[n];
}

int permutationNoRepeat(string a){
    //improvisacao de map
    int show[250] = {0};
    int d = 1;
    for(char i : a)
        show[(int)i]++;

    for(int i =0; i<250; i++)
        d*= max(1, fact(show[i]));
    
    return fact(a.size())/d;
}

int main(){
    dp[0]=1;
    dp[1]=1;
    cout<<permutationNoRepeat("ANA")<<endl;
}