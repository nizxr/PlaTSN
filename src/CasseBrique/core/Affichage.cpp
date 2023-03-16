#include"Affichage.h"
#include<iostream>
#include<cassert>
using namespace std;

const int dimx = 640;
const int dimy = 480;

Fenetre::Fenetre(){
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "erreur d'initialisation" << endl;
    }

    window = SDL_CreateWindow(
        "CasseBrique",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        dimx,
        dimy,
        SDL_WINDOW_SHOWN
    );
    if (!window) {
        cout << "erreur creatioon de fenetre" << endl;
    }

    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED
    );
    if(!renderer) {
        cout << "erreur creation du renderer" << endl;
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);


}

Fenetre::~Fenetre(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

Pixel& Fenetre::getPix(unsigned int x, unsigned int y) const {
    assert(x < dimx && y < dimy);
    return tab[y * dimx + x];
};

void Fenetre::setPix(unsigned int x, unsigned int y, const Pixel& couleur){
    assert(x < dimx && y < dimy);
    Pixel &p = getPix(x, y);
    p.setBleu(couleur.getBleu());
    p.setRouge(couleur.getRouge());
    p.setVert(couleur.getVert());
}



void Fenetre::dessinerRectangle(unsigned int Xmin, unsigned int Ymin, unsigned int Xmax,  unsigned int Ymax, const Pixel& couleur)
{
    assert(Xmin >= 0 && Ymin >= 0);
    assert(Xmax < dimx && Ymax < dimy);
    unsigned int i, j;
    for (i = Xmin; i < Xmax; i++)
    {
        for (j = Ymin; j < Ymax; j++)
        {
            setPix(i, j, couleur);
        }
    }
}