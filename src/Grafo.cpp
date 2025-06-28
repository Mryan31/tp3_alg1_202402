#include "Grafo.hpp"

#include <iostream>
#include <iomanip>
#include <stdexcept>

Grafo::Grafo() {};

Grafo::Grafo(size_t numCidades)
{
    distancias.resize(numCidades, std::vector<size_t>(numCidades, std::numeric_limits<size_t>::max()));
}

Grafo::~Grafo() {}

void Grafo::addCidade(const std::string &cidade)
{
    if (cidadeToIndice.find(cidade) == cidadeToIndice.end())
    {
        size_t newIndice = static_cast<size_t>(cidadeToIndice.size());
        cidadeToIndice[cidade] = newIndice;
        indiceToCidade.push_back(cidade);

        for (auto &r : distancias)
        {
            r.push_back(std::numeric_limits<size_t>::max());
        }
        distancias.emplace_back(cidadeToIndice.size(), std::numeric_limits<size_t>::max());

        distancias[newIndice][newIndice] = 0;
    }
}

void Grafo::addArestas(const std::string &cidade1, const std::string &cidade2, size_t peso)
{
    addCidade(cidade1);
    addCidade(cidade2);

    size_t indice1 = cidadeToIndice[cidade1];
    size_t indice2 = cidadeToIndice[cidade2];
    distancias[indice1][indice2] = peso;
    distancias[indice2][indice1] = peso;
}

const std::vector<std::vector<size_t>> &Grafo::getDistancia() const
{
    return distancias;
}

size_t Grafo::getNumCidades() const
{
    return cidadeToIndice.size();
}

void Grafo::display()
{
    // Exibe os cabeçalhos das colunas
    std::cout << "     ";
    for (const auto &city : indiceToCidade)
    {
        std::cout << std::setw(10) << city;
    }
    std::cout << "\n";

    // Exibe as distâncias
    for (size_t i = 0; i < distancias.size(); ++i)
    {
        std::cout << std::setw(10) << indiceToCidade[i];
        for (size_t j = 0; j < distancias[i].size(); ++j)
        {
            if (distancias[i][j] == std::numeric_limits<size_t>::max())
            {
                std::cout << std::setw(10) << "INF";
            }
            else
            {
                std::cout << std::setw(10) << distancias[i][j];
            }
        }
        std::cout << "\n";
    }
}

bool Grafo::cidadeExiste(const std::string &cidade) const
{
    return cidadeToIndice.find(cidade) != cidadeToIndice.end();
}

std::string Grafo::getNomeCidade(size_t indice) const
{
    return indiceToCidade[indice];
}