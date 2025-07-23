// problema 218. the skyline problem do leetcode
// complexidade O(n log n)
// problemas de Line sweep tem a ver com problema de sobreposição (representação em vetores)
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    if(a[0] != b[0])
        return a[0]<b[0];

    //caso em que nehum dos dois é fim
    if(a[2] != -1 && b[2] != -1)
        return a[1] > b[1];
    
    //caso em que os dois sao fim
    if(a[2] == -1 && b[2] == -1)
        return a[1] < b[1];
    
    // em que um dois dois é fim priorizar o nao fim
    return a[2] > b[2];
}


//deve retornar o novo predio               //recebe a cordenada dos predios
                            //[Li, Ri, Hi]
vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    int left, height, right, ant, current;
    
    // walls = [Li, Hi, Ri]
    vector<vector<int>> walls;
    // ans = [Li, Hi]
    vector<vector<int>> ans;
    for(vector<int> i : buildings){
        walls.push_back({i[0], i[2], i[1]});
        walls.push_back({i[1], -1, -1});
    }
    sort(walls.begin(), walls.end(), cmp);

    // greater<> para MinPriorityQueue
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    ant = -1;
    for(vector<int> i : walls){
        left = i[0];
        height = i[1];
        right = i[2];

        //normaliza a lista de prioridade
        while(!pq.empty() && pq.top().second <= left)
            pq.pop();
        
        if(right != -1)
            pq.push({height, right});

        if(pq.empty())
            current = 0;
        else
            current = pq.top().first;

        if(current != ant){
            ans.push_back({left, current});
            ant = current;
        }
    }
    return ans;
}
