
#include "sheep.h"


/*
* Cette fonction bouge le mouton de sorte à ce qu'il rebondisse sur les murs
*/

void sheep::move(){

// check if wolf near sheep, if yes, go on the opposite direction with a boost
    if(to_close){
        if(pos.x > nearest_wolf_pos_.x || pos.y > nearest_wolf_pos_.y)
            dir = UP_BOOST;
        if(pos.x < nearest_wolf_pos_.x || pos.y < nearest_wolf_pos_.y)
            dir = DOWN_BOOST;
    }
    //bounces on the sides
    else{
        if (pos.x == 1 || pos.x == frame_width -image_->w) {
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
            case 8:
                dir = DOWNLEFT;
                break;
            case 9:
                dir = UPRIGHT;
                break;
            }
            
        }
        //bounces on the top and bottom
        if (pos.y == 1 || pos.y == frame_height -image_->h) {
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
        case UP_BOOST:
            pos.x += 2;
            break;
        case DOWN_BOOST:
            pos.y += 2;
            break;
    }
    lastDir = dir; //it saves the last direction
     
  }    


/**
 * Calcule la position du loup le plus proche
*/
void sheep::get_nearest_wolf(std::vector<std::shared_ptr<animal>> animals){
    int animal_distance_x ;
    int animal_distance_y ;
    int animal_distance ;
    int nearest = frame_width;
    
    for (auto &animal_ptr : animals) {
        if(animal_ptr->type == WOLF){
            animal_distance_x = animal_ptr->pos.x - pos.x;
            animal_distance_y = animal_ptr->pos.y - pos.y;
            animal_distance = sqrt(pow(animal_distance_x, 2) + pow(animal_distance_y, 2));
            if (nearest > animal_distance){
                nearest = animal_distance;
                nearest_wolf_pos_ = animal_ptr->pos;
            }
            if (animal_distance < DIST_MIN_WOLF)
                to_close = true;
            else{
                to_close = false;
            }
            printf("TO CLOSE: %d\n", to_close);
        }
    }
    
}


