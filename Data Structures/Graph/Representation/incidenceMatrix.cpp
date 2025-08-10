#include <iostream>
#define MAXN 1000

int graph[MAXN][MAXN] = {-1};

using namespace std;

void scanfUndirectedUnweightedGraph(int nv){
    int v1, v2;
    for(int i =0; i<nv;i++){
        cin>> v1>>v2;
        graph[i][v2] = 1;
        graph[i][v1] = 1;
    }
}

void scanfDirectedUnweightedGraph(int nv){
    int v1, v2;
    for(int i =0; i<nv;i++){
        cin>> v1>>v2;
        graph[i][v2] = 1;
        graph[i][v1] = 0;
    }
}
void scanfUndirectedWeightedGraph(int nv){
    int v1, v2, w;
    for(int i =0; i<nv;i++){
        cin>> v1>>v2>>w;
        graph[i][v2] = w;
        graph[i][v1] = w;
    }
}

void scanfDirectedWeightedGraph(int nv){
    int v1, v2, w;
    for(int i =0; i<nv;i++){
        cin>> v1>>v2>>w;
        graph[i][v2] = w;
        graph[i][v1] = 0;
    }
}