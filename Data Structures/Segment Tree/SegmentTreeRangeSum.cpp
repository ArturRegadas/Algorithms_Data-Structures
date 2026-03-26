/*
build O(n)
query O(log n)
update O(log n)
update_range O(n log n) para cada update
*/
#include <vector>

#define INF (int)1e9+10

using namespace std;

class IndexHelper{
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

    int getMiddleIndex(int left_index, int right_index){
        return (left_index + right_index) / 2;
    }
};

class SegmentTree : private IndexHelper{
    private:
    vector<int> tree;
    int size;


    public:
    SegmentTree(vector<int> array) : tree(array.size()*4+1, 0), size(array.size()){
        build(array, 0, 0, array.size() - 1);
    }

    private:
    int sum(int first_value, int second_value){
        return first_value + second_value;
    }

    bool isOutOfRange(int left, int right, int left_limit, int right_limit){
        return (right_limit < left || left_limit > right);
    }

    bool isFullyInside(int left, int right, int left_limit, int right_limit){
        return (left_limit <= left && right <= right_limit);
    }

    bool isLeaf(int node_left_index, int node_right_index){
        return (node_left_index == node_right_index);
    }

    void build(
        vector<int>& array,
        int current_node_index,
        int init_range, int end_range
    ){
        if(isLeaf(init_range, end_range)){
            tree[current_node_index] = array[init_range];
            return;
        }

        int middle_range = getMiddleIndex(init_range,end_range);
        int left_node_index = getLeftIndex(current_node_index);
        int right_node_index = getRightIndex(current_node_index);

        build(array, left_node_index, init_range, middle_range);
        build(array, right_node_index, middle_range + 1, end_range);

        // mudanca logica
        tree[current_node_index] = sum(tree[left_node_index], tree[right_node_index]);
        //                           |
        //                         lambda
    }

    int recursiveQuery(
        int current_node_index,
        int& wanted_left_index,
        int& wanted_right_index,
        int current_left_index,
        int current_right_index
    ){
        if (isOutOfRange(
            current_left_index,
            current_right_index,
            wanted_left_index,
            wanted_right_index
        ))
        return 0;

        if (isFullyInside(
            current_left_index,
            current_right_index,
            wanted_left_index,
            wanted_right_index
        ))
            return tree[current_node_index];
    

        int current_middle_index = getMiddleIndex(current_left_index, current_right_index);
        int left_node_index = getLeftIndex(current_node_index);
        int right_node_index = getRightIndex(current_node_index);

        return sum(
            recursiveQuery(
                left_node_index,
                wanted_left_index,
                wanted_right_index,
                current_left_index,
                current_middle_index
            ),
            recursiveQuery(
                right_node_index,
                wanted_left_index,
                wanted_right_index,
                current_middle_index + 1,
                current_right_index
            )
        );
    }

    void recursiveUpdate(
        int current_node_index,
        int& new_value,
        int& wanted_index,
        int current_left_index,
        int current_right_index
    ){
        if(isLeaf(current_left_index, current_right_index)){
            tree[current_node_index] = new_value;
            return;
        }

        int current_middle_index = getMiddleIndex(current_left_index, current_right_index);
        int left_node_index = getLeftIndex(current_node_index);
        int right_node_index = getRightIndex(current_node_index);

        if(wanted_index <= current_middle_index)
            recursiveUpdate(
                left_node_index,
                new_value,
                wanted_index,
                current_left_index,
                current_middle_index
            );
        else
            recursiveUpdate(
                right_node_index,
                new_value,
                wanted_index,
                current_middle_index + 1,
                current_right_index
            );
        
        tree[current_node_index] = sum(
            tree[left_node_index],
            tree[right_node_index]
        );
    }

    public:
    int query(int init_range, int end_range){
        return recursiveQuery(0, init_range, end_range, 0, size - 1);
    }

    void update(int new_value, int index){
        recursiveUpdate(0, new_value, index, 0, size - 1);
    }

    
};