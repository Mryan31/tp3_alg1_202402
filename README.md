# 🚚 Planejamento de Rota para Distribuição — TSP com Abordagens Comparativas

Este projeto foi desenvolvido como parte do Trabalho Prático 3 da disciplina **Algoritmos 1 (DCC/UFMG)**. Ele simula o planejamento de rotas de entrega de uma empresa fictícia, **DelivExpress**, resolvendo uma variação do problema do caixeiro viajante (TSP - *Travelling Salesman Problem*) com três abordagens distintas de algoritmos.

## 📘 Enunciado

O objetivo é definir a melhor cidade para estabelecer um ponto central de distribuição e determinar a menor rota possível que passa por todas as cidades da região uma única vez e retorna à cidade de origem.

Para isso, o programa implementa e compara três estratégias de solução:

1. **Força Bruta (b)** — Testa todas as permutações possíveis para encontrar a solução ótima. É inviável para grandes instâncias.
2. **Programação Dinâmica (d)** — Utiliza a técnica de *Held-Karp* para armazenar subsoluções e reduzir a complexidade de tempo.
3. **Algoritmo Guloso (g)** — Gera uma solução aproximada de forma eficiente, escolhendo o melhor vizinho a cada passo.

## 💻 Tecnologias utilizadas

- Linguagem: **C++ (padrão C++17)**
- Entrada/Saída: `cin` e `cout`
- Compilação: `g++` com flags exigidas pela disciplina

## ⚙️ Compilação

Para compilar o programa, use:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic -Wformat-security -Wconversion -Werror -o tp3 main.cpp
