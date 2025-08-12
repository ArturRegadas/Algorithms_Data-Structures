/*

*/
#include <iostream>
#include <vector>

using namespace std;

class BIT{
    private:
    int size;
    vector<long long> array; //
    vector<long long> tree;

    //retorna o ultimo bit significativo(LSB)
    //exemplo: lsb(6) = 2 -> 110 | lsb = 10 -> 2 
    int lsb(int n){
        return n & -n;
        // -n inverte todos os bits depois do lsb
    }

    
    
    public:
    // tamanho da arvore, indexada em 1
    BIT(): size(0), tree(1, 0), array(1, 0){}
    BIT(int n): size(n), tree(n+1, 0), array(n+1, 0){}
    
    //usar update para cada valor de um array
    //update = O(log N)
    //build = O(N log N)
    /*
    BIT(vector<long long>& arr){ //O(N log N)
    size = arr.size();
    tree.assigment(size+1, 0);
    for(int i = 0; i<arr.size(); i++){
        update(i+1, arr[i]);
        }   
    }
        
    */
       
    BIT(vector<long long> arr){
        size = arr.size();
        array = vector<long long>(arr.begin(), arr.end());
        tree = arr;
        
        for(int i =1; i<=size; i++){
            int j = i + lsb(i);
            if(j <= size){
                tree[j] += tree[i];
            }
        }
    }
    
    vector<long long> getTree(){
        return tree;
    }
    
    //atualiza idx + diferença entre (value - arr[idx])
    void incrementUpdate(int idx, int delta){
        while(idx <= size){
            tree[idx] += delta;
            idx += lsb(idx);
        }
    }
    
    void update(int idx, long long value){
        incrementUpdate(idx, array[idx] - value);
        array[idx] = value;
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
    
    long long rangeQuery(int init, int end){
        return query(end) - query(init-1);
    }
    
    
};

