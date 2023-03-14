#ifndef _MEMORY_H
#define _MEMORY_H

#include <iostream>
#include <vector>

/// @class classe memory

class Memory
{
private:

    /// @brief nombre de cartes
    int nb_cartes;

    /// @brief tableau de cartes
    std::vector<int> cartes; 

    /// @brief visibilite des cartes
    std::vector<bool> bool_cartes;

    /// @brief numero de chances
    int chance;

public:
    Memory(int num_cards);
    void guess(int card_idx);
    bool is_game_over();
    void play();

    /// @brief Constructeur
    Memory();

    /// @brief Fonction permettant de montrer les cartes au tout debut
    void montrer();

    /// @brief Fonction permettant de savoir si une carte est revelee
    /// @param col 
    /// @param lig 
    bool reveler(int col, int lig);

    /// @brief Fonction permettant de savoir si les deux cartes selectionnees sont une paire 
    /// @param col1 
    /// @param lig1 
    /// @param col2 
    /// @param lig2 
    bool paire(int col1, int lig1, int col2, int lig2);
    
};

#endif