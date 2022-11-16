#include "Project_SDL1.h"

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <numeric>
#include <random>
#include <string>


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
}


namespace
{
	// Defining a namespace without a name -> Anonymous workspace
	// Its purpose is to indicate to the compiler that everything
	// inside of it is UNIQUELY used within this source file
	
	SDL_Surface* load_surface_for(const std::string& path, 
								  SDL_Surface* window_surface_ptr)
	{
		// Helper function to load a png for a specific surface
		// See SDL_ConvertSurface
	}
}

application::application(unsigned n_sheep, unsigned n_wolf) {
	
	// On créé la fenêtre
	this->window_ptr_ = SDL_CreateWindow("Jeu EPITA CPP", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, frame_width, frame_height, 0);

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
}
