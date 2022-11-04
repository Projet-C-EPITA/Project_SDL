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

class sheep : public animal {
	
	public:

	sheep(const std::string& file_path, SDL_Surface* window_surface_ptr): 
	animal( file_path, window_surface_ptr){};

	~sheep(){};
	// THe sheep move randomly on the map expect when he getting too close to a wolf, they get a temporary speed boost in the opposite direction of the wolf. When two sheep meet
	//they can produce an offspring 
	void move() override;
	
};