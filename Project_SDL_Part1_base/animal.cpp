#include "animal.h"



animal::animal(const std::string& file_path, SDL_Surface* window_surface_ptr){
    window_surface_ptr_ = window_surface_ptr;
    image_ =load_surface_for(file_path, window_surface_ptr_); 
    if(NULL == image_){
        fprintf(stderr, "Erreur SDL_LoadBMP : %s", SDL_GetError());
    }
    pos.x = rand() % frame_width - image_->w; //position aleatoire de l'animal 
    pos.y = rand() % frame_height - image_->h;
	pos.w = image_->w;
    pos.h = image_->h;
    
}
void animal::draw(){
			SDL_BlitSurface(image_, NULL, window_surface_ptr_, &pos);
		};


animal::~animal(){
    SDL_FreeSurface(image_);
    //SDL_FreeSurface(window_surface_ptr_);
};
