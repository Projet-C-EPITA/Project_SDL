#ifndef sheperd_H
#define sheperd_H


#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "utility.h"

#include <iostream>



class sheperd 
{
private:
    SDL_Surface *image_ptr_;
    SDL_Surface *window_surface_ptr_;
    SDL_Surface *image_;
    SDL_Rect pos_s; // Position of the sheperd
    SDL_Event *action_; // Event

public:
    
   /**
     * @summary: This function is the constructor of sheperd it load the image of the sheperd 
     * and set a random position for the object
     * @param {file_path} : string of the name of the path of the file
     * @param {*window_surface_ptr} : is a pointer to an SDL_Surface object that represents 
     *        the surface of the window. Where the image will be drawn on screen.
    */
    sheperd(const std::string &file_path, SDL_Surface *window_surface_ptr);

    /**
     * TODO: voir si on tej pas car sharepointer pas beosin de destructeur
     * @summary This function is the destructor of sheperd
     * 
    */
    ~sheperd();
    
    /**
     * @summary: This function draw the sheperd on the ground.this copy pixels from 
     * the image_ surface to the window_surface_ptr_.
     * 
    */
    void draw();

    /**
     * @summary: This function allow to move the sheperd with the arrow of the 
     * keyboard (UP, DOWN, LEFT, RIGHT)
     * 
    */
    void move();

    /**
     * TODO: Avoir si on supprime pas car pas utilisé
     * @summary This function set the event
     * 
    */
    void set_Event(SDL_Event *ev);
};

#endif 