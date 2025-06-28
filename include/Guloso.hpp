#ifndef GULOSO_HPP
#define GULOSO_HPP

#include "Grafo.hpp"
#include <vector>
#include <limits>
#include <unordered_set>

class Guloso {
public:
    // @brief Construtor da classe Guloso, recebe o grafo a ser utilizado pelo algoritmo.
    // @param grafo Referência para o grafo a ser utilizado.
    explicit Guloso(const Grafo& grafo);

    // @brief Encontra o menor caminho possível entre todas as cidades utilizando o algoritmo guloso.
    // @return A distância total do menor caminho encontrado.
    size_t findMenorCaminho();

private:
    // @brief Referência constante para o grafo utilizado pelo algoritmo guloso.
    const Grafo& grafo;

    // @brief Vetor para armazenar o melhor caminho encontrado pelo algoritmo guloso.
    std::vector<size_t> melhorCaminho;

    // @brief Armazena a menor distância encontrada durante a execução do algoritmo.
    size_t menorDistancia;
};

#endif