#include "animal.hh"
#include "SDL_image.h"

void draw(const char* file_path, SDL_Surface* window_surface_ptr){
    SDL_LockSurface(window_surface_ptr);
    SDL_Surface* image = IMG_Load(file_path);
    SDL_RenderCopy();
}


virtual void move(){

}