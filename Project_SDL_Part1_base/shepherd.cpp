#include "shepherd.h"
#include "Project_SDL1.h"

shepherd::shepherd(const std::string &file_path, SDL_Surface *window_surface_ptr)
{
    // On charge l'image du berger
    window_surface_ptr_ = window_surface_ptr;
    image_ = load_surface_for(file_path, window_surface_ptr_);
    if (image_ == NULL)
    {
        fprintf(stderr, "Erreur SDL_LoadBMP : %s", SDL_GetError());
    }

    pos.x = rand() % frame_width - image_->w; // position aleatoire du joueur
    pos.y = rand() % frame_height - image_->h;
    pos.w = image_->w;
    pos.h = image_->h;
}

void shepherd::draw()
{
    SDL_BlitSurface(image_, NULL, window_surface_ptr_, &pos);
}

shepherd::~sheperd()
{
    SDL_FreeSurface(image_);
}