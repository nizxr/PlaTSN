#ifndef _CASSEBRIQUE_H
#define _CASSEBRIQUE_H
#include"Balle.h"
#include"Planche.h"
#include"Brique.h"

///@brief Variables globales
const int NB_BALLES_MAX = 5;
const int NB_BRIQUES_MAX = 25;


/**
 * @class Classe du Casse Brique principale
 * 
 */
class CasseBrique{
private:
    /// @brief Tableau de Balle qui sera utilisé pour affichés plusieurs balles.
    Balle b[NB_BALLES_MAX];

    /// @brief Une planche
    Planche p;

    /// @brief La grille de briques qu'il faudrait detruire pour remporter la partie
    Brique grille[NB_BRIQUES_MAX][NB_BRIQUES_MAX];

    /// @brief Nombre de briques qu'il reste à detruire
    int nbBriquesUtil;

    /// @brief Score du jeu
    int score;

    /// @brief Nombre de vies restant
    int nbVies;

    /// @brief Temps écoulé
    float temps;

    /// @brief Position de la souris dans l'ecran
    /// @param posSourisX Position selon l'axe x
    /// @param posSourisY Position selon l'axe y
    int posSourisX;
    int posSourisY;

public:
    /// @brief Fonction permettant de générer les briques d'une façon aléatoire pour que les stages ne soient pas identiques.
    /// @param tab_briques La grille.
    /// @param nbBriquesUtil Le nombre de Briques utilisées.
    /// @param nbBriquesVisibles Le nombre de briques visibles
    void generateur_briques(Brique tab_briques[NB_BRIQUES_MAX][NB_BRIQUES_MAX],
                                int nbBriquesUtil, int nbBriquesVisibles);

    /// @brief Constructeur par default qui servira d'initialiser le jeu
    CasseBrique();
    
    /// @brief Fonction de mises à jour de l'environement ie mouvements, collisions, gain & perte de score, destruction de briques.
    void update();
};

#endif