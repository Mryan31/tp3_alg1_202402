#ifndef FORCABRUTA_HPP
#define FORCABRUTA_HPP

#include "Grafo.hpp"

class ForcaBruta
{
public:
    // @brief Referência constante para o grafo utilizado pelo algoritmo de força bruta.
    const Grafo& grafo;

    // @brief Gera todas as permutações possíveis de um caminho entre as cidades.
    // @param caminho Vetor para armazenar o caminho atual.
    // @param visitado Vetor que indica se uma cidade já foi visitada.
    // @param atual Caminho atual sendo analisado.
    // @param minDistancia Referência para a menor distância encontrada até o momento.
    // @param melhorCaminho Referência para o melhor caminho encontrado.
    void geraPermutacao(std::vector<size_t>& caminho, std::vector<bool>& visitado, std::vector<size_t>& atual, size_t& minDistancia, std::vector<size_t>& melhorCaminho);
    
    // @brief Calcula a distância total de uma partição do caminho.
    // @param caminho Vetor contendo a partição do caminho.
    // @return A distância total da partição.
    size_t calculaParticaoDistancia(const std::vector<size_t>& caminho) const;

    // @brief Construtor da classe ForcaBruta, recebe um grafo a ser utilizado pelo algoritmo.
    // @param grafo Referência para o grafo a ser utilizado.
    explicit ForcaBruta(const Grafo& grafo);

    // @brief Encontra o menor caminho possível entre todas as cidades utilizando força bruta.
    // @return A distância total do menor caminho encontrado.
    size_t findMenorCaminho();
};

#endif