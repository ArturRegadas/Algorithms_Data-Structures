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
    unordered_map<int, int> size;
    
    public:
    UnionFind(set<int> nuns){
        for(int i : nuns){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int Find(int n){
        if(parent[n] == n)return n;
        return Find(parent[n]);
    }
    void Union(int a, int b){
        int pa = Find(a);
        int pb = Find(b);
        if(pa==pb)return;
        if(size[pa]>size[pb])swap(pa, pb);
        parent[pa] = pb;
        size[pa]+=size[pb];
        
    }   
    bool inSet(int a, int b){
        return Find(a) == Find(b);
    }
};

