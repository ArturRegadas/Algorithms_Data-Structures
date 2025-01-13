#include <iostream>
#include <vector>
using namespace std;

class minHeap{
    public:
    vector<int> heap = {};
    int size = 0 ;

    void printHeap(){
        for(int i : heap){
            cout<<i<<" ";
        }
        cout<<"\n";
    }

    int getParent(int postion){
        return (int)(postion - 1)/2;

    }
    int getLeft(int position){
        return 2 * position + 1 ;
    }
    int getRight(int position){
        return 2 * position + 2 ;
    }

    void addToHeap(int data){
        heap.push_back(data);
        size++;

        siftUp(size-1);

    }
    void siftUp(int index){
        int parent, aux;
        while(index > 0){
            parent = getParent(index);
            //printHeap();
            if (heap[index]<heap[parent]){

                aux = heap[parent];
                heap[parent] = heap[index];
                heap[index] = aux;
                index = parent;
            }
            else{break;}
            

        }
    }
    int getMinInHeap(){
        int response = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        size--;

        siftDown();
        return response;
    }
    void siftDown(){
        int index = 0;
        int left, right, smaller, aux;
        while(2* index + 1 < size){
            left = getLeft(index);
            right = getRight(index);
            smaller = left;

            if(right<size && heap[right]<heap[left]){
                smaller=right;
            }
            if (heap[smaller]<heap[index]){
                aux = heap[index];
                heap[index] = heap[smaller];
                heap[smaller] = aux;
                index = smaller;
                
            }
            else{break;}
            




        }
        
    }

};

int main(){
    minHeap first;
    first.addToHeap(10);
    first.addToHeap(5);
    first.addToHeap(20);
    first.addToHeap(2);

    first.printHeap();

    cout<<"menor:: "<<first.getMinInHeap()<<"\n";
    first.printHeap();

    first.addToHeap(1);
    first.printHeap();

    return 0;
}