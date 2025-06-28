#ifndef DINAMICO_HPP
#define DINAMICO_HPP

#include "Grafo.hpp"
#include <vector>
#include <limits>

class Dinamico
{
private:
    // @brief Referência constante para o grafo utilizado pelo algoritmo de programação dinâmica.
    const Grafo& grafo;
    
    // @brief Tabela de programação dinâmica para armazenar as distâncias mínimas entre cidades.
    std::vector<std::vector<size_t>> dp;
    
    // @brief Tabela para reconstruir o caminho após o cálculo da distância mínima.
    std::vector<std::vector<size_t>> caminho;

    // @brief Função recursiva que resolve o problema do Caixeiro Viajante utilizando programação dinâmica.
    // @param mascara Máscara de bits que representa as cidades visitadas.
    // @param cidadeAtual Cidade atualmente sendo visitada.
    // @return A menor distância encontrada para o caminho a partir da cidadeAtual com as cidades visitadas especificadas pela máscara.
    size_t tsp(size_t mascara, size_t cidadeAtual);
    
    // @brief Reconstrói o caminho ótimo utilizando as tabelas de programação dinâmica.
    // @param mascara Máscara de bits que representa as cidades visitadas.
    // @param cidadeAtual Cidade atualmente sendo visitada.
    // @param rota Vetor onde o caminho será armazenado.
    void reconstroiCaminho(size_t mascara, size_t cidadeAtual, std::vector<size_t>& rota);

public:
    // @brief Construtor da classe Dinamico, recebe o grafo a ser utilizado pelo algoritmo.
    // @param grafo Referência para o grafo a ser utilizado.
    explicit Dinamico(const Grafo& grafo);

    // @brief Encontra o menor caminho possível entre todas as cidades utilizando programação dinâmica.
    // @return A distância total do menor caminho encontrado.
    size_t findMenorCaminho();
};

#endif