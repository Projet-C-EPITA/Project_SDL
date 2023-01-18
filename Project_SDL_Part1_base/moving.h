#ifndef MOVING_H
#define MOVING_H

#include <SDL2/SDL_surface.h>
#include <cstdint>
#include "utility.h"

enum eDirection
{
    UPLEFT,
    UPRIGHT,
    DOWNRIGHT,
    DOWNLEFT,
    UP,
    DOWN,
    RIGHT,
    LEFT
};

class moving
{

public:
    SDL_Rect pos; // position de l'objet
    eDirection dir;
    long speed;
    bool alive; // If true alive else die

    float x;
    float y;
    int dirX;
    int dirY;

    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    int getDirX();
    int getDirY();

    SDL_Surface *window_surface_ptr_;
    SDL_Surface *image_;

    moving(const std::string &file_path, SDL_Surface *window_surface_ptr);
    moving() = default;
    ~moving() = default;

    // virtual void move() = 0;
    int get_position();
};

#endif // MOVING_H