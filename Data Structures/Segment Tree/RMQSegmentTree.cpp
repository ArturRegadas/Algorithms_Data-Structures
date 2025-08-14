#include <algorithm>
#include <iostream>
#include <vector>

#define INF (int)1e9

using namespace std;

class SegmentTree{
    private:
    int size;
    // 
    vector<int> tree;

    public:
    SegmentTree(vector<int> array): size(array.size()), tree(4*array.size(), INF) {
        build(array, 1, 0, array.size() - 1);
    }

    private:
    void recursiveUpdate(int& idx, int& newValue, int node, int l, int r){
        //caso base
        if(r == l){
            tree[node] = newValue;
            return;
        }
        int mid = (l+r) / 2;
        if(idx <= mid)
            recursiveUpdate(idx, newValue, node*2, l, mid);
        else
            recursiveUpdate(idx, newValue, node*2+1 ,mid+1, r);
        tree[node] = min(tree[node*2], tree[node*2+1]);
    }

    int recursiveQuerry(int node, int& find_l, int& find_r, int l, int r){
        //caso base
        if(r < find_l || l > find_r)
            return INF; // fora do intervalo
        
        if (l >= find_l && r <= find_r)
            return tree[node];
        
        int mid = (l+r) / 2;
        return min(
            recursiveQuerry(node*2, find_l, find_r, l, mid),
            recursiveQuerry(node*2+1, find_l, find_r, mid+1, r)
        );
        
        
    }

    public:
    void build(vector<int>& array, int node, int l, int r){
        //caso base
        if(l == r){
            // momento em que chegamos na profundidade da arvore
            tree[node] = array[l];
            return;
        }

        int mid = (l+r) / 2;

        // filho da esquerda e respectivo no array original
        build(array, node*2, l, mid);

        //filho da direita e respectivo no array original
        build(array, node*2+1, mid+1, r);

        // pegar o menor entre os dois filhos em diferentes problema essa sempre vai ser a mudança
        tree[node] = min(tree[node*2], tree[node*2+1]);
    }

    void update(int idx, int newValue){
        recursiveUpdate(idx, newValue, 1, 0, size-1);
    }

    int querry(int init, int end){
        return recursiveQuerry(1, init, end, 0, size-1);
    }
};

