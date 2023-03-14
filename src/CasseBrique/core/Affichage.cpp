#include"Affichage.h"
#include<iostream>
using namespace std;


Fenetre::Fenetre(){
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "erreur d'initialisation" << endl;
    }

    window = SDL_CreateWindow(
        "CasseBrique",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
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
