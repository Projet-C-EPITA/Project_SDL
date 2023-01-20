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
    int speed = 5;
    int POINT_RADIUS = 5;
    double angle = 0;
    SDL_Rect shepherd_pos_;

public:

    /**
     * @summary: This function is the constructor of a sheep dog that inherit animal
     * We add the shepherd pos like that the dog will spawn at the exact same position as the shepherd
     */
    sheep_dog(const std::string &file_path, SDL_Surface *window_surface_ptr, int shepherd_posx, int shepherd_posy)
        : animal(file_path, window_surface_ptr){
            pos.x = shepherd_posx + 30; // position aleatoire de l'animal
            pos.y = shepherd_posy;
            
        };

    ~sheep_dog() = default;
    //turn around the sheperd
    void get_shepherd_pos(std::vector<std::shared_ptr<shepherd>> shepherds );
    /**
     * @summary: This function move 
     */
    virtual void move();


};

#endif