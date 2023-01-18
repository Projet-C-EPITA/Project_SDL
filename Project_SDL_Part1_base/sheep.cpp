
#include "sheep.h"


/*
* Cette fonction bouge le mouton de sorte à ce qu'il rebondisse sur les murs
*/

void sheep::move(){

// check if wolf near sheep, if yes, go on the opposite direction with a boost
    if(to_close_sheep == 1 && pos.x != 1 && (pos.x - 1) < frame_width -image_->w && pos.y != 1 && (pos.y -1) < frame_height -image_->h){
        // if(to_close_sheep == 1){
        // if(pos.x > nearest_wolf_pos_.x && (pos.y == nearest_wolf_pos_.y || pos.y - 1 == nearest_wolf_pos_.y || pos.y + 1 == nearest_wolf_pos_.y))
        //test si le loup est à gauche du sheep
        if(pos.x > nearest_wolf_pos_.x)
            //si loup au même niveau que le sheep sur y
            if(pos.y == nearest_wolf_pos_.y || pos.y - 1 == nearest_wolf_pos_.y || pos.y + 1 == nearest_wolf_pos_.y)
                dir = RIGHT_BOOST;
            //si le loup en bas du sheep en y
            else if(pos.y > nearest_wolf_pos_.y)
                dir = DOWNRIGHT_BOOST;
            //si le loup en haut du sheep en y
            else
                dir = UPRIGHT_BOOST; 

        //test si le loup est à droite du sheep
        if(pos.x < nearest_wolf_pos_.x)
            //si loup au même niveau que le sheep sur y
            if(pos.y == nearest_wolf_pos_.y|| pos.y - 1 == nearest_wolf_pos_.y || pos.y + 1 == nearest_wolf_pos_.y)
                dir = LEFT_BOOST;
            //si le loup en bas du sheep en y
            else if(pos.y > nearest_wolf_pos_.y)
                dir = DOWNLEFT_BOOST;
            //si le loup en haut du sheep en y
            else
                dir = UPLEFT_BOOST;  

        //test si le loup est sur la même ligne que le sheep en x
        if(pos.x == nearest_wolf_pos_.x)
            //si le loup est en bas du sheep en y
            if(pos.y > nearest_wolf_pos_.y)
                dir = DOWN_BOOST;
            //si le loup est en haut du sheep en y
            else
                dir = UP_BOOST;
        // // if(pos.y > nearest_wolf_pos_.x && (pos.x == nearest_wolf_pos_.x || pos.x - 1 == nearest_wolf_pos_.x || pos.x + 1 == nearest_wolf_pos_.x))
        // //     dir = DOWN_BOOST;
        // if(pos.x < nearest_wolf_pos_.x && (pos.y == nearest_wolf_pos_.y || pos.y - 1 == nearest_wolf_pos_.y || pos.y + 1 == nearest_wolf_pos_.y))
        //     dir = LEFT_BOOST;
        // if(pos.y < nearest_wolf_pos_.x && (pos.y == nearest_wolf_pos_.y || pos.y - 1 == nearest_wolf_pos_.y || pos.y + 1 == nearest_wolf_pos_.y))
        //     dir = UP_BOOST;

        // if(pos.x > nearest_wolf_pos_.x || pos.y > nearest_wolf_pos_.y)
        //     dir = RIGHT_BOOST;
        // if(pos.x < nearest_wolf_pos_.x || pos.y < nearest_wolf_pos_.y)
        //     dir = DOWN_BOOST;

            
    }
    //bounces on the sides
    else{
        if (pos.x == 1 || (pos.x - 1) >= frame_width -image_->w) {
            switch (lastDir) {
            case 0:
                // dir = UPRIGHT;    //this code checks if the sheep is right next to a wall 
                dir = DOWNLEFT;   
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

    switch (dir) {
        case UPLEFT: 
            pos.x--;     //this code moves the sheep 
            pos.y--;     
            break;       
        case UPRIGHT:
            pos.x++;
            pos.y--;
            break;
        case DOWNRIGHT:
            pos.x++;
            pos.y++;
            break;
        case DOWNLEFT:
            pos.x--;
            pos.y++;
            break;
        case UP:
            pos.x++;
            break;
        case DOWN:
            pos.x--;
            break;
        case RIGHT:
            pos.y--;
            break;
        case LEFT:
            pos.y++;
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
                to_close_sheep = true;
            else{
                to_close_sheep = false;
            }
        }
    }
    
}


