#include "utility.h"




/*utility::utility(const std::string &file_path, SDL_Surface *window_surface_ptr)
{
    window_surface_ptr_ = window_surface_ptr;
    image_ = load_surface_for(file_path, window_surface_ptr_);
	if(NULL == image_){
        fprintf(stderr, "Erreur SDL_LoadBMP : %s", SDL_GetError());
    }

}*/

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
	/*Rajout pour ouvrir la fenêtre*/
	
}

	// Defining a namespace without a name -> Anonymous workspace
	// Its purpose is to indicate to the compiler that everything
	// inside of it is UNIQUELY used within this source file
	
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

