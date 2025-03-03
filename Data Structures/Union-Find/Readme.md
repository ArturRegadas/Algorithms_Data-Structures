# Union-Find

Union-Find é uma estrutura de dados que trabalha com a união de conjuntos e a procura de um item em um conjunto

## Quick-Find
Find tem complexidade O(1) e o Union O(n) isso porque definimos um representante para cada conjunto, e para mudar o representante de um dos subconjuntos sera necessario percorrer o conjunto inteiro

## Quick-Union
Find tem complexidade O(n) e Union O(2n) já que usa o find 2 vezes, nao temos mais um representante, agora temos uma arvore cujo nodo raiz tem valor dele mesmo, o union atribui ao nodo raiz de x o nodo raiz de y, assim formando uma outra subarvore

## Weighted Quick-Union
Find tem complexidade O(log n) e union o(2logn) já que usa o find 2 vezes, sua estrutura é igual ao Quick-Union, entretanto agora a arvore terá sempre a menor profundidade possivel, entao sempre colocaremos a menor arvore na maior, balanceando a arvore principal

