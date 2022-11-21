#pragma once

#include "animal.h"


class sheep : public animal {
	
	private: 
	int lastDir;
	
	public:

	sheep(const std::string& file_path, SDL_Surface* window_surface_ptr): 
	animal(file_path, window_surface_ptr){}; //x = rect.x; y = rect.y
	// sheep.draw(windowrenderer, X, Y);

	~sheep(){};
	// THe sheep move randomly on the map expect when he getting too close to a wolf, they get a temporary speed boost in the opposite direction of the wolf. When two sheep meet
	//they can produce an offspring 

	// Call sheep1.move();
	// virtual void move() override;
	
};
