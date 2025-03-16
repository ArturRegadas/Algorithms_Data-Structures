#include <bitset>
#include <cstdio>

#define MAXI 155
#define MAXN 1500010 //155*2000 / 2
using namespace std;

int nums[MAXI];
int main(){
    int sum =0;
    int n, target;scanf("%d%d", &n, &target);
    for(int i =0;i<n;i++){
        scanf("%d", &nums[i]);
        sum+=nums[i];
    }   
    bitset<MAXN> dp;
    dp[0]= 1;
    for(int i = 0;i<n;i++){
        dp |= (dp<<nums[i]);
    }
    for(int i = target; i>=0;i--){
        if(dp[i]){
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}