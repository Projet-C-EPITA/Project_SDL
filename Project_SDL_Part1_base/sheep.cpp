
#include "sheep.h"


/*
* This function move the sheep so he bounces on walls & escape wolf
*/

void sheep::move(){

// check if wolf near sheep, if yes, go on the opposite direction
    if(to_close_sheep == 1 && pos.x != 1 && (pos.x + 1) < frame_width -image_->w && pos.y != 1 && (pos.y +1) < frame_height -image_->h){
        
        // test if wolf is on the left
        if(pos.x > nearest_wolf_pos_.x)
            // if wolf in same line than sheep
            if(pos.y == nearest_wolf_pos_.y || pos.y - 1 == nearest_wolf_pos_.y || pos.y + 1 == nearest_wolf_pos_.y)
                dir = RIGHT;
            //if wolf is up compared to sheep
            else if(pos.y > nearest_wolf_pos_.y)
                dir = DOWNRIGHT;
            //if wolf is down compared to sheep
            else
                dir = UPRIGHT;

        //test if wolf is on the right
        if(pos.x < nearest_wolf_pos_.x)
            //if wolf in same column than sheep
            if(pos.y == nearest_wolf_pos_.y|| pos.y - 1 == nearest_wolf_pos_.y || pos.y + 1 == nearest_wolf_pos_.y)
                // dir = LEFT_BOOST;
                dir = LEFT;
            //if wolf is up compared to sheep
            else if(pos.y > nearest_wolf_pos_.y)
                dir = DOWNLEFT;
            //if wolf is down compared to sheep
            else
                dir = UPLEFT;
   
    }

    //bounces on the sides
    else{
        if (pos.x == 1 || (pos.x - 1) >= frame_width -image_->w) {
            speed = 2;
            // checks if the sheep is right next to a wall
            switch (lastDir) {
            case 0:
                dir = UPRIGHT;   
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
            case 6: 
                dir = LEFT;
                break;
            case 7: 
                dir = RIGHT;
                break;
            case 8:
                dir = UPLEFT;
                break;
            case 9:
                dir = UPRIGHT;
                break;
            case 12:
                dir = UPRIGHT;
                break;
            case 13:
                dir = UPLEFT;
                break;
            case 14:
                dir = DOWNLEFT;
                break;
            case 15:
                dir = DOWNRIGHT;
                break;
            }
        }
        //bounces on the top and bottom
        if (pos.y == 1 || (pos.y -1) >= frame_height -image_->h) {
            speed = 2;
            switch (lastDir) {
            case 0:
                dir = DOWNLEFT;  
                break;           
            case 1:             
                dir = DOWNRIGHT;
                break;
            case 2:
                dir = UPRIGHT;
                break;
            case 3:
                dir = UPLEFT;
                speed = 2;
                break;
            case 4: 
                dir = DOWNRIGHT_BOOST; 
                break;
            case 5: 
                dir = UPRIGHT_BOOST;
                break; 
            case 7:
                dir = RIGHT_BOOST;
                break;
            case 10:
                dir = DOWNRIGHT;
                break;
            case 11:
                dir = UPLEFT;
                break;
            case 12:
                dir = DOWNLEFT;
                break;
            case 13:
                dir = DOWNRIGHT;
                break;
            case 14:
                dir = UPRIGHT_BOOST;
                break;
            case 15:
                dir = UPLEFT;
                break;
            }
        }
        
    }
    //modify direction based on previous conditions
    switch (dir) {
        case UPLEFT: 
            pos.x -= speed;     
            pos.y -= speed;     
            break;       
        case UPRIGHT:
            pos.x += speed;
            pos.y -= speed;
            break;
        case DOWNRIGHT:
            pos.x += speed;
            pos.y += speed;
            break;
        case DOWNLEFT:
            pos.x -= speed;
            pos.y += speed;
            break;
        case UP:
            pos.x += speed;
            break;
        case DOWN:
            pos.x -= speed;
            break;
        case RIGHT:
            pos.y -= speed;
            break;
        case LEFT:
            pos.y += speed;
            break;
        case RIGHT_BOOST:
            pos.x += 2;
            break;
        case LEFT_BOOST:
            pos.x -= 2;
            break;
        case UP_BOOST:
            pos.y -= 2;
            break;
        case DOWN_BOOST:
            pos.y += 2;
            break;
        case UPLEFT_BOOST:
            pos.x -= 2;
            pos.y -= 2;
            break;
        case UPRIGHT_BOOST:
            pos.x += 2;
            pos.y -= 2;
            break;
        case DOWNRIGHT_BOOST:
            pos.x += 2;
            pos.y += 2;
            break;
        case DOWNLEFT_BOOST:
            pos.x -= 2;
            pos.y += 2;
            break;

    }
    //saves last direction
    lastDir = dir;
     
  }    


/**
 * function to get nearest wolf to go on opposite direction
*/
void sheep::get_nearest_wolf(std::vector<std::shared_ptr<animal>> animals){
    int animal_distance_x ;
    int animal_distance_y ;
    int animal_distance ;
    int nearest = frame_width;
    int near_sheep = 0;
    for (auto &animal_ptr : animals) {
        
        if(animal_ptr->type == WOLF){
            animal_distance_x = animal_ptr->pos.x - pos.x;
            animal_distance_y = animal_ptr->pos.y - pos.y;
            animal_distance = sqrt(pow(animal_distance_x, 2) + pow(animal_distance_y, 2));
            
            if (nearest > animal_distance){
                nearest = animal_distance;
                nearest_wolf_pos_ = animal_ptr->pos;
            }
            //if wolf is too close compared to a certain distance, increase speed
            if (animal_distance < DIST_MIN_WOLF + 5){
                to_close_sheep = true;
                speed = 2;
                break;
            }
            else{
                to_close_sheep = false;
                speed = 1;
            }
        }
        //condition to determine if offspring
        else if(animal_ptr->type == SHEEP){
            offspring = false;
            animal_distance_x = animal_ptr->pos.x - pos.x;
            animal_distance_y = animal_ptr->pos.y - pos.y;
            animal_distance = sqrt(pow(animal_distance_x, 2) + pow(animal_distance_y, 2));
            Uint32 elapsedTime = SDL_GetTicks() - last_offspring;

            //if 2 sheeps are on top of each other  
            if(animal_distance < 10 && (((animal_ptr->sex == FEMALE) && (sex = MALE) && elapsedTime >= kOffspringPeriod) 
            || ((animal_ptr->sex == MALE) && (sex = FEMALE))) ){
                near_sheep++;
            }
                
            
            if(near_sheep == 2){
                offspring = true;
                last_offspring = SDL_GetTicks();
            }
        }
    }
    
}

