#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <vector>
#include "sheep.h"
#include "wolf.h"


// Definitions
constexpr double frame_rate = 60.0;            // refresh rate
constexpr double frame_time = 1. / frame_rate;
constexpr unsigned frame_width = 1400;         // Width of window in pixel
constexpr unsigned frame_height = 900;         // Height of window in pixel
// Minimal distance of animal to the border of the screen
constexpr unsigned frame_boundary = 100;



// Helper function to initialize SDL
void init();



// The ground on which all the animals live (like the std::vector in the zoo 
// exemple).
class ground
{
	private:
		// Attention, non-owning ptr, again to the screen
		SDL_Surface* window_surface_ptr_;
		std::shared_ptr<sheep> sheeps;
		std::shared_ptr<wolf> wolves;
		//sheep* sheeps;/* add smart pointer */ 
		//wolf* wolves;
		// Some attribute to store all the wolves and sheep here
	
	public:
		// todo: Ctor
		ground(SDL_Surface* window_surface_ptr);

		// todo: Dtor, again for clean up (if necessary)
		~ground(){};

		// todo: Add an animal
		// indiquer un num pour savoir quel animal store
		void add_animal();

		// todo: Refresh the screen : Move animals and draw them (method of animal)
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
		SDL_Renderer *window_renderer_;
		SDL_Event window_event_;
		unsigned  Nsheep;
		unsigned  Nwolf;
		unsigned int lastTime = 0, currentTime;
		bool is_open{ true };
		//ground ground_;

		// Other attributes here, for exemple an instance of ground
	
	public:
		// Ctor
		application(unsigned n_sheep, unsigned n_wolf);

		// Dtor
		~application();


		void createWindow();
		
		// Main loop of the application. This ensures that the screen is 
		// updated at the correct rate. See SDL_GetTicks() and SDL_Delay() to 
		// enforce a duration the application should terminate after 'period' 
		// seconds.
		int loop(unsigned period);
};
