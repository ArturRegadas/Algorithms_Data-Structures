#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#define MAXN (int)1e8

using namespace std;


class UnionFind{
    private:
    unordered_map<int, int> parent;
    
    public:
    UnionFind(set<int> nuns){
        for(int i : nuns) parent[i] = i;
    }
    
    int Find(int n){
        return parent[n];
    }
    void Union(int a, int b){
        int pa = Find(a);
        int pb = Find(b);
        for(const auto& [key, value] : parent)
        if(value == pb)parent[key] = pa;
    }   
    bool inSet(int a, int b){
        return Find(a) == Find(b);
    }
};

