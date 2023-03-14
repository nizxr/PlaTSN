#include"Affichage.h"

int main(void){
    Fenetre f;

    bool quit = false;
    while(!quit) {
        while(SDL_PollEvent(&f.event)) {
            if (f.event.type == SDL_QUIT)
            quit = true;
        }
    }

    return 0;
}