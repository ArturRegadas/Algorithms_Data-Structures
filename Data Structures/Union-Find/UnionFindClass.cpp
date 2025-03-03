#include <cstdio>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>
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
    bool Union(int a, int b){
        int pa = Find(a);
        int pb = Find(b);
        if(pa == pb)return false;
        for(const auto& [key, value] : parent)
            if(value == pb)parent[key] = pa;
        return true;
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

        price +
        steps++
        if(steps==vertices.size()-1)return price;
        }

    }
    return price;
}

int main(){
    int s, d, p;
    int edgesQ;scanf("%d", edgesQ);
    vector<pair<int, pair<int, int>>> edges(edgesQ);
    set<int> vertices;
    /*
    {1, {2, 1}}
    */
    for(int i =0;i<edgesQ;i++){
        scanf("%d%d%d", &s, &d, &p);
        edges[i] = {s,{d, p}};
        vertices.insert(s);vertices.insert(d);
    }
    
    



    return 0;
}