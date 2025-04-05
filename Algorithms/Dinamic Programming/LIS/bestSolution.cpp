#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

//O(nLog(n))
vector<int> LIS(vector<int>& nums){
    vector<int> ans;
    int n = nums.size();
    for(int i =0;i<n;i++){
        auto pos = lower_bound(ans.begin(), ans.end(), nums[i]);
        //faz um binary search e encontra a menor posição que caso o valor 
        //seja inserido o vector ainda esteja rdenado
        if(pos == ans.end())ans.push_back(nums[i]);
        else *pos = nums[i];
        //muda o valor do nodo
    }
    return ans;
}


int main(){
    int s;scanf("%d", &s);
    vector<int> nums(s);
    for(int i =0;i<s;i++)scanf("%d", &nums[i]);

    for(int i : LIS(nums)){
        printf("%d ",i);
    }
    printf("\n");

    return 0;
}