# Permutações e Função Fatorial

Este documento explica de forma clara e detalhada o conceito de **fatorial** e **permutação**, incluindo casos com e sem repetição.

---

## 1. Função Fatorial (!)

O **fatorial** de um número natural *n*, indicado por *n!*, é o produto de todos os números inteiros positivos de 1 até *n*.

**Definição formal:**

n! = n × (n - 1) × (n - 2) × ... × 3 × 2 × 1

**Exemplos:**

3! = 3 × 2 × 1 = 6

5! = 5 × 4 × 3 × 2 × 1 = 120

Por definição:

0! = 1

Isto é definido para manter a consistência das fórmulas.

⚠ **Crescimento rápido do fatorial:**

6! = 720

10! = 3.628.800

---

## 2. Permutações

Uma **permutação** é um arranjo **de todos os elementos** de um conjunto em uma ordem específica.

💡 **Exemplo intuitivo:** Se tenho 3 livros diferentes e quero colocá-los em uma prateleira, quantas formas diferentes posso organizá-los?

Para *n* elementos **todos diferentes**, o número de permutações possíveis é:

P(n) = n!

**Exemplo:**

- Conjunto: {A, B, C}  
- Permutações possíveis:  
  ABC  
  ACB  
  BAC  
  BCA  
  CAB  
  CBA

**Total:** 3! = 6 arranjos.

---

## 3. Permutação com Repetição

Se alguns elementos se repetem, o cálculo muda.

Se temos *n* elementos, com *n₁* elementos repetidos de um tipo, *n₂* elementos repetidos de outro tipo, etc., a fórmula é:

P(n; n₁, n₂, ...) = n! ÷ (n₁! × n₂! × ...)

**Exemplo:**

- Palavra: **"ANA"**

- Total de letras: n = 3  
- Número de repetições da letra A: n₁ = 2  
- Número de repetições da letra N: n₂ = 1

Número de permutações:

P = 3! ÷ 2! = 6 ÷ 2 = 3

**Permutações distintas:**

- ANA  
- AAN  
- NAA  

---

## 4. Ligação entre Fatorial e Permutações

- **Todos os elementos diferentes:**

P(n) = n!

- **Elementos repetidos:**

P(n; n₁, n₂, ...) = n! ÷ (n₁! × n₂! × ...)

---

## 📌 Resumo

- O **fatorial** é a base para calcular permutações.  
- O crescimento do fatorial é exponencialmente rápido.  
- Permutações com elementos repetidos exigem a divisão pelo fatorial das repetições.

---
