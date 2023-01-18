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

void shepherd::move()
{

    const Uint8 *keyboard_state_array = SDL_GetKeyboardState(NULL);
    SDL_PollEvent(&event);
    // WSAD  & UP/DOWN/LEFT/RIGHT arrow
    if (keyboard_state_array[SDL_SCANCODE_Z] || keyboard_state_array[SDL_SCANCODE_UP])
        this->speed.y -= 1;
    if (keyboard_state_array[SDL_SCANCODE_S] || keyboard_state_array[SDL_SCANCODE_DOWN])
        this->speed.y += 1;
    if (keyboard_state_array[SDL_SCANCODE_Q] || keyboard_state_array[SDL_SCANCODE_LEFT])
        this->speed.x -= 1;
    if (keyboard_state_array[SDL_SCANCODE_D] || keyboard_state_array[SDL_SCANCODE_RIGHT])
        this->speed.x += 1;
    // Limitation inside the frame
    if (this->pos.x + this->speed.x < frame_boundary || this->pos.x + this->speed.x > frame_width - this->image_ptr_->w - frame_boundary)
        this->speed.x = -this->speed.x;
    if (this->pos.y + this->speed.y < frame_boundary || this->pos.y + this->speed.y > frame_height - this->image_ptr_->h - frame_boundary)
        this->speed.y = -this->speed.y;
}

void shepherd::draw()
{
    SDL_BlitSurface(image_, NULL, window_surface_ptr_, &pos);
}

shepherd::~sheperd()
{
    SDL_FreeSurface(image_);
}