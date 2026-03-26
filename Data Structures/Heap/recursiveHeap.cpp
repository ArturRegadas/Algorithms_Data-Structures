#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

class HeapIndexHelper{
    protected:   
    int getParentIndex(int index){
        return (index - 1) / 2;
    }

    int getLeftIndex(int index){
        return 2 * index + 1;
    }

    int getRightIndex(int index){
        return 2 * index + 2;
    }

    int getMinIndex(){
        return 0;
    }
};

class Heap : private HeapIndexHelper{
    private:
    vector<int> heap;

    int getValueByIndex(int index){
        return heap[index];
    }

    int getLastIndex(){
        return heap.size() - 1;
    }

    int getMin(){
        return heap[0];
    }

    bool validIndex(int index){
        return index < heap.size();
    }
   
    void siftUp(int current_index){
        if (current_index == 0)
            return;

        int parent_index = getParentIndex(current_index);

        if (getValueByIndex(parent_index) > getValueByIndex(current_index)) {
            swap(heap[parent_index], heap[current_index]);
            siftUp(parent_index);
        }
    }

    void siftDown(int current_index){
        int left_index = getLeftIndex(current_index);
        int right_index = getRightIndex(current_index);

        if (!validIndex(left_index))
            return;

        int min_value_index = left_index;

        if (
            validIndex(right_index) &&
            getValueByIndex(right_index) < getValueByIndex(left_index)
        ) {
            min_value_index = right_index;
        }

        if (getValueByIndex(current_index) <= getValueByIndex(min_value_index))
            return;

        swap(heap[current_index], heap[min_value_index]);
        siftDown(min_value_index);
    }

    public:
    int getMinInHeap(){
        if (heap.empty())
            throw runtime_error("empty heap");

        int response = getMin();

        swap(heap[getMinIndex()], heap[getLastIndex()]);
        heap.pop_back();

        if (!heap.empty())
            siftDown(getMinIndex());

        return response;
    }

    void addToHeap(int data){
        heap.push_back(data);
        siftUp(getLastIndex());
    }
};