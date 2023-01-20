#ifndef UTILITY_H
#define UTILITY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_surface.h>
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <vector>
// Definitions
constexpr double frame_rate = 60.0; // refresh rate
constexpr double frame_time = 1. / frame_rate;
constexpr unsigned frame_width = 1400; // Width of window in pixel
constexpr unsigned frame_height = 800; // Height of window in pixel
const Uint32 kStarvationPeriod =
    15000; // Time before the wolf die of starvation
const Uint32 kOffspringPeriod = 10000; // Time before sheep can procreate create
// Minimal distance of animal to the border of the screen
constexpr unsigned frame_boundary = 100;

constexpr char file_path_sheep[] = "../../media/sheep.png";
constexpr char file_path_wolf[] = "../../media/wolf.png";
constexpr char file_path_shepherd[] = "../../media/shepherd.png";
constexpr char file_path_sheep_dog[] = "../../media/sheep_dog.png";

/**
 * @summary: Helper function to initialize SDL
 *
 */
void init();

/**
 * @summary: This function that loads an image file located at a specified path,
 * and creates an SDL_Surface from it
 * @param {file_path} : string of the name of the path of the file
 * @param {*window_surface_ptr} : is a pointer to an SDL_Surface object that
 * represents the surface of the window. Where the image will be drawn on
 * screen.
 */
SDL_Surface *load_surface_for(const std::string &path,
                              SDL_Surface *window_surface_ptr);

#endif