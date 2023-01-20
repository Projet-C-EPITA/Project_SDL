#ifndef ANIMAL_H
#define ANIMAL_H

#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "utility.h"

#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <vector>

#define DIST_MIN_WOLF 170

enum GENDER {
    MALE,
    FEMALE
};

enum TYPE{
	SHEEP, 
	WOLF, 
	DOG
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
		enum eDirection {UPLEFT, UPRIGHT, DOWNRIGHT, DOWNLEFT, UP, DOWN, RIGHT, LEFT, RIGHT_BOOST, LEFT_BOOST, UP_BOOST, DOWN_BOOST, UPLEFT_BOOST, UPRIGHT_BOOST, DOWNRIGHT_BOOST, DOWNLEFT_BOOST};
		eDirection dir = UPRIGHT; 
		
	
	public:
		
		GENDER sex;
		SDL_Rect pos; 
		TYPE type;
		bool isalive = true;
		
		/**
		 * @summary: This function that loads the sdl_surface that corresponds
		 * to the texture
		 * @param {file_path} : string of the name of the path of the file
		 * @param {*window_surface_ptr} : is a pointer to an SDL_Surface object that
		 * represents the surface of the window. Where the image will be drawn on
		 * screen.
		 */
		animal(const std::string& file_path, SDL_Surface* window_surface_ptr); 

		// todo: Use the destructor to release memory and clean-up behind you
		~animal();

		/**
		 * @summary: Draw the animal on the screen window_surface_ptr
		 * Note that this function is not virtual, it does not depend on the
		 * static type of the instance
		 */
		void draw();
		
		/**
		 * @summary: This virtual function gonna be instancied in the class wolf,
		 * sheep and shepherd dog. The keyword virtual indicates that this function 
		 * can be overridden by derived classes.
		 */
		virtual void move() = 0;

};

#endif