#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <vector>
#include <limits>
#include <unordered_map>
#include <string>

class Grafo
{
private:
    // @brief Mapeamento reverso de índices para os nomes das cidades.
    std::vector<std::string> indiceToCidade; 
    
    // @brief Matriz de adjascência para as distâncias entre as cidades.
    std::vector<std::vector<size_t>> distancias; 

public:
    // @brief Construtor padrão para o grafo.
    Grafo();
    
    // @brief Construtor para o grafo, onde o número de cidades é especificado.
    // @param numCidades Número de cidades no grafo.
    Grafo(size_t numCidades);

    // @brief Destruidor da classe Grafo.
    ~Grafo();

    // @brief Adiciona uma cidade ao grafo.
    // @param cidade Nome da cidade a ser adicionada.
    void addCidade(const std::string& cidade);
    
    // @brief Adiciona uma aresta entre duas cidades com o peso especificado.
    // @param cidade1 Primeira cidade da aresta.
    // @param cidade2 Segunda cidade da aresta.
    // @param peso Peso da aresta (distância entre as cidades).
    void addArestas(const std::string& cidade1, const std::string& cidade2, size_t peso);

    // @brief Obtém a matriz de distâncias entre as cidades.
    // @return Const referência para a matriz de distâncias.
    const std::vector<std::vector<size_t>>& getDistancia() const;
    
    // @brief Obtém o número de cidades no grafo.
    // @return Número de cidades.
    size_t getNumCidades() const;

    // @brief Obtém o nome da cidade dado um índice.
    // @param indice Índice da cidade.
    // @return Nome da cidade.
    std::string getNomeCidade(size_t indice) const;

    // @brief Exibe a matriz de adjascência do grafo.
    void display();

    // @brief Verifica se uma cidade existe no grafo.
    // @param cidade Nome da cidade a ser verificada.
    // @return Verdadeiro se a cidade existe, falso caso contrário.
    bool cidadeExiste(const std::string& cidade) const;

    // @brief Mapeamento direto dos nomes das cidades para os índices.
    std::unordered_map<std::string, size_t> cidadeToIndice;
};

#endif