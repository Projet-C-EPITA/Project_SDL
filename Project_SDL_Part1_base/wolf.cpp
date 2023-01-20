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
                nearest_sheep = animal_ptr;
                nearest_sheep_pos_ = animal_ptr->pos;
            }
        }
        
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
    is_get_sheep();
    time_to_catch();
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
    
   
}


/**
 * Cette fonction doit calculer le temps ecouler depuis qu'un loup n'a pas manger de mouton 
 * ne marche pas encore !!
*/
void wolf::time_to_catch()
{
    if (get_Sheep) 
    {
        m_lastMealTime = SDL_GetTicks();
    }
    else{
        Uint32 elapsedTime = SDL_GetTicks() - m_lastMealTime;

        if (elapsedTime > kStarvationPeriod)
        {
            isalive = false;
        }
    }
    
}

void wolf::is_get_sheep(){
    // Il y a une difference de position de 1 entre les deux image quand elle sont l'un sur l'autre
    if ((nearest_sheep_pos_.x == pos.x || 
    (nearest_sheep_pos_.x - 1 == pos.x) || (nearest_sheep_pos_.x + 1 == pos.x) || (nearest_sheep_pos_.x + 2 == pos.x) || (nearest_sheep_pos_.x - 2 == pos.x)) 
    && (nearest_sheep_pos_.y == pos.y || (nearest_sheep_pos_.y -1) == pos.y ||(nearest_sheep_pos_.y +1) == pos.y || (nearest_sheep_pos_.y -2) == pos.y ||(nearest_sheep_pos_.y +2) == pos.y)){
        get_Sheep = true;
        nearest_sheep->isalive = false;


    }
    else{
        get_Sheep = false;
    }
}