#ifndef MOVING_H
#define MOVING_H

#include <SDL2/SDL_surface.h>

#include <cstdint>

#include "utility.h"


enum eDirection {UPLEFT, UPRIGHT, DOWNRIGHT, DOWNLEFT, UP, DOWN, RIGHT, LEFT, RIGHT_BOOST, LEFT_BOOST, UP_BOOST, DOWN_BOOST, UPLEFT_BOOST, UPRIGHT_BOOST, DOWNRIGHT_BOOST, DOWNLEFT_BOOST};

class moving{
    
        
    public:
        SDL_Rect pos; //position de l'objet
        eDirection dir;
        long speed;
        bool alive; // If true alive else die
   
    SDL_Surface* window_surface_ptr_;
	SDL_Surface * image_;

    moving(const std::string &file_path, SDL_Surface *window_surface_ptr);
    moving() = default;
    ~moving() = default;

   // virtual void move() = 0;
    int get_position();
    
};

#endif