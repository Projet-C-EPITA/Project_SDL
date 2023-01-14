#ifndef WOLF_H
#define WOLF_H

#include "animal.h"

#include <iostream>
#include <string>

class wolf : public animal{
	
	private: 
	int lastDir;
	SDL_Rect nearest_sheep_pos_;
	
    public:

	wolf(const std::string& file_path, SDL_Surface* window_surface_ptr):
	animal(file_path, window_surface_ptr) {} ;

	~wolf()= default;
	//they will direct themselves towards the nearest sheep. 
	//If a wolf does not catch a sheep after a certain period, it will starve and die
	virtual void move() ;

	void get_neareast_animal(std::vector<std::shared_ptr<animal>> animals);

	
};

#endif
