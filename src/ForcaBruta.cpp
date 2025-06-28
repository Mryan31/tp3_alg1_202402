#include "./ForcaBruta.hpp"

#include <iostream>
#include <limits>

ForcaBruta::ForcaBruta(const Grafo &grafo) : grafo(grafo) {}

void ForcaBruta::geraPermutacao(std::vector<size_t> &caminho, std::vector<bool> &visitado,
                                std::vector<size_t> &atual, size_t &minDistancia,
                                std::vector<size_t> &melhorCaminho)
{
    if (atual.size() == caminho.size())
    {
        // Calcula a distância total do caminho gerado
        size_t distancia = calculaParticaoDistancia(atual);
        if (distancia < minDistancia)
        {
            minDistancia = distancia;
            melhorCaminho = atual; // Salva a melhor rota encontrada
        }
        return;
    }

    for (size_t i = 0; i < caminho.size(); i++)
    {
        if (!visitado[i])
        {
            visitado[i] = true;
            atual.push_back(caminho[i]);

            geraPermutacao(caminho, visitado, atual, minDistancia, melhorCaminho);

            atual.pop_back();
            visitado[i] = false;
        }
    }
}

size_t ForcaBruta::calculaParticaoDistancia(const std::vector<size_t> &caminho) const
{
    const auto &distancias = grafo.getDistancia();
    size_t totalDistancia = 0;

    for (size_t i = 0; i < caminho.size() - 1; ++i)
    {
        totalDistancia += distancias[caminho[i]][caminho[i + 1]];
    }

    // Retorna à cidade de origem
    totalDistancia += distancias[caminho.back()][caminho.front()];
    return totalDistancia;
}

size_t ForcaBruta::findMenorCaminho()
{
    size_t numCidades = grafo.getNumCidades();
    std::vector<size_t> caminho(numCidades);
    for (size_t i = 0; i < numCidades; i++)
        caminho[i] = i;

    size_t minDistancia = std::numeric_limits<size_t>::max();
    std::vector<size_t> melhorCaminho;
    std::vector<bool> visitado(numCidades, false);
    std::vector<size_t> atual;

    geraPermutacao(caminho, visitado, atual, minDistancia, melhorCaminho);

    // Exibir saída no formato desejado
    std::cout << minDistancia << std::endl;
    for (size_t i = 0; i < melhorCaminho.size(); i++)
    {
        std::cout << grafo.getNomeCidade(melhorCaminho[i]);
        if (i < melhorCaminho.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;

    return minDistancia;
}