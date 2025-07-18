//solução optimizada em O(log n) p/busca
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

#define MAXN (int)1e5+10
#define MAXLOG (int)20 //2^20 1e6

umap<int, vector<int>> graph;
vector<vector<int>> parent(MAXN, vector<int>(MAXLOG, -1)); // dp
int depth[MAXN];


// current and parent
void dfs(int c, int p){ //build LCA para as pesquisas
    //parent[c][0] == parent de c
    //parent[c][n] == 2^^k-esimo parent de c
    parent[c][0] = p;
    for(int i = 1; i<MAXLOG; i++)
        if(parent[c][i-1] != -1)
            parent[c][i] = parent[parent[c][i-1]][i-1];
        else
            parent[c][i] = -1;
    
    for(int i : graph[c]){
        if(i != p && depth[i] == 0){
            depth[i] = depth[c] + 1 ;
            dfs(i, c);
        }
    }
}

//algoritmo para nivelar
int lift(int c, int k){
    int i =0;
    while(c != -1 && k > 0){
        if(k%2==1)
            c = parent[c][i];
        k /= 2;
        i++;
    }
    return c;
}

int LCA(int a, int b){
    // vamos considerar que a esta a um nivel maior que b
    if(depth[b] > depth[a])
        swap(a, b);
    a = lift(a, depth[a] - depth[b]);

    //caso em que o LCA é a propria busca
    if(a == b)
        return a;

    //subida ate o ultimo acestral não comum
    for(int i = MAXLOG-1; i>=0; i--){
        if(parent[a][i] != -1 && parent[a][i] != parent[b][i]){
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}


int main(){
    
    depth[1] = 1;
    int n, c;
    int d, p;
    scanf("%d", &n);
    for(int i =0; i<n-1; i++){
        scanf("%d%d", &d, &p);
        graph[d].push_back(p);
        graph[p].push_back(d);
    }
    scanf("%d", &c);
    dfs(1, -1);
    for(int i =0; i<c;i++){
        scanf("%d%d", &d, &p);
        printf("%d\n", LCA(d, p));
    }
}