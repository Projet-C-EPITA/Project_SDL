#ifndef SHEEP_DOG_H
#define SHEEP_DOG_H

#pragma once

#include <string>
#include <cmath>

#include "animal.h"
#include "shepherd.h"

class sheep_dog : public animal
{
private:
    SDL_Rect shepherd_pos_;
    double angle = 50;
    int POINT_RADIUS = 70;
    int speed = 5;
    
    
public:

    /**
     * @summary: This function is the constructor of a sheep dog that inherit animal
     * We add the shepherd pos like that the dog will spawn at the exact same position as the shepherd
     */
    sheep_dog(const std::string &file_path, SDL_Surface *window_surface_ptr, int shepherd_posx, int shepherd_posy)
        : animal(file_path, window_surface_ptr){
            pos.x = shepherd_posx + 30; // position aleatoire de l'animal
            pos.y = shepherd_posy - 10;
            
        };

    ~sheep_dog() = default;
   
   /**
     * @summary: This function set the variable shepherd_pos to the position of the sheperd
     * @param: vector of shepherd
     */
    void get_shepherd_pos(std::vector<std::shared_ptr<shepherd>> shepherds );
    /**
     * @summary: This function move 
     */
    virtual void move();


};

#endif