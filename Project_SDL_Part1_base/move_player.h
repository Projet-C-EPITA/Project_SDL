#define MOVE_PLAYER_H
#ifndef MOVE_PLAYER_H

#include <SDL2/SDL.h>

// Classe élément jouable avec des interactions
// Pas besoin de constructeur / destructeur
class move_player
{
private:
    float x;
    float y;
    float speed;
    int dirx;
    int diry;
    SDL_Event action;

public:
    void draw_player(SDL_Render *window_render_, SDL_Surface *window_surface_ptr_, const char *file_path)
    {
        SDL_Surface *image = IMG_Load(file_path);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(window_renderer_, image);
        SDL_Rect rect = {5, 5, 62, 42};
        SDL_BlitSurface(image, NULL, window_surface_ptr_, NULL);
    }

    int get_x();
    int get_y();
    int get_dirx();
    int get_diry();
    void set_x(int x);
    void set_y(int y);
    void move();
}

#endif // MOVE_PLAYER_H