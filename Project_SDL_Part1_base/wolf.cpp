#include "wolf.h"

/**
 * Cette fonction calcule la distance min du loup avec un des sheep du ground
 * et met la position du sheep le plus proche dans neareast_sheep
*/
void wolf::get_neareast_animal(std::vector<std::shared_ptr<animal>> animals){
    int sheep_distance_x ;
    int sheep_distance_y ;
    int sheep_distance ;
    int neareast = frame_width;
    
    for (auto &animal_ptr : animals) {
        if (animal_ptr->type == SHEEP){
            
        	sheep_distance_x = animal_ptr->pos.x - pos.x;
            sheep_distance_y = animal_ptr->pos.y - pos.y;
            sheep_distance = sqrt(pow(sheep_distance_x, 2) + pow(sheep_distance_y, 2));
            if (neareast > sheep_distance){
                neareast = sheep_distance;
                nearest_sheep_pos_ = animal_ptr->pos;
            }
        }
    }
    

}

/**
 * Cette fonction doit calculer le temps ecouler depuis qu'un loup n'a pas manger de mouton 
 * ne marche pas encore !!
*/
void wolf::time_to_catch(){
    if (nearest_sheep_pos_.x == pos.x && nearest_sheep_pos_.y== pos.y){
        get_Sheep = true;
        m_lastMealTime = SDL_GetTicks();
        
    }

    Uint32 elapsedTime = SDL_GetTicks() - m_lastMealTime;
    
    if (elapsedTime > kStarvationPeriod) {
            std::cout << "Wolf has died of starvation" << std::endl;
            isalive = false;
            
    }
}
/**
 * Cette fonction bouge le loup dans la direction du mouton le + proche
 **/
void wolf::move() {
    
    // TODO faire une fonction qui tient le loup eloigné du sheperd dog qui est plus important que de chasser
    // 1. SI assez loin du dog alors hunt
    // Else get_far
    
    if (pos.x > nearest_sheep_pos_.x )
        pos.x --;
    if (pos.x < nearest_sheep_pos_.x )
        pos.x ++;
    if (pos.y > nearest_sheep_pos_.y )
        pos.y --;
    if (pos.y < nearest_sheep_pos_.y )
        pos.y ++;

   // wolf::time_to_catch();
}

/*
 // Create a time_point that will hold the start time
    std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();

    // Perform some operation
    std::this_thread::sleep_for(std::chrono::seconds(5));

    // Calculate the duration of the operation
    std::chrono::duration<double> duration = std::chrono::steady_clock::now() - start;
    std::cout << "Duration of operation: " << duration.count() << " seconds" << std::endl;

    // Reset the time_point to the current time
    start = std::chrono::steady_clock::now();
*/

