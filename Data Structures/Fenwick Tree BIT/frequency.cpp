// nesse problema seria possivel implementar um constructor em O(N)
// seria necessario apenas mudar a estrutura de BIT para incrementar + 1
// nos exercicios nao tem problema fazer em O(N log N) por que no fundo 
// vai ser O(N log N) nao vai mudar muito o fato de fazer um constructor em tempo linear
#include <algorithm>
#include "BIT.cpp"
#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> sortedUnique(vector<int> arr){
    set<int> sans(arr.begin(), arr.end());
    return vector<int>(sans.begin(), sans.end());
}

class DynamicRank{
    private:
    vector<int> sorted_unique;
    BIT bit;

    public:
    DynamicRank(vector<int> a){
        sorted_unique = sortedUnique(a);
        bit = BIT(a.size());
    }

    int rank(int n){
        int pos = lower_bound(sorted_unique.begin(),sorted_unique.end(),n) - sorted_unique.begin();
        return bit.query(pos);
    }

    void insert(int value){
        int pos = lower_bound(sorted_unique.begin(), sorted_unique.end(), value) - sorted_unique.begin() + 1;
        bit.incrementUpdate(pos, 1);
    }

};

int main(){
    vector<int> nums = {5, 1, 2, 7, 5};
    DynamicRank dr(nums);

    for(int i : nums)
        dr.insert(i);
    
    cout<<dr.rank(5)<<endl;
    cout<<dr.rank(3)<<endl;
    
    return 0;

}