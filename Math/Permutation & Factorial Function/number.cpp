#include <iostream>
#define MAXN (int)1e3
using namespace std;


int fact(int n){
    int ans = 1;
    for(int i = 2; i<=n; i++)
        ans*=i;
    return ans;
}

int main(){
    cout<<fact(3)<<endl;
}