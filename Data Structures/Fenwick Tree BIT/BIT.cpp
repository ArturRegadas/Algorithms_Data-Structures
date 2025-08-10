/*

*/
#include <iostream>
#include <vector>

using namespace std;

class BIT{
    private:
    int size;
    vector<long long> tree;

    //retorna o ultimo bit significativo(LSB)
    //exemplo: lsb(6) = 2 -> 110 | lsb = 10 -> 2 
    int lsb(int n){
        return n & -n;
        // -n inverte todos os bits depois do lsb
    }

    //soma de 1 até n
    long long query(int idx){
        long long ans = 0;
        while (idx > 0){
            ans += tree[idx];
            idx -= lsb(idx);
        }
        return ans;
    }
    
    public:
    // tamanho da arvore, indexada em 1
    BIT(int n): size(n), tree(n+1, 0){}

    //atualiza idx com valor d
    void update(int idx, long long d){
        while(idx <= size){
            tree[idx] += d;
            idx += lsb(idx);
        }
    }
    
    long long rangeQuery(int init, int end){
        return query(end) - query(init-1);
    }

};
