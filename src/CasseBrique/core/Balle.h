#ifndef _BALLE_H
#define _BALLE_H
#include"Complex.h"


/**
 * @class Classe Balle
 */
class Balle {
public:
    /// @brief Constructeur
    Balle();

    /// @brief Rayon
    float r;

    ///@brief Position de la balle.
    Complex position;

    ///@brief Vitesse de la balle.
    Complex vitesse;
};

#endif