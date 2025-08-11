#include <iostream>
using namespace std;
int main(){
    int a[6] = {0, 5, 3, 7, 9, 6};
    int b[6]={0};
    for(int i = 1; i<=5; i++){
        for(int k = i-(i&-i)+1; k<=i; k++)
            b[i] += a[k];
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;
}