#ifndef PROJECT_H
#define PROJECT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <vector>

#include "animal.h"
#include "sheep.h"
#include "shepherd.h"
#include "utility.h"
#include "wolf.h"

class ground
{
private:
    // Attention, non-owning ptr, again to the screen
    SDL_Surface *window_surface_ptr_;


public:
    // number of loops done
    unsigned count_loop;

    // number of babies byloop
    unsigned nb_babies = 0;

    std::vector<std::shared_ptr<animal>> animals;
    std::vector<std::shared_ptr<shepherd>> shepherds;

    int scoreF;// Final score which correspond to the number of sheep on the ground

    ground(SDL_Surface *window_surface_ptr);
     
    /**
     * @summary: This function count the number of loop passed for sheeps
     * @param {count} : the number of loop
     *
     */
    void set_CountLoop(unsigned count);
    
     /**
     * @summary: This function add a new animal to the vector animals
     * @param {animal} : shared pointeur of animal
     *
     */
    void add_animal(const std::shared_ptr<animal> &animal);

    /**
     * @summary: This function add a new shepherd to the vector shepherds
     * @param {animal} : shared pointeur of shepherd
     *
     */
    void add_shepherd(const std::shared_ptr<shepherd> &shepherd);

    /**
     * @summary: This function Refresh the screen : Move animals/Shepherd and draw them
     * 
     */ 
    unsigned update();

    ~ground(){};
   
};

// The application class, which is in charge of generating the window
class application
{
private:
    // The following are owning ptrs
    SDL_Window *window_ptr_;
    SDL_Surface *window_surface_ptr_;
    SDL_Renderer *window_renderer_;
    SDL_Event window_event_;
    unsigned Nsheep;
    unsigned Nwolf;
    unsigned int lastTime = 0, currentTime;
    bool is_open{ true };

    std::unique_ptr<ground> ground_;

public:
    // Ctor
    application(unsigned n_sheep, unsigned n_wolf);

    // Dtor
    ~application();

    void createWindow();

    // set number of sheeps
    void add_sheep();

    /**
     * @summary: Main loop of the application. This ensures that the screen is
     * updated at the correct rate. See SDL_GetTicks() and SDL_Delay() to
     * enforce a duration the application should terminate after 'period'
     * seconds.
     * @param {period}: Correspond to the time in ms that the Application will
     * be open.
     */
    int loop(unsigned period);
};
#endif