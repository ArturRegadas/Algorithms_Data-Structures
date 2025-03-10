#include <bits/stdc++.h>
#define INF (int)1e9+10
#define pb push_back
#define F first
#define S second
#define map unordered_map<int, vector<pair<int , int>>>
using namespace std;

unordered_map<int, int> parents;

void getPath(int current, vector<int>& ans){
    if(current != parents[current]){
        getPath(parents[current], ans);
    }
    ans.pb(current);
}

vector<int> dijkstra(int init, int destiny, map graph){
    int currPrice, currNode, iPrice, iNode;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    unordered_map<int, int> prices;
    parents[init] = init;
    for(const auto& [key, value] : graph)prices[key] = INF;
    prices[init] = 0;
    pair<int , int> current;
    pq.push({0, init});
    while(!pq.empty()){
        current = pq.top();
        pq.pop();
        currPrice = current.F;
        currNode = current.S;
        if(currPrice > prices[currNode])continue;
        if(currNode == destiny){
            vector<int> ans;
            getPath(destiny, ans);
            return ans;

        }
        for(pair<int, int> i : graph[currNode]){
            iPrice = i.S;iNode = i.F;
            if(prices[currNode]+iPrice < prices[iNode]){
                parents[iNode] = currNode;
                prices[iNode] = prices[currNode]+iPrice;
                pq.push({prices[iNode], iNode});
            }
        }
    }
    return {-1};
}

int main(){
    int vertices,edges, init , destiny;
    int in, d, p;
    scanf("%d%d", &vertices, &edges);

    map graph;
    for(int i =0;i<edges;++i){
        scanf("%d%d%d", &in, &d, &p);
        graph[in].pb({d, p});
        graph[d].pb({in, p});
    }
    scanf("%d%d", &init, &destiny);
    vector<int> ans = dijkstra(init, destiny, graph);
    for(int i =0;i<ans.size()-1;++i)printf("%d ", ans[i]);
    printf("%d\n", ans.back());


    return 0;
}