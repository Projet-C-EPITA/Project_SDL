#include "animal.h"


animal::animal(const std::string& file_path, SDL_Surface* window_surface_ptr){
   /* window_surface_ptr_ = window_surface_ptr;
    const char * file = file_path.c_str();
    //texture_img_ = IMG_LoadTexture(window_renderer_, file);
    //load_surface_for(file_path, window_surface_ptr); a ecrire
    image_ = IMG_Load(file); /*Pour charger une image*/
    /*if(NULL == image_){
        fprintf(stderr, "Erreur SDL_LoadBMP : %s", SDL_GetError());
    }
    */
   /* image_ = load_surface_for(file_path, window_surface_ptr);
    if (image_ == nullptr)
        throw std::runtime_error("animal::animal(): " + std::string(SDL_GetError()));
    float X_pos = rand() % frame_width + 1; //position X de l'animal (aleatoire)
    float Y_pos = rand() % frame_height + 1;*/
    
}

void animal::draw(SDL_Renderer *window_renderer){// il faut aussi une position dans les arguments ?
   /* SDL_LockSurface(window_surface_ptr);
    SDL_Surface* image = IMG_Load(file_path);
    SDL_RenderCopy();*/
   
   
    SDL_Texture *tmp = SDL_CreateTextureFromSurface(window_renderer, image_); /* créer une texture à partir de cette image*/
    SDL_FreeSurface(image_); /* On libère la surface, on n’en a plus besoin */
    texture_img_ = SDL_CreateTexture(window_renderer, SDL_PIXELFORMAT_RGBA8888, 
                            SDL_TEXTUREACCESS_TARGET, image_->w, image_->h);
    SDL_SetRenderTarget(window_renderer, texture_img_); /* La cible de rendu est maintenant texture. */
    SDL_RenderCopy(window_renderer, tmp, NULL, NULL); /* On copie tmp sur texture */
    SDL_DestroyTexture(tmp);
    //SDL_FreeSurface(image_);
    SDL_SetRenderTarget(window_renderer, NULL); /* La cible de rendu est de nouveau le renderer. **/
}