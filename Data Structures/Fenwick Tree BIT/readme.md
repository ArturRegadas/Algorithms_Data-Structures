# Fenwick Tree BIT (Binary Indexed Tree)

Uma BIT (Binary Indexed Tree) é uma estrutura de dados utilizada principalmente para alteração em um array cujo indices dependem dos valores anteriores, no caso usarei o exemplo da soma entre ranges (intervalos)

A BIT é simples de implementar, principalmente comparado com outras estruturas como segTree ou SparseTable, por isso para esses tipos de problema é prefirivel utilizar uma BIT

## LSB (Least Significant Bit)
Na tradução literal significa bit menos significativo em termos tecnicos é o bit mais a direita de um numero, exemplo:

6 -> 0110 o bit no penultimo indice é o lsb, como ele tem valor 2 o lsb(6) = 2

7 -> 0111 no caso o bit no ultimo indice é o lsb, ele tme valor 1, lsb(7) = 1

8 -> 1000 no caso o bit no primeiro indice é o lsb, ele tem valor 8, lsb(8) = 8

Todos numero potencias de 2 tem lsb(x) == x. O contexto de lsb é importante para entender para comprender a relação de parentesco em uma BIT;

## Relação
A BIT usada sera a mais simples, uma por meio de array(n + 1) n -> tamanho do array de querrys, em termos matematicos:

                 i
    BIT[i]=      ∑  arr[k] 
            k=i−lsb(i)+1
    // BIT e arr indexado em 1

Codigo para compreender melhor:
```cpp
// O(N Log N), existe em O(N)
#include <iostream>
using namespace std;
int main(){
    int a[6] = {0, 5, 3, 7, 9, 6};
    int b[6]={0};
    for(int i = 1; i<=5; i++){
        for(int k = i-(i&-i)+1; k<=i; k++)
            b[i] += a[k];
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;
}
```

ou seja iremos apenas incrementar seus pais (lsb) e nao todos como em uma prefixSum

![parents](/Local/BITParents.png)

Na imagem é visivel a relação de parentesco e soma

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






        ​