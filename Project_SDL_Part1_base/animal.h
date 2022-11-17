#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Project_SDL1.h"
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <vector>

float X_pos = rand() % frame_width + 1; //position X de l'animal (aleatoire)
float Y_pos = rand() % frame_height + 1;

class animal
{
	private:
		// ptr to the surface on which we want the animal to be drawn, also 
		// non-owning
		SDL_Surface* window_surface_ptr_;
		// The texture of the sheep (the loaded image), use load_surface_for
		SDL_Texture* texture_img_;
		
		//float x; 
		//float y;
	protected:
		SDL_Surface * image_;
		enum eDirection {UPLEFT, UPRIGHT, DOWNRIGHT, DOWNLEFT, UP, DOWN, RIGHT, LEFT};
		eDirection dir = UPRIGHT; 
		
		// todo: Attribute(s) to define its position
	
	public:
		// todo: The constructor has to load the sdl_surface that corresponds 
		// to the texture
		animal(const std::string& file_path, SDL_Surface* window_surface_ptr) {}; 

		// todo: Use the destructor to release memory and clean-up behind you
		~animal(){};

		// todo: Draw the animal on the screen window_surface_ptr
		// Note that this function is not virtual, it does not depend on the 
		// static type of the instance
		void draw(SDL_Renderer *window_renderer){};

		// todo: Animals move around, but in a different fashion depending on 
		// which type of animal
		virtual void move() = 0;
};