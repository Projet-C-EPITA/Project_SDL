#ifndef WOLF_H
#define WOLF_H

#include "animal.h"
#include <iostream>
#include <string>
class wolf : public animal{
	
	private: 
	int lastDir;
	
    public:

	wolf(const std::string& file_path, SDL_Surface* window_surface_ptr):
	animal(file_path, window_surface_ptr) {} ;

	~wolf()= default;
	//they will direct themselves towards the nearest sheep. 
	//If a wolf does not catch a sheep after a certain period, it will starve and die
	virtual void move() ;
	
};

#endif
