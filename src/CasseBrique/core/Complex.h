#ifndef _COMPLEX_H
#define _COMPLEX_H

/**
    @class Classe qui permet de gérer les Complex, utilisé pour les interactions et les mouvements.
*/
class Complex {
 private:
    /// @brief un nombre complex s'ecrit comme C = x + iy
    /// @param x la coordonnée selon l'axe x
    /// @param y la coordonnée selon l'axe y
    float x, y;

public:
    /// @brief Construire un complex à partir des deux parametres passés
    /// @param a partie réelle du nombre complex
    /// @param b partie imaginaire du nombre complex
    /// @return un nombre complex C = a + ib
    Complex make_complex(float a, float b) const;

    Complex operator+(const Complex &c) const;

    Complex operator-(const Complex &c) const;

    Complex operator*(const Complex &c) const;

    Complex operator*(float lambda) const;

};

#endif