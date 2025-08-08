# Triângulo de Pascal e Coeficientes Binomiais

---

## 1. O que é o Triângulo de Pascal?

O Triângulo de Pascal é uma disposição triangular de números, onde:

- O topo é sempre 1.
- Cada número no interior é a soma dos dois números localizados logo acima dele.
- As bordas laterais são sempre 1.

---

## 2. Como construir

1. Comece com o número 1 na primeira linha.
2. Coloque 1 nas extremidades de cada linha.
3. Preencha os números do meio somando os dois valores logo acima.

---

## 3. Primeiras linhas

Linha 0:                        1  
Linha 1:                      1   1  
Linha 2:                    1   2   1  
Linha 3:                  1   3   3   1  
Linha 4:                1   4   6   4   1  
Linha 5:              1   5  10  10   5   1  
Linha 6:            1   6  15  20  15   6   1  

---

## 4. Coeficientes Binomiais

Os números do Triângulo de Pascal são chamados **coeficientes binomiais**.

Eles representam o número de maneiras de escolher **k** elementos de um conjunto com **n** elementos, sem se importar com a ordem.


A fórmula é:

pascal[n][k] = n! / (k! × (n - k)!)

escolher k elementos com n elementos = pascal[n][k]

C(n, k) = n! / (k! × (n - k)!)

Onde:
- n = número da linha no Triângulo de Pascal
- k = posição do número na linha (começando do 0)
- ! = fatorial

---

## 5. Exemplo de relação


Linha 4: 1   4   6   4   1  
- C(4, 0) = 1  
- C(4, 1) = 4  
- C(4, 2) = 6  
- C(4, 3) = 4  
- C(4, 4) = 1  

---

## 6. Relação com o Binômio de Newton

O Triângulo de Pascal fornece os coeficientes para a expansão de (a + b)^n.

Exemplo:
(a + b)^3 = 1a³b⁰ + 3a²b¹ + 3a¹b² + 1a⁰b³

Os coeficientes 1, 3, 3, 1 vêm da linha 3 do Triângulo de Pascal.

---

## 7. Aplicações

- Cálculo de combinações
- Expansões binomiais
- Problemas de probabilidade
- Padrões numéricos e sequências

---
