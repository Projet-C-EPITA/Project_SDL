#define HUMAN_H
#ifndef HUMAN_H

#pragma once
#include "human.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
// #include "Project_SDL1.h"
#include "utility.h"
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <vector>

class human
{

private:
    SDL_Surface *window_surface_ptr_;
    SDL_Surface *image_ptr_;
    SDL_Rect rectangle_;
    int posX_;
    int posY_;
    int dirX_;
    int dirY_;
    SDL_Event action;
    int vitesse_;

public:
    human(const std::string &file_path, SDL_Surface *window_surface_ptr) : ~human() = default;
    void move();
    int getPosX();
    int getPosY();
    void setDirX(int directionX);
    void setDirY(int directionY);
    int getDirX();
    int getDiY();
    void Set_Event(SDL_Event ev);
}

#endif