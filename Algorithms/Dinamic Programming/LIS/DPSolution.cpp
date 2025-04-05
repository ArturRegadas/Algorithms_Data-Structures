#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

//O(n²)
int solution(vector<int>& nums){
    int s = nums.size();
    int ans = 0;
    int current = 0;
    for(int i = 1; i<s; i++){
        for(int j = 0; j<s;j++)if(nums[j]<nums[i])current++;
        ans = max(ans, current);
        current = 0;
    }
    return ans;
}

int main(){
    int n;scanf("%d", &n);
    vector<int> nums(n);
    for(int i =0;i<n;i++)scanf("%d", &nums[i]);
    printf("%d\n", solution(nums));

    return 0;
}