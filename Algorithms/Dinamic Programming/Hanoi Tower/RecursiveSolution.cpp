#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;

int MinMovements(int n){
    return pow(2, n)-1;
}

void Hanoi( int n, int init, int aux,
            int destiny,
            vector<pair<int, int>>& ans){
                if(n == 0)return;
                // vai de origem para auxiliar usando o destino como auxiliar
                Hanoi(n-1, init, destiny, aux, ans);
                ans.push_back({init, destiny});
                Hanoi(n-1,aux, init, destiny, ans);
            }


int main(){
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> ans;
    Hanoi(n, 1, 2, 3, ans);
    for(pair<int, int> i: ans){
        printf("%d -> %d\n", i.first, i.second);
    }
    printf("%d\n", MinMovements(n));


    return 0;
}