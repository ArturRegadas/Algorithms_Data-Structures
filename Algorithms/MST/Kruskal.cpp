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
    bool Union(int a, int b){
        int pa = Find(a);
        int pb = Find(b);
        if(pa==pb)return false;
        if(size[pa]>size[pb])swap(pa, pb);
        parent[pa] = pb;
        size[pa]+=size[pb];
        return true;
    }   
    bool inSet(int a, int b){
        return Find(a) == Find(b);
    }
};

bool compare(pair<int, pair<int, int>> a,
pair<int, pair<int, int>> b){
    return a.second.second<b.second.second;
}
int Kruskal(vector<pair<int, pair<int, int>>> edges,
            set<int> vertices){
    
UnionFind nuns(vertices);
sort(edges.begin(), edges.end(), compare);
int price = 0;
int steps =0;
for(pair<int, pair<int, int>> current : edges){
    if(nuns.Union(current.first, current.second.first)){
        
    price += current.second.second;
    steps++;
    if(steps==vertices.size()-1)return price;
}

}
return price;
}


int main(){
    int s, d, p;
    int edgesQ;
    scanf("%d",&edgesQ);
    vector<pair<int, pair<int, int>>> edges(edgesQ);
    set<int> vertices;
    /*
    {1, {2, 1}}
    */
    for(int i =0;i<edgesQ;i++){
        scanf("%d%d%d", &s, &d, &p);
        edges[i] = {s,{d, p}};
        vertices.insert(s);
        vertices.insert(d);
    }
    printf("%d\n", Kruskal(edges, vertices));
        

    return 0;
}