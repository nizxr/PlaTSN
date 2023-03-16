#include<SDL2/SDL.h>
#include"Pixel.h"
using namespace std;


class Fenetre {
public:
    Fenetre();
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
    ~Fenetre();

    /// @param tab le tableau 2D de pixel
    Pixel * tab;
    
    /** @brief Accesseur : récupère le pixel original de coordonnées (x,y) en vérifiant leur validité
     la formule pour passer d'un tab 2D à un tab 1D est tab[y*dimx+x]
     @return Référence du pixel des cordonnées x,y
     */
    Pixel& getPix(unsigned int x, unsigned int y) const;    

    /// @brief Mutateur : modifie le pixel de coordonnées (x,y)
    void setPix(unsigned int x, unsigned int y, const Pixel& couleur);

    /// @brief Dessine un rectangle plein de la couleur dans l'image (en utilisant setPix, indices en paramètre compris)
    /// @param [in] couleur reference d'un pixel pour faire office de couleur
    /// @param [in] Xmin coin gauche du rectangle
    /// @param [in] Xmax coin droite du rectangle
    /// @param [in] Ymin coin haut
    /// @param [in] Ymax coin bas
    void dessinerRectangle(unsigned int Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax, const Pixel& couleur);


};