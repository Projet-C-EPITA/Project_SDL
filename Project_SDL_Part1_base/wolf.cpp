#include "wolf.h"

/**
 * Cette fonction calcule la distance min du loup avec un des sheep du ground
 * et met la position du sheep le plus proche dans neareast_sheep
*/
void wolf::get_neareast_animal(std::vector<std::shared_ptr<animal>> animals){
    int animal_distance_x ;
    int animal_distance_y ;
    int animal_distance ;
    int neareast = frame_width;
    
    for (auto &animal_ptr : animals) {
        if (animal_ptr->type == SHEEP){
            
        	animal_distance_x = animal_ptr->pos.x - pos.x;
            animal_distance_y = animal_ptr->pos.y - pos.y;
            animal_distance = sqrt(pow(animal_distance_x, 2) + pow(animal_distance_y, 2));
            if (neareast > animal_distance){
                neareast = animal_distance;
                nearest_sheep_pos_ = animal_ptr->pos;
            }
        }
        // PAs fou de copier a voir si mieux plus tard
        else if (animal_ptr->type == DOG){
            animal_distance_x = animal_ptr->pos.x - pos.x;
            animal_distance_y = animal_ptr->pos.y - pos.y;
            animal_distance = sqrt(pow(animal_distance_x, 2) + pow(animal_distance_y, 2));
            if (neareast > animal_distance){
                neareast = animal_distance;
                closest_dog_pos_ = animal_ptr->pos;
                // Verifie si le chien du shepherd est trop proche du loup
                if (animal_distance < DIST_MIN_WOLF)
                    to_close = true;
                else{
                    to_close = false;
                }
            }
        }
    }
    
}




/**
 * Cette fonction bouge le loup dans la direction du mouton le + proche 
 * mais en evitant les chiens du bergers en priorité
 **/
void wolf::move() {
    
    // SI un chien est trop proche alors le loup s'en eloigne
    if (to_close){
        if (pos.x > closest_dog_pos_.x )
            pos.x ++;
        if (pos.x < closest_dog_pos_.x )
            pos.x --;
        if (pos.y > closest_dog_pos_.y )
            pos.y ++;
        if (pos.y < closest_dog_pos_.y )
            pos.y --;
    }
    //Sinon il se rapproche d'un mouton
    else{
        if (pos.x > nearest_sheep_pos_.x )
            pos.x --;
        if (pos.x < nearest_sheep_pos_.x )
            pos.x ++;
        if (pos.y > nearest_sheep_pos_.y )
            pos.y --;
        if (pos.y < nearest_sheep_pos_.y )
            pos.y ++;

    }
    
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