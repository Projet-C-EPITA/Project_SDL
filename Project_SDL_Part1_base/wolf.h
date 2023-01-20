#ifndef WOLF_H
#define WOLF_H

#include <chrono>
#include <iostream>
#include <string>

#include "animal.h"

class wolf : public animal
{
private:
    int lastDir;
    SDL_Rect nearest_sheep_pos_;
    SDL_Rect closest_dog_pos_;
    std::shared_ptr<animal> nearest_sheep;
    bool to_close = false;
    bool get_Sheep = false;
   
    Uint32 m_lastMealTime = SDL_GetTicks() ;

public:
    /**
     * @summary: This function is the constructor of wolf that inherit of animal
     * @param {file_path} : string of the name of the path of the file
     * @param {*window_surface_ptr} : is a pointer to an SDL_Surface object that
     * represents the surface of the window. Where the image will be drawn on
     * screen.
     */
    wolf(const std::string &file_path, SDL_Surface *window_surface_ptr)
        : animal(file_path, window_surface_ptr){};

    ~wolf() = default;

    /**
     * @summary: This function moves the wolf in the direction of
     * the nearest sheep but avoiding the shepherd's dogs in priority
     *
     */
    virtual void move();

    /**
     * @summary: This function must calculate the time elapsed since
     * a wolf has not eat a sheep
     *
     */
    void time_to_catch();

    /**
     * @summary: This function set the boolean animal::is_alive and get_sheep if
     * the wolf catch a sheep
     *
     */
    void is_get_sheep();

    /**
     * @summary: This function calculates the min distance of the wolf from one
     * of the sheep in the ground and puts the position of the nearest sheep in
     * neareast_sheep
     * @param {animals}: Take the vector of animal to browse it.
     *
     */
    void get_neareast_animal(std::vector<std::shared_ptr<animal>> animals);

    
};

#endif
