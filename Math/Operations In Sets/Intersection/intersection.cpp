#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

bool FIND(int a, unordered_set<int>b){
    return b.find(a) != b.end();
}

unordered_set<int> intersection(unordered_set<int> a, unordered_set<int> b){
    if(b.size() < a.size())
        swap(a, b);
    unordered_set<int> ans;
    for(int i : a)
        if(FIND(i, b))
            ans.insert(i);
    return ans;
}