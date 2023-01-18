#ifndef SHEPHERD_H
#define SHEPHERD_H


#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "utility.h"

#include <iostream>



class shepherd 
{
private:
    SDL_Surface *image_ptr_;
    SDL_Surface *window_surface_ptr_;

protected:
    SDL_Surface *image_;
    //long speed;

public:
    SDL_Rect pos_s;
    SDL_Event *action_;
   
    shepherd(const std::string &file_path, SDL_Surface *window_surface_ptr);
    ~shepherd();
    void draw();
    void move();
    void set_Event(SDL_Event *ev);
};

#endif // SHEPHERD_H