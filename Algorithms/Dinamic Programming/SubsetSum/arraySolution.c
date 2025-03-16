#include <stdio.h>
#define MAXI 155
#define MAXN 150001

int nums[MAXI];
int main(){
    int n, target;
    int sum =0;
    scanf("%d%d", &n, &target);
    for(int i =0;i<n;i++){
        scanf("%d", &nums[i]);
        sum += nums[i];
    }

    int dp[MAXN]={0};
    dp[0] = 1;
    for(int i =0;i<n;i++){
        for(int j =target; j>=nums[i];j--){
            dp[j] |= dp[j-nums[i]];
        }
    }
    for(int i =target;i>=0;i--){
        if(dp[i]){
            printf("%d\n", i);
            break;
        }
    }


    return 0;
}