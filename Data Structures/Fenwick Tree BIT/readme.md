# Fenwick Tree BIT (Binary Indexed Tree)

Uma BIT (Binary Indexed Tree) é uma estrutura de dados utilizada principalmente para alteração em um array cujo indices dependem dos valores anteriores, no caso usarei o exemplo da soma entre ranges (intervalos)

A BIT é simples de implementar, principalmente comparado com outras estruturas como segTree ou SparseTable, por isso para esses tipos de problema é prefirivel utilizar uma BIT

## LSB (Least Significant Bit)
Na tradução literal significa bit menos significativo em termos tecnicos é o bit mais a direita de um numero, exemplo:

6 -> 0110 o bit no penultimo indice é o lsb, como ele tem valor 2 o lsb(6) = 2

7 -> 0111 no caso o bit no ultimo indice é o lsb, ele tme valor 1, lsb(7) = 1

8 -> 1000 no caso o bit no primeiro indice é o lsb, ele tem valor 8, lsb(8) = 8

Todos numero potencias de 2 tem lsb(x) == x. O contexto de lsb é importante para entender para comprender a relação de parentesco em uma BIT;

```cpp
int lsb(int n){
    return (n & -n);
}
```

## Relação
A BIT usada sera a mais simples, uma por meio de array(n + 1) n -> tamanho do array de querrys, em termos matematicos:

                 i
    BIT[i]=      ∑  arr[k] 
            k=i−lsb(i)+1
    // BIT e arr indexado em 1

![parents](/Local/BITParents.png)

Na imagem é visivel a relação de parentesco e soma, por exemplo a BIT de indice referente à 4 tem a soma de todos os valores do indice 1 ao 4, na imagem mostra todas as relações

Codigo para compreender melhor:
```cpp
// O(N Log N), existe em O(N)
#include <iostream>
using namespace std;
int main(){
    int a[6] = {0, 5, 3, 7, 9, 6};
    int b[6]={0};
    for(int i = 1; i<=5; i++){
        for(int k = i-lsb(i)+1; k<=i; k++)
            b[i] += a[k];
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;
}
```

ou seja iremos apenas incrementar seus pais (lsb) e nao todos como em uma prefixSum

## Update

Comprendendo o update, é fato que ja compreendeu a relação da BIT, no update alteraremos o valor e todos os seus pais

```cpp
//delta = arr[i] - value
void incrementUpdate(int idx, long long delta){
    while(idx <= size){
        tree[idx] = delta;
        idx += lsb(idx);
    }
}

void update(int idx, long long value){
    incrementUpdate(idx, array[idx] - value);
    array[idx] = value;
}
```

Atualizamos o indice e todos os pais do indice com valor anterior + novo valor e a difenrença entre valor anterior do array

## Querry
Como na pratica uma BIT funciona como uma prefixSum a soma de valor de [i, n]  = SomaDePrefixosDe(n) - SomaDePrefixosDe(i)

A BIT ja esta montada entretanto é necessario percorrer a BIT já que BIT[i] != SomaDePrefixosDe(i)

```cpp
long long querry(int idx){
    long long ans = 0;
    while(idx > 0){
        ans+=tree[idx];
        idx -= lsb(idx);
    }
    return ans;
}
long long rangeQuerry(int init, int end){
    return querry(end) - querry(init - 1);
}
```
De maneira abstrata, é realizado o oposto do update, a soma sera incrementada de todos os seus filhos, caminharemos apenas pelos filhos chaves

## Variantes
Alem do exercicio de soma em intervalos existem outros problemas que podem ser utilizados com BIT, a seguir os principais

### Numero de Inversões
Dado um vetor A contabilizar quantidade de inversões-pares em que (A[i] > A[j]) e (i < j)-

    A = {8, 4, 2, 1}
    inverões = {
        {8, 4},
        {8, 2},
        {8, 1},
        {4, 2},
        {4, 1},
        {2, 1}
    }

No caso esse vetor esta ordenado e nao possui valores iguais entao a quantidade de inversões é a soma de 1 até n, tal que n -> tamanho do vetor

```cpp
#include "BIT.cpp"
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> sortedUnique(vector<int> arr){
    set<int> sans(arr.begin(), arr.end());
    return vector<int>(sans.begin(), sans.end());
}

int main(){
    int inversions = 0;
    int current_rank;
    vector<int> nums = {8, 4, 2, 1};

    /*
    sera armazenada na bit a quantidade
    de elementos menor que x ja foram encontradas
    ate o momento
    */
    BIT bit(nums.size());

    vector<int> sorted_unique = sortedUnique(nums);

    //valor, indice
    unordered_map<int, int> rank;
    for(int i = 0; i<nums.size(); i++)
        rank[sorted_unique[i]] = i+1;
    
    // necessario inverter ja que i < j, por conta da progressao de i -> j,
    // invertemos a ordem de j -> i;
    vector<int> reversed_nums = vector<int>(nums.rbegin(), nums.rend());
    for(int i : reversed_nums){
        current_rank = rank[i];

        // querry conta quantos sao menores ate o rank atual
        inversions += (int)bit.query(current_rank-1);
        bit.incrementUpdate(current_rank, 1);
    }

    printf("%d\n", inversions);

    return 0;
}
```

### Frequencias
Saber quantos numeros dentro de um range são menores ou iguais a x

```cpp
// nesse problema seria possivel implementar um constructor em O(N)
// seria necessario apenas mudar a estrutura de BIT para incrementar + 1
// nos exercicios nao tem problema fazer em O(N log N) por que no fundo 
// vai ser O(N log N) nao vai mudar muito o fato de fazer um constructor em tempo linear
#include <algorithm>
#include "BIT.cpp"
#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> sortedUnique(vector<int> arr){
    set<int> sans(arr.begin(), arr.end());
    return vector<int>(sans.begin(), sans.end());
}

class DynamicRank{
    private:
    vector<int> sorted_unique;
    BIT bit;

    public:
    DynamicRank(vector<int> a){
        sorted_unique = sortedUnique(a);
        bit = BIT(a.size());
    }

    int rank(int n){
        int pos = lower_bound(sorted_unique.begin(),sorted_unique.end(),n) - sorted_unique.begin();
        return bit.query(pos);
    }

    void insert(int value){
        int pos = lower_bound(sorted_unique.begin(), sorted_unique.end(), value) - sorted_unique.begin() + 1;
        bit.incrementUpdate(pos, 1);
    }

};

int main(){
    vector<int> nums = {5, 1, 2, 7, 5};
    DynamicRank dr(nums);

    for(int i : nums)
        dr.insert(i);
    
    cout<<dr.rank(5)<<endl;
    cout<<dr.rank(3)<<endl;
    
    return 0;

}
```







        ​