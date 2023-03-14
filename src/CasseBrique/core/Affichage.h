#include<SDL2/SDL.h>
using namespace std;

class Fenetre {
public:
    Fenetre();
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
    ~Fenetre();
};