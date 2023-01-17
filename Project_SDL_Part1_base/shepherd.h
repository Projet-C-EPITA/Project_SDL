#define SHEPHERD_H
#ifndef SHEPHERD_H

#include "move_player.h"
#include <SDL2/SDL.h>

float X_pos = rand() % frame_width + 1; // position X de l'animal (aleatoire)
float Y_pos = rand() % frame_height + 1;

class shepherd : public move_player
{
private:
    SDL_Surface *image_ptr_;
    SDL_Surface *window_surface_ptr_;

protected:
    SDL_Surface *image_;

public:
    SDL_Rect pos;
    /*
        SDL_Surface* get_image_ptr();
    */
    shepherd(const std::string &file_path, SDL_Surface *window_surface_ptr);
    ~shepherd();
    void draw();
    void move(int x, int y);
    void Set_Event(SDL_Event ev);
}

#endif // SHEPHERD_H