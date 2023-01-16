#include "human.h"

human::human(const std::string &file_path, SDL_Surface *window_surface_ptr)
{
    window_surface_ptr_ = window_surface_ptr;
    image_ = load_surface_for(file_path, window_surface_ptr_); /*Pour charger une image*/
    if (NULL == image_)
    {
        fprintf(stderr, "Erreur SDL_LoadBMP : %s", SDL_GetError());
    }

    pos.x = rand() % frame_width - image_->w; // position aleatoire de l'animal
    pos.y = rand() % frame_height - image_->h;
    pos.w = image_->w;
    pos.h = image_->h;
}

void human::move()
{

    setDirX(0);
    setDirY(0);

    if (this->touche.type = SDL_KEYDOWN)
    {
        if (this->touche.key == SDLK_z)
        {
            setDirY(-1);
        }
        if (this->touche.key == SDLK_s)
        {
            setDirY(1);
        }
        if (this->touche.key == SDLK_q)
        {
            setDirX(-1);
        }
        if (this->touche.key == SDLK_d)
        {
            setDirX(1);
        }
    }
    if (getDirX() + getPosX() <= 60 || getDirX() + getPosX() >= frame_width - 90)
    {
        setDirX(0);
    }
    if (getDirY() + getPosY() <= 60 || getDirY() + getPosY() >= frame_height - 90)
    {
        setDirY(0);
    }
    posX_ += getDirX() * getSpeed();
    posY_ += getDirY() * getSpeed();
}