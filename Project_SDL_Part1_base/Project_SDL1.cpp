#include "Project_SDL1.h"

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <numeric>
#include <random>
#include <string>
#include <SDL.h>




//---------------------------------------Partie Ground -----------------------------------------

ground::ground(SDL_Surface* window_surface_ptr){
		window_surface_ptr_ = window_surface_ptr;
}


void ground::add_animal(const std::shared_ptr<animal>& animal){
		 animals.push_back(animal);
		 
}

void ground::update(){
		
		for (auto &animal_ptr : animals){
			// Calcule ici le mouton le plus proche pour change la direction du loup
			if (animal_ptr->type == WOLF){
				auto wolfs = std::static_pointer_cast<wolf>(animal_ptr);
				wolfs->get_neareast_animal(ground::animals); // TODO :va en meme temps calculer closest dog
			}
        	animal_ptr->move();
		}
		// Clear the screen
		SDL_FillRect(window_surface_ptr_, nullptr ,SDL_MapRGB(window_surface_ptr_->format, 0, 255, 0));
		// Draw all animals
		for (auto &animal_ptr : animals){
			//Ne marche pas encore mais verifie si l'animal est toujours en vie sinon pouf il disparait
			if (!animal_ptr->isalive) {
				animal_ptr.reset();// releases the resource and free the memory
			}
			animal_ptr->draw();	
		}
			
		
}

	


// ---------------------------------------------Partie Application --------------------------------
	
	application::application(unsigned n_sheep, unsigned n_wolf){
		
		Nsheep = n_sheep;
		Nwolf = n_wolf;
		createWindow();	
		ground_ = std::make_unique<ground>(window_surface_ptr_);
	
		// TODO : faire une rand avec l'enum sex du sheep (male,female)
		for (int i = 0; i < Nsheep; ++i) {
			std::shared_ptr<sheep> sheeps = std::make_shared<sheep>(file_path_sheep, window_surface_ptr_);
			ground_->add_animal(sheeps);
			sheeps->draw();
			sheeps->type = SHEEP;
		}

		for (int i = 0; i < Nwolf; ++i) {
			std::shared_ptr<wolf> wolfs =std::make_shared<wolf>(file_path_wolf, window_surface_ptr_);
			ground_->add_animal(wolfs);
			wolfs->draw();
			wolfs->type = WOLF;
			
			
		}
	}	

	application::~application(){
		SDL_DestroyWindow(window_ptr_);
		std::cout << "Window destroy\n";

		IMG_Quit();
    	SDL_Quit();
	}

	void application::createWindow(){
		window_ptr_ = SDL_CreateWindow("Game SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, frame_width, frame_height, SDL_WINDOW_SHOWN);
		std::cout <<"window created\n";
		if (window_ptr_ == nullptr) {
			SDL_Log("Could not create a window: %s", SDL_GetError());
		}
		window_renderer_ = SDL_CreateRenderer(window_ptr_, -1, SDL_RENDERER_ACCELERATED);
		if (window_renderer_ == nullptr) {
			SDL_Log("Could not create a renderer: %s", SDL_GetError());
		}

		window_surface_ptr_ =  SDL_GetWindowSurface(window_ptr_);
		if (window_surface_ptr_ == nullptr){
			SDL_DestroyWindow(window_ptr_);
			SDL_Log("Could not create a window: %s", SDL_GetError());
		}
		SDL_FillRect(window_surface_ptr_, nullptr, SDL_MapRGB(window_surface_ptr_->format, 0, 255, 0));

		
	}
	

	int application::loop(unsigned period) {
		while(SDL_GetTicks() < (period*1000) && is_open){
			SDL_PollEvent(&window_event_);
			switch (window_event_.type) {
				case SDL_QUIT:
					is_open = false;
					break;
			}
			ground_->update();
			SDL_UpdateWindowSurface(window_ptr_);
		}		
		
		//A mettre dans le dtor de app
		SDL_DestroyRenderer(window_renderer_);
		SDL_DestroyWindow(window_ptr_);
		SDL_Quit();
		
		return period;
	}

	

	