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
	
	private: 
	
	//float X = rand() % frame_width + 1;   //random starting point
   	//float Y = rand() % frame_height + 1;
	int lastDir;
	enum eDirection {UPLEFT, UPRIGHT, DOWNRIGHT, DOWNLEFT, UP, DOWN, RIGHT, LEFT};
	eDirection dir = UPRIGHT; 
	
	public:

	sheep(const std::string& file_path, SDL_Surface* window_surface_ptr): 
	animal(file_path, window_surface_ptr){}; //x = rect.x; y = rect.y
	// sheep.draw(windowrenderer, X, Y);

	~sheep(){};
	// THe sheep move randomly on the map expect when he getting too close to a wolf, they get a temporary speed boost in the opposite direction of the wolf. When two sheep meet
	//they can produce an offspring 
	// Call sheep1.move();
	virtual void move() override;
	
};