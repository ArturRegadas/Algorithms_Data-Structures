// numa aplicação nomral mudar um range [l, r] demora O(N log N)
// com Lazy Propagation é possivel em O(log N)
#include <iostream>
#include <vector>

using namespace std;

// max in range 
class LazySegmentTree{
    private:
    int size;
    vector<int> tree, lazy;

    void build(vector<int>& array,int node ,int l, int r){
        if(l == r){
            tree[node] = array[l];
            return;
        }
        int mid = (l+r)/2;

        build(array, node*2, l, mid);
        build(array, node*2+1, mid+1, r);

        tree[node] = max(tree[node*2], tree[node*2+1]);
    }

    public:
    LazySegmentTree(vector<int> array) : size(array.size()), tree(4 * array.size(), 0), lazy(4 * array.size(), 0){
        build(array, 1, 0, array.size()-1);
    }

    

};