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


/*

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
		
		SDL_Rect pos; //position de l'animal
	
	public:
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

};

class sheep : public animal {
	
	private: 
	int lastDir;
	
	public:

	sheep(const std::string& file_path, SDL_Surface* window_surface_ptr): 
	animal(file_path, window_surface_ptr) {} ;

	~sheep() = default;
	// THe sheep move randomly on the map expect when he getting too close to a wolf, they get a temporary speed boost in the opposite direction of the wolf. When two sheep meet
	//they can produce an offspring 

	virtual void move() override;
	
};
//--------------------------------Partie Wolf --------------------------
class wolf : public animal
{
	
	private: 
	int lastDir;
	
    public:

	wolf(const std::string& file_path, SDL_Surface* window_surface_ptr): 
	animal(file_path, window_surface_ptr){};

	~wolf()= default;
	//they will direct themselves towards the nearest sheep. 
	//If a wolf does not catch a sheep after a certain period, it will starve and die
	virtual void move() override;
	
};*/



// The ground on which all the animals live (like the std::vector in the zoo 
// exemple).
class ground
{
	private:
		// Attention, non-owning ptr, again to the screen
		SDL_Surface* window_surface_ptr_;
	protected:	
		std::vector<std::shared_ptr<animal>> animals;
		// Some attribute to store all the wolves and sheep here
	
	public:
		// todo: Ctor
		ground(SDL_Surface* window_surface_ptr);

		// todo: Dtor, again for clean up (if necessary)
		~ground(){};

		void add_animal(const std::shared_ptr<animal>& animal); 

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