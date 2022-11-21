#include "Project_SDL1.h"

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <numeric>
#include <random>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "animal.h"
#include "sheep.h"
#include "wolf.h"


void init()
{
	// Initialize SDL
	if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0)
		throw std::runtime_error("init():" + std::string(SDL_GetError()));

	// Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
		throw std::runtime_error("init(): SDL_image could not Initialize! "
								 "SDL_image Error: " + 
								 std::string(IMG_GetError()));
	/*Rajout pour ouvrir la fenêtre*/
	
}

	
	


namespace {
	// Defining a namespace without a name -> Anonymous workspace
	// Its purpose is to indicate to the compiler that everything
	// inside of it is UNIQUELY used within this source file
	
	SDL_Surface* load_surface_for(const std::string& path, 
								  SDL_Surface* window_surface_ptr)
	{
		// Helper function to load a png for a specific surface
		// See SDL_ConvertSurface
		if (!window_surface_ptr){
			std::cout << "Error : window surface ptr is invalid" << std::endl;
			return (nullptr);
		}

		window_surface_ptr = SDL_ConvertSurface(IMG_Load(path.c_str()), window_surface_ptr->format, 0);
		if (!window_surface_ptr){
			std::cout << "Error during creation of surface." << std::endl;
			return (nullptr);
		}

		return window_surface_ptr;
	}
		
}
	
	application::application(unsigned n_sheep, unsigned n_wolf){
		
		Nsheep = n_sheep;
		Nwolf = n_wolf;
		createWindow();		

		/*this->window_ptr_ = SDL_CreateWindow("Jeu EPITA CPP", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, frame_width, frame_height, 0);

		// On récupère la surface
		this->window_surface_ptr_ = SDL_GetWindowSurface(this->window_ptr_);

		// On charge les moutons
		for (int i = 0; i < n_sheep; i++) {
			std::unique_ptr<Animal> sheep = std::make_unique<Sheep>(this->window_surface_ptr_);
			this->playing_ground->add_character(std::move(sheep));
		}

		// On charge les loups
		for (int i = 0; i < n_wolf; i++) {
			std::unique_ptr<Animal> wolf = std::make_unique<Wolf>(this->window_surface_ptr_);
			this->playing_ground->add_character(std::move(wolf));
		}
			*/
	}

	application::~application(){
		SDL_DestroyWindow(window_ptr_);
		std::cout << "Window destroy\n";
	}

	void application::createWindow(){
		window_ptr_ = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, frame_width, frame_height, SDL_WINDOW_SHOWN);
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
	
/*Ne s'eteint pas au bout d'un certain delai mais quand on quitte avec la croix*/
	int application::loop(unsigned period){
		animal wolf("../../media/wolf.png", window_surface_ptr_);
		wolf.draw(window_renderer_, window_surface_ptr_, "../../media/wolf.png");

		SDL_UpdateWindowSurface(window_ptr_);
		while(SDL_GetTicks() < (period*1000) && is_open){
			SDL_PollEvent(&window_event_);
			switch (window_event_.type) {
				case SDL_QUIT:
					is_open = false;
					break;
			}
		}	

		//A mettre dans le dtor de app
		SDL_DestroyRenderer(window_renderer_);
		SDL_DestroyWindow(window_ptr_);
		SDL_Quit();
		
		return period;
	}

	ground::ground(SDL_Surface* window_surface_ptr){
		//TODO
	}

	// en parametre les remplacer avec le type d'animal qu'on appelera et mettra le file correspondant
	void ground::add_animal(){
		/*string file_path;
		if(type == "sheep")
			file_path = "sheep.png";
		else if(type == "wolf")
			file_path = "wolf.png";
		animal animal = new animal(file_path, ground);
		update(animal);
		//animal::animal(file_path, window_surface_ptr);
*/
	}// ici utiliser les smart pointeur pour ajouter l'animal

	void ground::update(){
		//	animal.draw(animal.filepath, ground);
	}

