#ifndef SHEEP_H
#define SHEEP_H

#pragma once
#include <string>
#include <chrono>
#include "animal.h"

//class animal;

class sheep : public animal{
	
	private: 
	int lastDir;
	SDL_Rect nearest_wolf_pos_;
	bool to_close_sheep = false;
	int speed = 1;
	
	
	public:

	bool offspring = false;
	Uint32 last_offspring = SDL_GetTicks();
	sheep(const std::string& file_path, SDL_Surface* window_surface_ptr):
	animal(file_path, window_surface_ptr) {} ;

	~sheep() = default;
	// THe sheep move randomly on the map expect when he getting too close to a wolf, they get a temporary speed boost in the opposite direction of the wolf. When two sheep meet
	//they can produce an offspring 

	virtual void move() ;
	void get_nearest_wolf(std::vector<std::shared_ptr<animal>> animals);
	void createOffspring();
	
	// in order to verifie if sheep is too close to a wolf
	//virtual void get_neareast_animal(std::vector<std::shared_ptr<animal>> animals);
};

#endif