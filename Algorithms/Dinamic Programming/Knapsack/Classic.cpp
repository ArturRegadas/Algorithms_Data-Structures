#include <iostream>
#include <cstdio>
#include <vector>
#define MAXN (int)1e4
using namespace std;

int weights[MAXN];
int prices[MAXN];
vector<vector<int>> dp(MAXN, vector<int>(MAXN, 0));
int max(int a, int b){return a>b? a : b;}

int knapsackSolution(int items, int knapsack){
    for(int i =0;i<items;++i){
        for(int w = 0; w<=knapsack;++w){
            if(w < weights[i])dp[i+1][w+1] = dp[i][w+1];
            else dp[i+1][w+1] = max(dp[i][w+1], dp[i][w-weights[i]]+prices[i]);
        }
    }
    return dp[items][knapsack];
}

int main(){
    int items, knapsack, ans;
    scanf("%d", &items);
    for(int i =0;i<items;i++)scanf("%d%d", &prices[i], &weights[i]);
    scanf("%d", &knapsack);
    ans = knapsackSolution(items, knapsack);
    printf("%d\n", ans);
    return 0;
}