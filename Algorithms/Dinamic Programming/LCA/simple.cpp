//solução simples em O(n) p/busca
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#define FIND(container, key) ((container).find(key) != (container).end())
#define uset unordered_set
#define umap unordered_map
using namespace std;


umap<int, pair<int, int>> bfsDepth(umap<int, vector<int>> graph, int init){
    vector<int> queue = {init};
    // node, parent node, depth
    umap<int, pair<int, int>> parent = {{1, {1, 0}}};
    uset<int> processed = {init};
    while(!queue.empty()){
        int current = queue[0];
        queue.erase(queue.begin());
        for(int i : graph[current]){
            if(!FIND(processed, i)){
                queue.push_back(i);
                processed.insert(i);
                parent[i] = {current, parent[current].second + 1};
            }
        }
    }
    return parent;
}


int simpleLCA(umap<int, pair<int, int>>tree ,int v1, int v2){
    if (tree[v2].second > tree[v1].second)
        swap(v1, v2);
    int ans = 0;
    //nivelação
    while(tree[v1].second > tree[v2].second){
        v1 = tree[v1].first;
    }
    while(v1 != v2){
        v1=tree[v1].first;
        v2=tree[v2].first;
    }
    return v1;

}

int main(){
    int n, c;
    umap<int, vector<int>> graph;
    int d, p;
    scanf("%d", &n);
    for(int i =0; i<n-1; i++){
        scanf("%d%d", &d, &p);
        graph[d].push_back(p);
        graph[p].push_back(d);
    }
    umap<int, pair<int, int>> tree = bfsDepth(graph, 1);
    scanf("%d", &c);
    for(int i =0; i<c; i++){
        scanf("%d%d", &d, &p);
        int ans = simpleLCA(tree,d, p);
        printf("%d\n", ans); 
    }
    

    return 0;
}