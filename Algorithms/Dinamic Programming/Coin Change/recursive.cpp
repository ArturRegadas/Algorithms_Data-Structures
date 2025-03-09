#include <cstdio>
#include <vector>
#include <algorithm>
#define  MAXN (int)1e4+10
#define INF (int)1e9+10
using namespace std;
int n, value, coins[MAXN];

int CoinChange(int amount, int i,  vector<vector<int>>& dp){
    if(amount == 0) return 0;
    if(amount < 0 || i < 0) return INF;
    if(dp[i][amount] != INF)return dp[i][amount];
    dp[i][value] = min(CoinChange(amount, i-1, dp),
                        CoinChange(amount - coins[i], i, dp)+1);
    return dp[i][value];
}

int main(){
    scanf("%d %d", &n, &value);
    for(int i =0;i<n;++i)scanf("%d", &coins[i]);
    vector<vector<int>> dp(n+1, vector<int>(value+1, INF));
    int ans = CoinChange(value, n-1, dp);
    printf("%d\n", ans);
    return 0;
}