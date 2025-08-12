#include "BIT.cpp"
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> sortedUnique(vector<int> arr){
    set<int> sans(arr.begin(), arr.end());
    return vector<int>(sans.begin(), sans.end());
}

int main(){
    int inversions = 0;
    int current_rank;
    vector<int> nums = {8, 4, 2, 1};

    /*
    sera armazenada na bit a quantidade
    de elementos menor que x ja foram encontradas
    ate o momento
    */
    BIT bit(nums.size());

    vector<int> sorted_unique = sortedUnique(nums);

    //valor, indice
    unordered_map<int, int> rank;
    for(int i = 0; i<nums.size(); i++)
        rank[sorted_unique[i]] = i+1;
    
    // necessario inverter ja que i < j, por conta da progressao de i -> j,
    // invertemos a ordem de j -> i;
    vector<int> reversed_nums = vector<int>(nums.rbegin(), nums.rend());
    for(int i : reversed_nums){
        current_rank = rank[i];

        // querry conta quantos sao menores ate o rank atual
        inversions += (int)bit.query(current_rank-1);
        bit.incrementUpdate(current_rank, 1);
    }

    printf("%d\n", inversions);

    return 0;
}