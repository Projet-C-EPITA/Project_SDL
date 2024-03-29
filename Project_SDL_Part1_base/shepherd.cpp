#include "shepherd.h"


shepherd::shepherd(const std::string &file_path, SDL_Surface *window_surface_ptr)
{
    // On charge l'image du berger
    window_surface_ptr_ = window_surface_ptr;
    image_ = load_surface_for(file_path, window_surface_ptr_);
    if (image_ == NULL)
    {
        fprintf(stderr, "Erreur SDL_LoadBMP : %s", SDL_GetError());
    }

    pos_s.x = rand() % frame_width - image_->w; // random position of the player
    pos_s.y = rand() % frame_height - image_->h;
    pos_s.w = image_->w;
    pos_s.h = image_->h;
}


void shepherd::move()
{
    const Uint8 *keyboard_state_array = SDL_GetKeyboardState(NULL);
    SDL_PollEvent(action_);
    // Limitation inside the frame
    if(pos_s.x <= 1){
         if (keyboard_state_array[SDL_SCANCODE_UP])
            pos_s.y -= 1;
        if (keyboard_state_array[SDL_SCANCODE_DOWN])
            pos_s.y += 1;
        if (keyboard_state_array[SDL_SCANCODE_RIGHT])
            pos_s.x += 1;
   
    }
    else if(pos_s.x >= frame_width -image_->w){
        if (keyboard_state_array[SDL_SCANCODE_UP])
            pos_s.y -= 1;
        if (keyboard_state_array[SDL_SCANCODE_DOWN])
            pos_s.y += 1;
        if (keyboard_state_array[SDL_SCANCODE_LEFT])
            pos_s.x -= 1; 
    }

    else if (pos_s.y <= 1){
        if ( keyboard_state_array[SDL_SCANCODE_DOWN])
            pos_s.y += 1;
        if (keyboard_state_array[SDL_SCANCODE_LEFT])
            pos_s.x -= 1;
        if (keyboard_state_array[SDL_SCANCODE_RIGHT])
            pos_s.x += 1;
    }
    else if (pos_s.y >= frame_height -image_->h){
        if ( keyboard_state_array[SDL_SCANCODE_UP])
            pos_s.y -= 1;
        if ( keyboard_state_array[SDL_SCANCODE_LEFT])
            pos_s.x -= 1;
        if ( keyboard_state_array[SDL_SCANCODE_RIGHT])
            pos_s.x += 1;
    }
    // The shepherd don't touch any edge
    else{
        if (keyboard_state_array[SDL_SCANCODE_UP])
            pos_s.y -= 1;
        if (keyboard_state_array[SDL_SCANCODE_DOWN])
            pos_s.y += 1;
        if ( keyboard_state_array[SDL_SCANCODE_LEFT])
            pos_s.x -= 1;
        if (keyboard_state_array[SDL_SCANCODE_RIGHT])
            pos_s.x += 1;
    }
}

void shepherd::draw()
{
    SDL_BlitSurface(image_, NULL, window_surface_ptr_, &pos_s);
    
}


SDL_Rect shepherd::get_pos_shepherd(){
    return pos_s;
}

shepherd::~shepherd()
{
    SDL_FreeSurface(image_);
}