#include "animal.hh"
#include "SDL_image.h"

animal::animal(const char* file_path, SDL_Surface* window_surface_ptr){
    load_surface_for(file_path, window_surface_ptr);
}

void draw(const char* file_path, SDL_Surface* window_surface_ptr){
    SDL_LockSurface(window_surface_ptr);
    SDL_Surface* image = IMG_Load(file_path);
    SDL_RenderCopy();
}


virtual void move(){

}