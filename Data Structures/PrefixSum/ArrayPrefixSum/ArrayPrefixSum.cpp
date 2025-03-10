#include <cstdio>
#include <algorithm>
#define MAXN (int)1e5+10
using namespace std;

class PrefixSumArray{
    private:
    int size;
    int PrefixSum[MAXN]={0};

    public:
    PrefixSumArray(int array[], int n){
        for(int i =1; i<=n;++i)this -> PrefixSum[i] = this -> PrefixSum[i-1]+array[i-1];
        this -> size = n+1;
    }
    int getSum(int a, int b){
        if(min(a, b)< 0 || max(a , b)>=this -> size) return -1;
        return this -> PrefixSum[b+1] - this -> PrefixSum[a];
    }
};


int main(){
    int n, p1, p2;
    int array[MAXN];
    scanf("%d", &n);
    for(int i =0; i<n;i++)scanf("%d", &array[i]);
    PrefixSumArray sum(array, n);
    scanf("%d%d", &p1, &p2);
    int ans = sum.getSum(p1, p2);
    printf("%d\n", ans);

    return 0;
}