#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, vector<int>> UnWeightedGraph;
unordered_map<int, unordered_map<int, int>> WeightedGraph;

//numero de vertices
void scanfUndirectedUnweightedGraph(int nv){
    int v1, v2;
    for(int i =0; i<nv;i++){
        cin>> v1>>v2;
        UnWeightedGraph[v1].push_back(v2);
        UnWeightedGraph[v2].push_back(v1);

    }
}

void scanfDirectedUnweightedGraph(int nv){
    int v1, v2;
    for(int i =0; i<nv;i++){
        cin>> v1>>v2;
        UnWeightedGraph[v1].push_back(v2);
    }
}
void scanfUndirectedWeightedGraph(int nv){
    int v1, v2, w;
    for(int i =0; i<nv;i++){
        cin>> v1>>v2>>w;
        WeightedGraph[v1][v2] = w;
        WeightedGraph[v2][v1] = w;
    }
}

void scanfDirectedWeightedGraph(int nv){
    int v1, v2, w;
    for(int i =0; i<nv;i++){
        cin>> v1>>v2>>w;
        WeightedGraph[v1][v2] = w;
    }
}