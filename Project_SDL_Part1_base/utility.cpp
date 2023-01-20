#include "utility.h"




void init()
{
	// Initialize SDL
	if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0)
		throw std::runtime_error("init():" + std::string(SDL_GetError()));

	// Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
		throw std::runtime_error("init(): SDL_image could not Initialize! "
								 "SDL_image Error: " + 
								 std::string(IMG_GetError()));
	
}

	
	SDL_Surface* load_surface_for(const std::string& path, 
								  SDL_Surface* window_surface_ptr)
	{
		// Helper function to load a png for a specific surface
		// See SDL_ConvertSurface
		if (!window_surface_ptr){
			std::cout << "Error : window surface ptr is invalid" << std::endl;
			return (nullptr);
		}

		window_surface_ptr = SDL_ConvertSurface(IMG_Load(path.c_str()), window_surface_ptr->format, 0);
		if (!window_surface_ptr){
			std::cout << "Error during creation of surface." << std::endl;
			return (nullptr);
		}

		return window_surface_ptr;
	}	

