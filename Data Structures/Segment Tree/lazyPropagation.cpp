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
            lazy[node] = 0;
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

    private:
    void propagation(int node, int l, int r){
        if(lazy[node] == 0)
            return;
        
        tree[node] = max(tree[node], lazy[node]);

        // verifica se tem filhos, no caso verifica se o
        // range é diferent de [1,1] ou [2, 2] por exemplo
        if(l != r){
            lazy[node*2] = max(lazy[node*2],lazy[node]);
            lazy[node*2+1] = max(lazy[node*2+1],lazy[node]);
        }
        lazy[node] = 0;


    }
    // alterar de [idl, idr] = new_value
    void recursiveRangeUpdate(int node,int& idl, int& idr, int& new_value, int l, int r){
        propagation(node, l, r);

        // fora do [idl, idr]
        if(r < idl || l > idr)
            return;

        //os dois dentro de [idl, idr]
        if(l >= idl && r <= idr){
            lazy[node] = new_value;
            propagation(node, l, r);
            return;
        }

        int mid = (l+r)/2;
        recursiveRangeUpdate(node*2, idl, idr, new_value, l, mid);
        recursiveRangeUpdate(node*2+1, idl, idr, new_value, mid+1 ,r);      
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }

    int recursiveRangeQuery(int node, int& idl, int& idr, int l, int r){
        propagation(node, l, r);
        if(r < idl || l > idr)
            return -1;
        
        if(l >= idl && r <= idr)
            return tree[node];
        
        int mid = (l+r)/2;
        int for_left = recursiveRangeQuery(node*2, idl, idr, l, mid);
        int for_right = recursiveRangeQuery(node*2+1, idl, idr, mid+1, r);
        return max(for_left, for_right);
    }

    public:
    void rangeUpdate(int idl, int idr, int new_value){
        recursiveRangeUpdate(1, idl, idr, new_value, 0, size-1);
    }

    int rangeQuery(int idl, int idr){
        return recursiveRangeQuery(1, idl, idr, 0, size-1);
    }

};