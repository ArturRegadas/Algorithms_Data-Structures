#include <iostream>
#define MAXN 1000

int graph[MAXN][MAXN];

using namespace std;

//numero de vertices
void scanfUndirectedUnweightedGraph(int nv){
    int v1, v2;
    for(int i =0; i<nv;i++){
        cin>> v1>>v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
}

void scanfDirectedUnweightedGraph(int nv){
    int v1, v2;
    for(int i =0; i<nv;i++){
        cin>> v1>>v2;
        graph[v1][v2] = 1;
    }
}
void scanfUndirectedWeightedGraph(int nv){
    int v1, v2, w;
    for(int i =0; i<nv;i++){
        cin>> v1>>v2>>w;
        graph[v1][v2] = w;
        graph[v2][v1] = w;
    }
}

void scanfDirectedWeightedGraph(int nv){
    int v1, v2, w;
    for(int i =0; i<nv;i++){
        cin>> v1>>v2>>w;
        graph[v1][v2] = w;
    }
}