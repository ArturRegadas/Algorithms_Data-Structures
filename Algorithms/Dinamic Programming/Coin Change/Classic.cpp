#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN (int)1e4+10
#define INF (int)1e9+10
using namespace std;

int n, coins[MAXN];

/*
minimun change with matriz
int MinimunChange(int value){
    vector<vector<int>> dp(n+1, vector<int>(value+1, INF));
    for(int i =0;i<=n;i++)dp[i][0] = 0;
    for(int i =0;i<n;++i){
        for(int j = 0;j<=value;++j){
            if(j<coins[i])dp[i+1][j] = dp[i][j];
            else{
                if(dp[i+1][j - coins[i]] == INF)dp[i+1][j] = INF;
                else dp[i+1][j] = min(dp[i][j], dp[i+1][j - coins[i]] + 1);
            }
        }
    }
    return dp[n][value];
}
*/
int MinimunChange(int value){
    vector<int> dp(value+1, INF);
    dp[0] = 0;
    for(int i =0;i<n;i++){
        for(int j = 0; j<= value;j++){
            if(j>=coins[i])dp[j] = min(dp[j], dp[j-coins[i]]+1);
        }
    }
    return dp[value];
}

int main(){
    int value;
    scanf("%d %d", &n, &value);
    for(int i =0; i<n;++i)scanf("%d", &coins[i]);
    int ansMin = MinimunChange(value);

    printf("%d\n", ansMin);

}