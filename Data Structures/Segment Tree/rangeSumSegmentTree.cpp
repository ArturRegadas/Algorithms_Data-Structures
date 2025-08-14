#include <iostream>
#include <vector>

using namespace std;

class SegmentTree{
    private:
    int size;
    vector<int> tree;

    void build(vector<int>&array, int node, int l, int r){
        if(l == r){
            tree[node] = array[l];
            return;
        }
        int mid = (l+r)/2;

        build(array, node*2, l, mid);
        build(array, node*2+1, mid+1, r);
        tree[node] = tree[node*2]+tree[node*2+1];
    }

    public:
    SegmentTree(vector<int> array) : size(array.size()), tree(4 * array.size(), 0){
        build(array, 1, 0, array.size()-1);
    }

    private:
    void recursiveUpdate(int& idx, int& new_value,int node, int l, int r){
        if(l == r){
            tree[node] = new_value;
            return;
        }
        int mid=(l+r)/2;

        if(idx <= mid)
            recursiveUpdate(idx, new_value, node*2, l, mid);
        else
            recursiveUpdate(idx, new_value, node*2+1, mid+1, r);
        tree[node] = tree[node*2]+tree[node*2+1];
    }

    int recursiveQuery(int node, int l, int r, int& find_l, int& find_r){
        if(r < find_l || l > find_r )
            return 0;

        if(l >= find_l && r <= find_r)
            return tree[node];
        
        int mid = (r+l)/2;
        return 
            recursiveQuery(node*2, l, mid, find_l, find_r) +
            recursiveQuery(node*2+1, mid+1, r, find_l, find_r);
    }

    public:
    void update(int idx, int new_value){
        recursiveUpdate(idx, new_value, 1, 0, size-1);
    }

    int query(int init, int end){
        return recursiveQuery(1,0 ,size-1 ,init ,end);
    }

};