#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

//a e b poderiam ser vetores
unordered_set<int> Union(unordered_set<int>a, unordered_set<int>b){
    if(b.size()<a.size())
        swap(a, b);
    for(int i : b)
        a.insert(i);
    return a;
}