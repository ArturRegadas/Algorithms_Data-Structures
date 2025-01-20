#include <iostream>
#include <vector>
#include <algorithm> //usar heap

using namespace std;

void printHeap(vector<int> heap){
    for (int i : heap) std::cout << i << " ";
    std::cout << "\n";
}

int main(){

    vector<int> data = {4, 10, 3, 5, 1};

    make_heap(data.begin(), data.end());
    printHeap(data);

    data.push_back(7);
    push_heap(data.begin(), data.end());

    printHeap(data);

    pop_heap(data.begin(), data.end());
    int maxElement = data.back();
    data.pop_back();
    cout << "Max-Heap apos pop_heap (removendo maior elemento): ";
    printHeap(data);
    cout << "Maior elemento removido: " << maxElement << "\n";

    sort_heap(data.begin(), data.end());
    cout << "Heap ordenado apos sort_heap: ";
    printHeap(data);




    


    
}