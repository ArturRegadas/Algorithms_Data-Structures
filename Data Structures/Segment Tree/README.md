# Segment Tree

Uma Segment Tree pode resolver quase todos os problemas relacionados a range, diferentemente de uma [Binary Indexed Tree (BIT)](../Fenwick%20Tree%20BIT/), que não pode pegar o menor número em um range, por exemplo. A lógica/função relacionada à sua necessidade é a única mudança necessária na implementação de diferentes SegTrees.

A maioria das iterações de uma SegTree funciona de maneira extremamente semelhante a uma busca binária, ou seja, uma busca recursiva é feita a partir de um índice requerido usando o meio do range como pivô. Essa recursão tem um relacionamento direto com um respectivo nodo; inclusive, cada nodo corresponde a uma resposta destinada a um range, sendo a raiz o resultado da SegTree para a consulta ```query(0, size() - 1)```, ou seja, o range todo. Entretanto, não existe 1 nodo para todos os resultados possíveis, portanto, para algumas consultas deve-se usar dois nodos para compor o resultado de uma consulta.

A característica primária para compreender essa estrutura de dados é que todas as folhas são respectivas ao array, de forma que a folha mais à esquerda corresponda ao ```array[0]``` e a folha mais à direita ao ```array[array.size() - 1]```, por exemplo. Considerando uma função ```f(p1, p2)``` que corresponde à lógica da sua segtree, os nodos intermediários são ```node[i] = f(node[left], node[right])```.

<img src="https://damiankuras.com/posts/segment-tree/images/seg-tree-update.svg" width="500">

Na imagem a cima a função f -> sum(p1, p2)

## Build

A build usa principalmente a relação de ranges entre o array base e seu respectivo nodo; inclusive, esse é o caso base. Após chegar em uma folha, define-se aquele nodo com o valor do array; depois, o resultado entre os dois irmãos vai sendo atribuído para o respectivo pai de forma recursiva.

```cpp
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
    tree[current_node_index] = f(tree[left_node_index], tree[right_node_index]);
}
```

## Query

A busca de 1 ou 2 nodos que mais se encaixam com a busca é o objetivo em uma query. Queremos o nodo menos profundo cujo range da consulta esteja contido no range respectivo do nodo ```(left >= wanted_left && right <= wanted_right)```. Antes, é importante restringir intervalos inválidos fora do range ```(right < wanted_left || left > wanted_right)```. No caso de apenas um nodo não satisfazer a necessidade do resultado, caso exista outro nodo que abrange outro range não contido no primeiro nodo escolhido, ele deverá ser usado para o resultado.

```cpp
int query(
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
        return EMPTY_NODE;

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

    return f(
        query(
            left_node_index,
            wanted_left_index,
            wanted_right_index,
            current_left_index,
            current_middle_index
        ),
        query(
            right_node_index,
            wanted_left_index,
            wanted_right_index,
            current_middle_index + 1,
            current_right_index
        )
    );
}
```

## Update

A ideia do update é a mais simples: você alterará a folha respectiva ao índice que será alterado; em seguida, os nodos pais terão o resultado dentre os dois filhos.

```cpp
void update(
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
        update(
            left_node_index,
            new_value,
            wanted_index,
            current_left_index,
            current_middle_index
        );
    else
        update(
            right_node_index,
            new_value,
            wanted_index,
            current_middle_index + 1,
            current_right_index
        );
    
    tree[current_node_index] = f(
        tree[left_node_index],
        tree[right_node_index]
    );
}
```

## Lazy Propagation

A técnica de Lazy Propagation em uma SegTree é para resolver o único problema de fazer update de um range, anteriormente em ```O(n log n)``` — com otimização pode ser em ```O(n)``` —, para ```O(log n)```. A ideia de lazy (preguiçoso) é a mais pura definição da técnica, isso porque procrastinamos as mudanças o máximo possível, de forma que em algum momento tudo estará da maneira que deveria estar.

A definição da lazy é de uma nova árvore com tamanho igual ao da Segment Tree, que funciona como marcadores para futuras mudanças. Um exemplo prático:

Abaixo existe uma Segment Tree de RMQ (range minimum query).

Fizemos uma alteração de [1, 3] para 1:

