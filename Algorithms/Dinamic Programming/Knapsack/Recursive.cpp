#include <iostream>
#include <cstdio>
#include <vector>
#define MAXN (int)1e4
using namespace std;

int weights[MAXN];
int prices[MAXN];
vector<vector<int>> dp(MAXN, vector<int>(MAXN, -1));

int max(int& a, int& b){return a>b? a : b;}

int knapsackSolution(int i, int w){
    if(i==0 || w ==0)return 0;
    if(dp[i][w] != -1)return dp[i][w];
    if(w < weights[i-1])return dp[i][w] = knapsackSolution(i-1 , w);
    return dp[i][w] = max(knapsackSolution(i-1, w),knapsackSolution(i-1, w-weights[i-1])+prices[i-1]);
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