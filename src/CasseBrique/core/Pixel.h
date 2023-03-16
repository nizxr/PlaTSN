#ifndef _PIXEL_H
#define _PIXEL_H

/**
 \class Classe Pixel à trois parametre : rouge, vert, bleu.
*/
class Pixel
{
private:
    /// @brief les composantes RGB (0 à 255) du pixel
    /// @param r coeficient rouge
    /// @param g coeficient vert
    /// @param b coeficient bleu 
    unsigned char r, g, b;
public:
   /// @brief Constructeur par défaut de la classe: initialise le pixel à la couleur noire
    Pixel();

   /** 
    @brief Constructeur de la classe: initialise r,g,b avec les paramètres
    @param [in] nr niveau de rouge
    @param [in] ng niveau de vert
    @param [in] nb niveau de bleu
    */
    Pixel(unsigned char nr, unsigned char ng, unsigned char nb);

   /// @brief Accesseur : récupère la composante rouge du pixel
    unsigned char getRouge() const;

   /// @brief Accesseur : récupère la composante verte du pixel
    unsigned char getVert() const;

   /// @brief Accesseur : récupère la composante bleue du pixel
    unsigned char getBleu() const;

   /** @brief Mutateur : modifie la composante rouge du pixel 
    @param [in] nr niveau de rouge
   */
    void setRouge(unsigned char nr);

   /** @brief Mutateur : modifie la composante vert du pixel 
    @param [in] ng niveau de vert
   */
    void setVert(unsigned char ng);
    
    /** @brief Mutateur : modifie la composante vert du pixel 
    @param [in] nb niveau de vert
   */
    void setBleu(unsigned char nb);
};

#endif
