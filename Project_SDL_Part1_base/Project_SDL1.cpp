#include "Project_SDL1.h"

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <numeric>
#include <random>
#include <string>
#include <SDL.h>
#include "animal.h"
#include "wolf.h"
#include "sheep.h"


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
namespace {
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
		
}

// ---------------------------------Partie Animal ----------------------------------------


animal::animal(const std::string& file_path, SDL_Surface* window_surface_ptr){
    window_surface_ptr_ = window_surface_ptr;
    image_ = load_surface_for(file_path, window_surface_ptr_); /*Pour charger une image*/
    if(NULL == image_){
        fprintf(stderr, "Erreur SDL_LoadBMP : %s", SDL_GetError());
    }

    pos.x = rand() % frame_width + 1; //position aleatoire de l'animal 
    pos.y = rand() % frame_height + 1;
	pos.w = image_->w;
    pos.h = image_->h;
    
}
void animal::draw(){
			//SDL_Surface* image = IMG_Load(file_path);
			//SDL_Texture* texture = SDL_CreateTextureFromSurface(window_renderer_, image_);
			//SDL_Rect rect = {pos.w, pos.h, pos.x, pos.y};
			SDL_BlitSurface(image_, NULL, window_surface_ptr_, &pos);
		};

/*SDL_Rect animal::get_position() {
  return this->pos;
}*/

animal::~animal(){
    SDL_FreeSurface(image_);
   // SDL_FreeSurface(window_surface_ptr_);
};


 // ----------------------------------------Partie Sheep --------------------------------------

void sheep::move(){

    //bounces on the sides
      if (pos.x == 1 || pos.x == frame_width -100) {
          switch (lastDir) {
          case 0:
              dir = UPRIGHT;    //this code checks if the sheep is right next to a wall 
              break;                 
          case 1:               
              dir = UPLEFT;    
              break;
          case 2:
              dir = DOWNLEFT;
              break;
          case 3:
              dir = DOWNRIGHT;
              break;
          case 6: // pas mis de case 4 parceque on atteint pas les side si on va que en haut
              dir = LEFT;//pas sur que ca soit atteint
              break;
          case 7: 
              dir = RIGHT;
              break;
          }
      }
      //bounces on the top and bottom
      if (pos.y == 1 || pos.y == frame_height -100) {
          switch (lastDir) {
          case 0:
              dir = DOWNLEFT;  //same thing down here but for
              break;           //the top and bottom
          case 1:             
              dir = DOWNRIGHT;
              break;
          case 2:
              dir = UPRIGHT;
              break;
          case 3:
              dir = UPLEFT;
              break;
          case 4: 
              dir = DOWN; 
              break;
          case 5: 
              dir = UP;
              break; 
          }
      }

      switch (dir) {
          case UPLEFT: 
               pos.x--;     //this code moves the sheep 
               pos.y--;     
              break;       
          case UPRIGHT:
               pos.x++;
               pos.y--;
              break;
          case DOWNLEFT:
               pos.x--;
               pos.y++;
              break;
          case DOWNRIGHT:
               pos.x++;
               pos.y++;
              break;
          case UP:
               pos.x++;
              break;
          case DOWN:
               pos.x--;
              break;
          case LEFT:
               pos.y++;
              break;
          case RIGHT:
               pos.y--;
              break;
      }
      lastDir = dir; //it saves the last direction
  }                 


 //----------------------------------------Partie Wolf ---------------------------------------
