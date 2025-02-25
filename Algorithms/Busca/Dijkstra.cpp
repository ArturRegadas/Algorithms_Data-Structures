#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;
int infinity = numeric_limits<int>::max();

int getMin(unordered_map<int, int> prices, vector<int> queue, unordered_map<int, bool> processed){
    int minus = infinity;
    int index = -1;
    for(int i : queue){
        if(prices[i] < minus && !processed[i]){
            minus=prices[i];
            index = i;
        }
    }
    return index;

}

vector<int> getPath(unordered_map<int, int> parents, int init, int current){
    vector<int> path;
    while(current != init){
        path.push_back(current);
        current = parents[current];
    }
    path.push_back(init);
    reverse(path.begin(), path.end());
    return path;


}

vector<int> dijkstra(unordered_map<int, unordered_map<int, int>> graph, int init, int end, int size){
    
    unordered_map<int, int> prices;
    unordered_map<int, bool> processed;
    for(int i = 1; i<=size; i++){
        prices[i] = infinity;
        processed[i] = false;
    }
    prices[init] = 0;

    int current;
    vector<int> queue = {init};

    unordered_map<int, int> parents;


    for(int g =0; g<size; g++){
        current = getMin(prices, queue, processed);
        if(current == -1){
            break;
        }
        if (current == end){
            return getPath(parents, init, end);
        }
        processed[current] = true;

        for(auto i : graph[current]){
            queue.push_back(i.first);
            if(prices[current]+i.second< prices[i.first]){
                prices[i.first]=prices[current]+i.second;
                parents[i.first] = current;
            }
        }
    }
    return {-1};

}


int main(){

    int vertices, edges;
    unordered_map<int, unordered_map<int, int>> graph;

    cin>>vertices>>edges;
    
    int edg1, edg2, wgh;
    for(int i = 1; i<=edges; i++){
        cin>>edg1>>edg2>>wgh;
        graph[edg1][edg2] = wgh;
        graph[edg2][edg1] = wgh;
    }

    vector<int> path = dijkstra(graph, 1, vertices, vertices);

    for(int i: path){
        cout<< i<<" ";
    }
    cout<<"\n";



    return 0;
}