#ifndef PROJECT_H
#define PROJECT_H

#include "animal.h"
#include "wolf.h"
#include "sheep.h"
#include "utility.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <vector>



class ground
{
	private:
		// Attention, non-owning ptr, again to the screen
		SDL_Surface* window_surface_ptr_;
	
		
		// Some attribute to store all the wolves and sheep here
	
	public:
		//number of loops done
		unsigned count_loop;

		//number of babies byloop
		unsigned nb_babies = 0;

		std::vector<std::shared_ptr<animal>> animals;
		// todo: Ctor
		ground(SDL_Surface* window_surface_ptr);

		// todo: Dtor, again for clean up (if necessary)
		~ground(){};

		void add_animal(const std::shared_ptr<animal>& animal); 

		// todo: Refresh the screen : Move animals and draw them (method of animal)
		unsigned update();
		
		//set number of sheeps
		void set_CountLoop(unsigned count);

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
		
		// Other attributes here, for exemple an instance of ground
		std::unique_ptr<ground> ground_;
		
	public:
		// Ctor
		application(unsigned n_sheep, unsigned n_wolf);

		// Dtor
		~application();


		void createWindow();

		//set number of sheeps
		void add_sheep();
		
		// Main loop of the application. This ensures that the screen is 
		// updated at the correct rate. See SDL_GetTicks() and SDL_Delay() to 
		// enforce a duration the application should terminate after 'period' 
		// seconds.
		int loop(unsigned period);
		
};
#endif