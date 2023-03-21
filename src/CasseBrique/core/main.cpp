#include"Pixel.h"
#include"Affichage.h"
#include"CasseBrique.h"
#include"Complex.h"

int main(int argc, char const *argv[]){
    Fenetre f;
    CasseBrique cb;
    cb.init();

    //cb.init();

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