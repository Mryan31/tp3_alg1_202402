#include "Guloso.hpp"
#include <iostream>
#include <limits>

Guloso::Guloso(const Grafo& grafo) : grafo(grafo), menorDistancia(std::numeric_limits<size_t>::max()) {}

size_t Guloso::findMenorCaminho() {
    size_t numCidades = grafo.getNumCidades();
    if (numCidades == 0) return 0;

    std::vector<bool> visitado(numCidades, false);
    melhorCaminho.clear();
    menorDistancia = 0;

    size_t cidadeAtual = 0;
    visitado[cidadeAtual] = true;
    melhorCaminho.push_back(cidadeAtual);

    for (size_t i = 1; i < numCidades; ++i) {
        size_t cidadeMaisProxima = -1;
        size_t menorDist = std::numeric_limits<size_t>::max();

        for (size_t j = 0; j < numCidades; ++j) {
            if (!visitado[j] && grafo.getDistancia()[cidadeAtual][j] < menorDist) {
                menorDist = grafo.getDistancia()[cidadeAtual][j];
                cidadeMaisProxima = j;
            }
        }

        if (cidadeMaisProxima != std::numeric_limits<size_t>::max()) {
            visitado[cidadeMaisProxima] = true;
            melhorCaminho.push_back(cidadeMaisProxima);
            menorDistancia += menorDist;
            cidadeAtual = cidadeMaisProxima;
        }
    }
    menorDistancia += grafo.getDistancia()[cidadeAtual][melhorCaminho[0]]; // Retorno ao ponto inicial

    // Exibir o resultado diretamente aqui
    std::cout << menorDistancia << "\n";
    for (size_t cidade : melhorCaminho) {
        std::cout << grafo.getNomeCidade(cidade) << " ";
    }
    std::cout << "\n";

    return menorDistancia;
}