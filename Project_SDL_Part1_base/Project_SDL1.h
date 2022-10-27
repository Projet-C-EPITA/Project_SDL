#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <vector>


// Definitions
constexpr double frame_rate = 60.0;            // refresh rate
constexpr double frame_time = 1. / frame_rate;
constexpr unsigned frame_width = 1400;         // Width of window in pixel
constexpr unsigned frame_height = 900;         // Height of window in pixel
// Minimal distance of animal to the border of the screen
constexpr unsigned frame_boundary = 100;


// Helper function to initialize SDL
void init();



class animal
{
	private:
		// ptr to the surface on which we want the animal to be drawn, also 
		// non-owning
		SDL_Surface* window_surface_ptr_;
		// The texture of the sheep (the loaded image), use load_surface_for
		
		// todo: Attribute(s) to define its position
	
	public:
		// todo: The constructor has to load the sdl_surface that corresponds 
		// to the texture
		animal(const std::string& file_path, SDL_Surface* window_surface_ptr)
		{}; 

		// todo: Use the destructor to release memory and clean-up behind you
		~animal(){};

		// todo: Draw the animal on the screen window_surface_ptr
		// Note that this function is not virtual, it does not depend on the 
		// static type of the instance
		void draw(){};

		// todo: Animals move around, but in a different fashion depending on 
		// which type of animal
		virtual void move(){} = 0;
};



// Insert here
// Class sheep, derived from animal
class sheep : public animal
{
	// todo
	// Ctor
	// Dtor
	// Implement functions that are purely virtual in base class
};



// Insert here
// class wolf, derived from animal
// Use only sheep at first. Once the application works for sheep you can add 
// the wolves



// The ground on which all the animals live (like the std::vector in the zoo 
// exemple).
class ground
{
	private:
		// Attention, non-owning ptr, again to the screen
		SDL_Surface* window_surface_ptr_;

		// Some attribute to store all the wolves and sheep here
	
	public:
		// todo: Ctor
		ground(SDL_Surface* window_surface_ptr);

		// todo: Dtor, again for clean up (if necessary)
		~ground(){};

		// todo: Add an animal
		void add_animal(/*some argument here*/);

		// todo: Refresh the screen : Move animals and draw them
		void update();

		// Possibly other methods, depends on your implementation
};



// The application class, which is in charge of generating the window
class application
{
	private:
		// The following are owning ptrs
		SDL_Window* window_ptr_;
		SDL_Surface* window_surface_ptr_;
		SDL_Event window_event_;

		// Other attributes here, for exemple an instance of ground
	
	public:
		// Ctor
		application(unsigned n_sheep, unsigned n_wolf);

		// Dtor
		~application();

		// Main loop of the application. This ensures that the screen is 
		// updated at the correct rate. See SDL_GetTicks() and SDL_Delay() to 
		// enforce a duration the application should terminate after 'period' 
		// seconds.
		int loop(unsigned period);
};
