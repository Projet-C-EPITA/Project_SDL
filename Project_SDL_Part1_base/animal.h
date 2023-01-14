#ifndef ANIMAL_H
#define ANIMAL_H

#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//#include "Project_SDL1.h"
#include "utility.h"

#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <vector>

enum GENDER {
    MALE,
    FEMALE
};

enum TYPE{
	SHEEP, 
	WOLF, 
	SHEPERDDOG
};

class animal 
{
	private:
		// ptr to the surface on which we want the animal to be drawn, also 
		// non-owning
		SDL_Surface* window_surface_ptr_;
		// The texture of the sheep (the loaded image), use load_surface_for
		SDL_Texture* texture_img_;

	protected:
		SDL_Surface * image_;
		enum eDirection {UPLEFT, UPRIGHT, DOWNRIGHT, DOWNLEFT, UP, DOWN, RIGHT, LEFT};
		eDirection dir = UPRIGHT; 
		
	
	public:
		
		GENDER sex;
		SDL_Rect pos; 
		TYPE type;
		//position de l'animal
		//moving moving_= moving();
		// todo: The constructor has to load the sdl_surface that corresponds 
		// to the texture
		animal(const std::string& file_path, SDL_Surface* window_surface_ptr); 

		// todo: Use the destructor to release memory and clean-up behind you
		~animal();

		// todo: Draw the animal on the screen window_surface_ptr
		// Note that this function is not virtual, it does not depend on the 
		// static type of the instance
		void draw();

		SDL_Rect get_position();

		
		virtual void move() = 0;
		//virtual void get_nearest_animal(std::vector<std::shared_ptr<animal>> animals) = 0;

};

#endif