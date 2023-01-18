#ifndef PROJECT_H
#define PROJECT_H

#include "animal.h"
#include "wolf.h"
#include "sheep.h"
#include "shepherd.h"
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
		// le mieux à faire aurait ete uene class object et on aurait reuni les deux parties ensemble
		std::vector<std::shared_ptr<animal>> animals;
		std::vector<std::shared_ptr<shepherd>> shepherds;
		int scoreF;
		// todo: Ctor
		ground(SDL_Surface* window_surface_ptr);

		// todo: Dtor, again for clean up (if necessary)
		~ground(){};

		void add_animal(const std::shared_ptr<animal>& animal); 
		void add_shepherd(const std::shared_ptr<shepherd>& shepherd); 

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
		
		// Other attributes here, for exemple an instance of ground
		std::unique_ptr<ground> ground_;
		
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
#endif