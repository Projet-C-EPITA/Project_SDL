#include "Project_SDL1.h"

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <numeric>
#include <random>
#include <string>
#include <SDL2/SDL.h>




//---------------------------------------Partie Ground -----------------------------------------

ground::ground(SDL_Surface* window_surface_ptr){
		window_surface_ptr_ = window_surface_ptr;
}
void ground::set_CountLoop(unsigned count){
	count_loop = count;
}

void ground::add_animal(const std::shared_ptr<animal>& animal){
		 animals.push_back(animal);
		 
}

void ground::add_sheperd(const std::shared_ptr<sheperd>& sheperd){
	sheperds.push_back(sheperd);
}

unsigned ground::update(){
		int total_babies = 0;
		int last_baby = 1;
		int add_sheep = 0;
		for (auto &animal_ptr : animals){
			int new_sheeps = 0;
			// Calcule ici le mouton le plus proche pour change la direction du loup
			if (animal_ptr->type == WOLF){
				auto wolfs = std::static_pointer_cast<wolf>(animal_ptr);
				wolfs->get_neareast_animal(ground::animals); // TODO :va en meme temps calculer closest dog
			}
			if (animal_ptr->type == SHEEP){
				auto sheeps = std::static_pointer_cast<sheep>(animal_ptr);
				sheeps->get_nearest_wolf(ground::animals);
				if(sheeps->offspring == true){
					new_sheeps++;
				}
			}
			
			if(new_sheeps>=1){
				total_babies++;
			}
        	animal_ptr->move();
		}
		for(auto &shep : sheperds){
			shep->move();
		}

		// Clear the screen
		SDL_FillRect(window_surface_ptr_, nullptr ,SDL_MapRGB(window_surface_ptr_->format, 0, 255, 0));
		// Draw all animals
		SDL_Delay(15);
		//reset number of babies created when new loop starts
		if(count_loop == 1)
			nb_babies = 0;
		//creates babies if 2 sheeps collide
		if(total_babies>1){
			nb_babies++;
			if(nb_babies == 1){
				last_baby = count_loop;
				auto baby = std::make_shared<sheep>(file_path_sheep, window_surface_ptr_);
				add_animal(baby);
				baby->type = SHEEP;
				int random = rand()%2;
				if(random == 0)
					baby->sex = FEMALE;
				else
					baby->sex = MALE;
				add_sheep++;
			}
		}
		for (int i = 0 ; i < animals.size(); i++){
			if (!animals[i]->isalive) {
				if (animals[i]->type == SHEEP)
					scoreF--;
				animals.erase(animals.begin() + i--);
			}
			else
				animals[i]->draw();	
		}
		for(auto &shep : sheperds){
			shep->draw();
		}
	return add_sheep;
}

	


// ---------------------------------------------Partie Application --------------------------------
	
	application::application(unsigned n_sheep, unsigned n_wolf){
		
		Nsheep = n_sheep;
		Nwolf = n_wolf;
		
		createWindow();	
		ground_ = std::make_unique<ground>(window_surface_ptr_);

		ground_->scoreF = n_sheep;
		for (int i = 0; i < Nsheep; ++i) {
			std::shared_ptr<sheep> sheeps = std::make_shared<sheep>(file_path_sheep, window_surface_ptr_);
			ground_->add_animal(sheeps);
			sheeps->draw();
			sheeps->type = SHEEP;
			int random = rand()%2;
			if(random == 0)
				sheeps->sex = FEMALE;
			else
				sheeps->sex = MALE;
		}

		for (int i = 0; i < Nwolf; ++i) {
			std::shared_ptr<wolf> wolfs =std::make_shared<wolf>(file_path_wolf, window_surface_ptr_);
			ground_->add_animal(wolfs);
			wolfs->draw();
			wolfs->type = WOLF;
			
			
		}
		std::shared_ptr<sheperd> sheperd1 = std::make_shared<sheperd>(file_path_sheperd, window_surface_ptr_);
		ground_->add_sheperd(sheperd1);
		sheperd1->draw();
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
		int count = 0;
		while(SDL_GetTicks() < (period*1000) && is_open){
			count++;
			ground_->set_CountLoop(count);
			SDL_PollEvent(&window_event_);
			switch (window_event_.type) {
				case SDL_QUIT:
					is_open = false;
					break;
			}
			unsigned nb_sheep = ground_->update();
			if(nb_sheep == 1)
				Nsheep++;
			SDL_UpdateWindowSurface(window_ptr_);
			//*2 to avoid too many children at once, reset the count every 2 loops
			if(count == Nsheep*2){
				count = 0;
				ground_->set_CountLoop(count);
			}
				
		}		
		
		//A mettre dans le dtor de app
		SDL_DestroyRenderer(window_renderer_);
		SDL_DestroyWindow(window_ptr_);
		SDL_Quit();
		std::cout << "The score of the application is: " << ground_->scoreF << std::endl;
		return period;
	}

	

	