#ifndef SHEEP_H
#define SHEEP_H

#pragma once
#include <string>

#include "animal.h"

class sheep : public animal
{
private:
    int lastDir;
    SDL_Rect nearest_wolf_pos_;
    bool to_close_sheep = false;
    int speed = 1;

public:
    bool offspring = false;

    /**
     * @summary: This function is the constructor of a sheep that inherit animal
     */
    sheep(const std::string &file_path, SDL_Surface *window_surface_ptr)
        : animal(file_path, window_surface_ptr){};

    ~sheep() = default;

    /**
     * @summary: This function move randomly on the map and bouncing on the
     * edges expect when he getting too close to a wolf, they get a temporary
     * speed boost in the opposite direction of the wolf. When two sheep
     * meet(MALE and FEMALE) they can produce an offspring.
     */
    virtual void move();

    /**
     * @summary: This function calculates the min distance of the sheep from one
     * of the wolf in the ground and puts the position of the nearest wolf in
     * nearest_wolf
     * @param {animals}: Take the vector of animal to browse it.
     *
     */
    void get_nearest_wolf(std::vector<std::shared_ptr<animal>> animals);


};

#endif