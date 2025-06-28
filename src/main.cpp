#include <iostream>
#include <string>
#include <unordered_map>

#include "Grafo.hpp"
#include "ForcaBruta.hpp"
#include "Dinamico.hpp"
#include "Guloso.hpp"

int main()
{
    char tipo;
    size_t numCidades, numArestas;
    std::cin >> tipo;
    std::cin >> numCidades >> numArestas;

    Grafo grafo;
    std::string cidade1, cidade2;
    size_t peso;

    for (size_t i = 0; i < numArestas; i++)
    {
        std::cin >> cidade1 >> cidade2 >> peso;

        grafo.addArestas(cidade1, cidade2, peso);
    }

    // Força bruta
    if (tipo == 'b')
    {
        ForcaBruta fb(grafo);
        fb.findMenorCaminho();
    }
    // Programação Dinâmica
    else if (tipo == 'd')
    {   
        Dinamico dp(grafo);
        dp.findMenorCaminho();
    }
    // Estratégia Gulosa
    else if (tipo == 'g')
    {
        Guloso gp(grafo);
        gp.findMenorCaminho();
    }

    return 0;
}