void wolf::move(){
    //Selection d'une direction aléatoire entre -8 et 10 de base de faisait entre -1 et 1
	int rand_dirX = 4* (rand()%10 - 8); // soit +1 soit -1
	int rand_dirY = 4* (rand()%10- 8);

    std::cout << rand_dirX << "y : " << rand_dirY << "\n";
    
    // Verifie si loup ne touche pas le bord
    if (pos.y == 1 || pos.y >= frame_height - 100) {
       // std::cout << "loup touche bord Y"  << "/n";
        if (rand_dirY > 0)
            rand_dirY *=-1;
    }
        //rand_dirY == 1 ? rand_dirY * (-1) : rand_dirY;
    
    if (pos.x == 1 || pos.x >= frame_width - 100) 
    {
       // std::cout << "loup touche bord X" <<"/n" ;
        if (rand_dirX > 0)
            rand_dirX *=-1;
    }
        //rand_dirX == 1 ? rand_dirX * (-1) : rand_dirX;
     
    pos.x += rand_dirX;
    pos.y += rand_dirX;

}

//---------------------------------------Partie Ground -----------------------------------------

ground::ground(SDL_Surface* window_surface_ptr){
		window_surface_ptr_ = window_surface_ptr;
}


void ground::add_animal(const std::shared_ptr<animal>& animal){
		 animals.push_back(animal);
}

void ground::update(){

		for (auto &animal_ptr : animals)
        	animal_ptr->move();
		// Clear the screen
		SDL_FillRect(window_surface_ptr_, nullptr ,SDL_MapRGB(window_surface_ptr_->format, 0, 255, 0));
		// Draw all animals
		for (auto &animal_ptr : animals)
			animal_ptr->draw();		
}

	


// ---------------------------------------------Partie Application --------------------------------
	
	application::application(unsigned n_sheep, unsigned n_wolf){
		
		Nsheep = n_sheep;
		Nwolf = n_wolf;
		createWindow();	
		ground_ = std::make_unique<ground>(window_surface_ptr_);
	
		for (int i = 0; i < Nsheep; ++i) {
			std::shared_ptr<sheep> sheeps = std::make_shared<sheep>(file_path_sheep, window_surface_ptr_);
			ground_->add_animal(sheeps);
			sheeps->draw();
		}

		for (int i = 0; i < Nwolf; ++i) {
			std::shared_ptr<wolf> wolfs =std::make_shared<wolf>(file_path_wolf, window_surface_ptr_);
			ground_->add_animal(wolfs);
			wolfs->draw();
		}
	}	

	application::~application(){
		SDL_DestroyWindow(window_ptr_);
		std::cout << "Window destroy\n";

		IMG_Quit();
    	SDL_Quit();
	}

	void application::createWindow(){
		window_ptr_ = SDL_CreateWindow("Game SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, frame_width, frame_height, SDL_WINDOW_SHOWN);
		std::cout <<"window created\n";
		if (window_ptr_ == nullptr) {
			SDL_Log("Could not create a window: %s", SDL_GetError());
		}
		window_renderer_ = SDL_CreateRenderer(window_ptr_, -1, SDL_RENDERER_ACCELERATED);
		if (window_renderer_ == nullptr) {
			SDL_Log("Could not create a renderer: %s", SDL_GetError());
		}

		window_surface_ptr_ =  SDL_GetWindowSurface(window_ptr_);
		if (window_surface_ptr_ == nullptr){
			SDL_DestroyWindow(window_ptr_);
			SDL_Log("Could not create a window: %s", SDL_GetError());
		}
		SDL_FillRect(window_surface_ptr_, nullptr, SDL_MapRGB(window_surface_ptr_->format, 0, 255, 0));

		
	}
	

	int application::loop(unsigned period){
		//animal wolf("../../media/wolf.png", window_surface_ptr_);
		//wolf.draw();

		while(SDL_GetTicks() < (period*1000) && is_open){
			SDL_PollEvent(&window_event_);
			switch (window_event_.type) {
				case SDL_QUIT:
					is_open = false;
					break;
			}
			ground_->update();
			SDL_UpdateWindowSurface(window_ptr_);
		}		
		
		//A mettre dans le dtor de app
		SDL_DestroyRenderer(window_renderer_);
		SDL_DestroyWindow(window_ptr_);
		SDL_Quit();
		
		return period;
	}

	

	