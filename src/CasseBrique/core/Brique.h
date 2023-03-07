#ifndef _BRIQUE_H
#define _BRIQUE_H
#include"Complex.h"

/**
  @class Classe brique
 */
class Brique{
private:
    /// @brief Coordonnée debut de la brique selon l'axe X.
    Complex positionXmin;
    /// @brief Coordonnée fin dela brique selon l'axe X.
    Complex positionXmax;
    /// @brief Vitesse de mouvement de la brique.
    Complex vitesse;
    /// @brief Indique si la brique est visible ou pas.
    bool etat;   
};

#endif