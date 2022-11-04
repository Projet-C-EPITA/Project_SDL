#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Project_SDL1.h"
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <vector>
#include "animal.h"

class wolf : public animal
{
	// todo
	// Ctor
	// Dtor
	// Implement functions that are purely virtual in base class
    public:

	wolf(const std::string& file_path, SDL_Surface* window_surface_ptr): 
	animal( file_path, window_surface_ptr){};

	~wolf(){};
	//they will direct themselves towards the nearest sheep. 
	//If a wolf does not catch a sheep after a certain period, it will starve and die
	void move() override;
	
};