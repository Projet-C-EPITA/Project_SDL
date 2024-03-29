#ifndef shepherd_H
#define shepherd_H


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
    SDL_Surface *image_;
    SDL_Rect pos_s; // Position of the shepherd
    SDL_Event *action_; // Event

public:
    
   /**
     * @summary: This function is the constructor of shepherd it load the image of the shepherd 
     * and set a random position for the object
     * @param {file_path} : string of the name of the path of the file
     * @param {*window_surface_ptr} : is a pointer to an SDL_Surface object that represents 
     *        the surface of the window. Where the image will be drawn on screen.
    */
    shepherd(const std::string &file_path, SDL_Surface *window_surface_ptr);

   
    ~shepherd();
    
    /**
     * @summary: This function draw the shepherd on the ground.this copy pixels from 
     * the image_ surface to the window_surface_ptr_.
     * 
    */
    void draw();

    /**
     * @summary: This function allow to move the shepherd with the arrow of the 
     * keyboard (UP, DOWN, LEFT, RIGHT)
     * 
    */
    void move();

  
    SDL_Rect get_pos_shepherd();
};

#endif 