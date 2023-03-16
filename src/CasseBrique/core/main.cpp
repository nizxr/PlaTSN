#include"Affichage.h"
#include"CasseBrique.h"

int main(void){
    Fenetre f;
    CasseBrique cb;

    cb.init();

    bool quit = false;
    while(!quit) {
        while(SDL_PollEvent(&f.event)) {
            if (f.event.type == SDL_QUIT)
            quit = true;
        }
        cb.update();
        f.dessinerRectangle(10, 10, 30, 30,Pixel(255,0,0));
    }

    return 0;
}