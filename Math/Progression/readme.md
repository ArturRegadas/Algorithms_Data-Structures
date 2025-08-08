# Progressão Aritmética (PA) e Progressão Geométrica (PG)

Este documento explica os conceitos básicos de **Progressão Aritmética (PA)** e **Progressão Geométrica (PG)**, suas fórmulas principais e exemplos práticos.

---

## 1. Progressão Aritmética (PA)

Uma **Progressão Aritmética** é uma sequência numérica onde a diferença entre termos consecutivos é constante.

Essa diferença constante é chamada de **razão (r)** da PA.

### Definição

Se a1 é o primeiro termo e r é a razão, os termos da PA são:

a1, a1 + r, a1 + 2r, a1 + 3r, ...

### Fórmula do termo geral

O termo n (an) é dado por:

an = a1 + (n - 1) × r

### Soma dos n primeiros termos

A soma dos n primeiros termos (Sn) é:

Sn = (n / 2) × (a1 + an)

ou

Sn = (n / 2) × [2 × a1 + (n - 1) × r]

### Exemplo

Considere a PA: 2, 5, 8, 11, ...

- a1 = 2  
- r = 3

- O 5º termo é:  
  an = 2 + (5 - 1) × 3 = 2 + 12 = 14

- Soma dos 5 primeiros termos:  
  Sn = (5 / 2) × (2 + 14) = (5 / 2) × 16 = 40

---

## 2. Progressão Geométrica (PG)

Uma **Progressão Geométrica** é uma sequência numérica onde a razão entre termos consecutivos é constante.

Essa razão constante é chamada de **razão (q)** da PG.

### Definição

Se a1 é o primeiro termo e q é a razão, os termos da PG são:

a1, a1 × q, a1 × q², a1 × q³, ...

### Fórmula do termo geral

O termo n (an) é dado por:

an = a1 × q^(n - 1)

### Soma dos n primeiros termos

A soma dos n primeiros termos (Sn) é:

- Se q ≠ 1:  
  Sn = a1 × (qⁿ - 1) / (q - 1)

- Se q = 1:  
  Sn = n × a1

### Exemplo

Considere a PG: 3, 6, 12, 24, ...

- a1 = 3  
- q = 2

- O 5º termo é:  
  an = 3 × 2^(5 - 1) = 3 × 16 = 48

- Soma dos 5 primeiros termos:  
  Sn = 3 × (2⁵ - 1) / (2 - 1) = 3 × (32 - 1) / 1 = 3 × 31 = 93

---

## Resumo

| Conceito                | Fórmula do termo geral         | Fórmula da soma dos n primeiros termos        |
|-------------------------|-------------------------------|-----------------------------------------------|
| Progressão Aritmética    | an = a1 + (n - 1) × r         | Sn = (n / 2) × (a1 + an)                       |
| Progressão Geométrica    | an = a1 × q^(n - 1)           | Sn = a1 × (qⁿ - 1) / (q - 1), para q ≠ 1      |

---