```
        SegTree        NovaSegTree
           2                1
        2     3          1     1
      2   4 6   3      2   1 1   1
```

Com a lazy tree (tenha em mente que 0 -> nulo; a representação é pessoal):

```
        SegTree         Lazy Tree
           2                0
        2     3          0     1
      2   4 6   3      0   1 0   0
```

### Propagation

A hereditariedade dos nodos e o relacionamento entre árvores é feita a partir da função propagation:

```cpp
void propagation(
    int current_node_index,
    int current_left_index,
    int current_right_index
){
    if(lazy[current_node_index] == EMPTY_NODE)
        return;
    
    tree[current_node_index] = lazy[current_node_index];

    int left_node_index = getLeftIndex(current_node_index);
    int right_node_index = getRightIndex(current_node_index);

    if(!isLeaf(current_left_index, current_right_index)){
        lazy[left_node_index] = lazy[current_node_index];
        lazy[right_node_index] = lazy[current_node_index];
    }
    lazy[current_node_index] = EMPTY_NODE;

}
```

Após a propagação, a estrutura geral ficará assim:

```
        SegTree         Lazy Tree
           1                0
        1     1          0     0
      2   1 6   3      0   0 1   1
```

A função de propagação deve ser usada sempre no início das funções para saber se não existe algum nodo pendente para ser alterado.

A ideia também pode ser alterada para outras variantes; nesse exemplo, redefinimos o valor. Pode-se também usar como um agregador (que haverá uma maior mudança caso o problema seja soma de ranges):

```cpp
void propagation(
    int current_node_index,
    int current_left_index,
    int current_right_index
){
    if(lazy[current_node_index] == EMPTY_NODE)
        return;
    
    tree[current_node_index] += lazy[current_node_index]; //* (right - left + 1)
    //                               IMPORTANTE CASO SEJA SOMA DE RANGES COM UPDATE AGREGADO

    int left_node_index = getLeftIndex(current_node_index);
    int right_node_index = getRightIndex(current_node_index);

    if(!isLeaf(current_left_index, current_right_index)){
        lazy[left_node_index] += lazy[current_node_index];
        lazy[right_node_index] += lazy[current_node_index];
    }
    lazy[current_node_index] = EMPTY_NODE;

}
void recursiveRangeUpdate(
    int current_node_index,
    int& wanted_left_index, 
    int& wanted_right_index, 
    int& new_value, 
    int current_left_index, 
    int current_right_index
){
    propagation(
        current_node_index,
        current_left_index, 
        current_right_index
    );

    if (isOutOfRange(
        current_left_index,
        current_right_index,
        wanted_left_index,
        wanted_right_index
    ))
        return;

    if (isFullyInside(
        current_left_index,
        current_right_index,
        wanted_left_index,
        wanted_right_index
    )){
        lazy[current_node_index] = new_value;
        propagation(
            current_node_index,
            current_left_index, 
            current_right_index
        );
        return;
    }

    int current_middle_index = getMiddleIndex(current_left_index, current_right_index);
    int left_node_index = getLeftIndex(current_node_index);
    int right_node_index = getRightIndex(current_node_index);
    recursiveRangeUpdate(
        left_node_index,
        wanted_left_index,
        wanted_right_index,
        new_value,
        current_left_index,
        current_middle_index
    );
    recursiveRangeUpdate(
        right_node_index,
        wanted_left_index,
        wanted_right_index,
        new_value,
        current_middle_index+1,
        current_right_index
    );      
    tree[current_node_index] = min(tree[left_node_index], tree[right_node_index]);
}

int recursiveRangeQuery(
    int current_node_index,
    int& wanted_left_index, 
    int& wanted_right_index, 
    int current_left_index, 
    int current_right_index
){
    propagation(
        current_node_index,
        current_left_index, 
        current_right_index
    );

    if (isOutOfRange(
        current_left_index,
        current_right_index,
        wanted_left_index,
        wanted_right_index
    ))
        return EMPTY_NODE;
    
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
    return min(
        recursiveRangeQuery(
            left_node_index,
            wanted_left_index,
            wanted_right_index,
            current_left_index,
            current_middle_index
        ),
        recursiveRangeQuery(
            right_node_index,
            wanted_left_index,
            wanted_right_index,
            current_middle_index+1,
            current_right_index
        )
    );
}
```