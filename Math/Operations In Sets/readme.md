# Operações de Conjuntos com `std::unordered_set`

Este documento descreve as quatro operações clássicas da teoria dos conjuntos, aplicadas ao `std::unordered_set` do C++.  
Cada operação é explicada com:
- **Definição** matemática
- **Ideia** de implementação
- **Pseudocódigo**
- **Complexidade**

---

## 1️⃣ União (`A ∪ B`)

**Definição:** Todos os elementos que estão em `A` ou em `B`, sem repetição.

**Ideia:**
1. Começar com todos os elementos de `A`.
2. Inserir todos os elementos de `B` no conjunto.
3. Como `unordered_set` não permite duplicatas, elementos repetidos são ignorados automaticamente.

**Pseudocódigo:**

```cpp
função UNIAO(A, B):
    resultado ← cópia de A
    para cada elemento e em B:
        resultado.inserir(e)
    retornar resultado
````

**Complexidade:**
- **Esperada:** `O(n + m)`

---

## 2️⃣ Interseção (`A ∩ B`)

**Definição:** Todos os elementos que estão **em ambos** `A` e `B`.

**Ideia:**
1. Escolher o menor conjunto para iterar (mais eficiente).
2. Para cada elemento, verificar se também está no outro conjunto.
3. Se estiver, inserir no resultado.

**Pseudocódigo:**

```cpp
função INTERSECAO(A, B):
    resultado ← conjunto vazio
    menor, maior ← (A, B) ou (B, A) baseado no tamanho
    para cada elemento e em menor:
        se maior.contem(e):
            resultado.inserir(e)
    retornar resultado
```


**Complexidade:**
- **Esperada:** `O(min(n, m))`
- **Pior caso:** `O(n × m)`

---

## 3️⃣ Diferença (`A − B`)

**Definição:** Todos os elementos que estão em `A` e **não** estão em `B`.

**Ideia:**
1. Iterar sobre `A`.
2. Inserir no resultado apenas elementos que não estão em `B`.

**Pseudocódigo:**
```cpp
função DIFERENCA(A, B):
    resultado ← conjunto vazio
    para cada elemento e em A:
        se NÃO B.contem(e):
            resultado.inserir(e)
    retornar resultado
```

**Complexidade:**
- **Esperada:** `O(n)`

---

## 4️⃣ Diferença Simétrica (`A ⊕ B`)

**Definição:** Elementos que estão em `A` ou em `B`, mas **não em ambos**.

**Ideia:**
1. Adicionar ao resultado os elementos de `A` que não estão em `B`.
2. Adicionar ao resultado os elementos de `B` que não estão em `A`.

**Pseudocódigo:**

```cpp
função DIFERENCA_SIMP(A, B):
    resultado ← conjunto vazio
    para cada elemento e em A:
        se NÃO B.contem(e):
            resultado.inserir(e)
    para cada elemento e em B:
        se NÃO A.contem(e):
            resultado.inserir(e)
    retornar resultado
```

**Complexidade:**
- **Esperada:** `O(n + m)`

---

## 📌 Observações Finais
- `std::unordered_set` armazena elementos de forma não ordenada e garante unicidade.
- Todas as operações usam `count` ou `insert`, que são `O(1)` em média.
- Em cenários de alto número de colisões no hash, as operações podem degradar para `O(n × m)`.
- Essas mesmas ideias podem ser adaptadas para `std::set` (ordenado), mas com complexidade `O(log n)` por inserção/verificação.
