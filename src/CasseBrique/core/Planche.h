#ifndef _PLANCHE_H
#define _PLANCHE_H
#include"Complex.h"

/**
 * @class Classe Planche
 * 
 */
class Planche {
public:
    int getTaille() const;
    Complex getPosMin() const;
    Complex getPostMax() const;

    /// @brief Constructeur
    Planche();

    ///@brief Coordonnée debut de la planche selon l'axe X.
    Complex positionXmin;

    /// @brief Coordonnée fin de la planche selon l'axe X.
    Complex positionXmax;

    /// @brief Taille de la planche.
    float taille;
};


#endif