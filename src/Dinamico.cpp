#include "Dinamico.hpp"
#include <iostream>
#include <limits>

Dinamico::Dinamico(const Grafo& grafo) : grafo(grafo){
    size_t n = grafo.getNumCidades();
    dp.assign(1 << n, std::vector<size_t>(n, std::numeric_limits<size_t>::max())); // Use max em vez de -1
    caminho.assign(1 << n, std::vector<size_t>(n, std::numeric_limits<size_t>::max())); // Use max em vez de -1
}

// TSP com Programação Dinâmica e com bitmasking

size_t Dinamico::tsp(size_t mascara, size_t cidadeAtual){
    if (mascara == (static_cast<size_t>(1) << static_cast<size_t>(grafo.getNumCidades())) - 1){
        return grafo.getDistancia()[cidadeAtual][0]; // Cidade inicial
    }

    if (dp[mascara][cidadeAtual] != std::numeric_limits<size_t>::max()){
        return dp[mascara][cidadeAtual];
    }

    size_t distanciaMinima = std::numeric_limits<size_t>::max();
    size_t proximaCidade = std::numeric_limits<size_t>::max(); // Inicializa com max

    for (size_t proximo = 0; proximo < grafo.getNumCidades(); proximo++){
        if (!(mascara & (1 << proximo))){
            size_t novaDistancia = grafo.getDistancia()[cidadeAtual][proximo] + tsp(mascara | (1 << proximo), proximo);
            if (novaDistancia < distanciaMinima) {
                distanciaMinima = novaDistancia;
                proximaCidade = proximo; // Armazena a próxima cidade
            }
        }
    }
    caminho[mascara][cidadeAtual] = proximaCidade; // Armazenando o próximo passo para posterior uso
    
    return dp[mascara][cidadeAtual] = distanciaMinima;
}

void Dinamico::reconstroiCaminho(size_t mascara, size_t cidadeAtual, std::vector<size_t>& rota) {
    rota.push_back(cidadeAtual);
    size_t proximaCidade = caminho[mascara][cidadeAtual];

    if (proximaCidade == std::numeric_limits<size_t>::max()) return; // Verifica com max

    reconstroiCaminho(mascara | (1 << proximaCidade), proximaCidade, rota);
}

size_t Dinamico::findMenorCaminho(){
    size_t distanciaMinima = tsp(1, 0); 

    std::vector<size_t> melhorCaminho;
    reconstroiCaminho(1, 0, melhorCaminho);

    std::cout << distanciaMinima << std::endl;
    for (size_t cidade : melhorCaminho) {
        std::cout << grafo.getNomeCidade(cidade) << " ";
    }
    std::cout << std::endl;

    return distanciaMinima;
}
