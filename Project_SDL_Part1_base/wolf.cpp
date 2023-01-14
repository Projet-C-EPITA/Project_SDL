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

void wolf::move() {
    //1.Parcourir la liste des animaux (direct sur les sheep) sur le ground (good)
    //2.Verifier si l'animal est un sheep( good)
    //3. calculer entre les point du loup et celui du sheep quel sheep est le + proche (distance min) (fait)
    //4. aller vers cette destination
   
   /* if (pos.x < nearest_sheep_pos_.x && pos.y < nearest_sheep_pos_.y){
        pos.x++;     
        pos.y++;
        // DOWNRIGHT
    }
    if (pos.x > nearest_sheep_pos_.x && pos.y > nearest_sheep_pos_.y){
        pos.x--;     
        pos.y--;
        //UPLEFT
    }
    if (pos.x < nearest_sheep_pos_.x && pos.y > nearest_sheep_pos_.y){
        pos.x++;
        pos.y--;
        // UPRIGTH
    }
    if (pos.x > nearest_sheep_pos_.x && pos.y < nearest_sheep_pos_.y){
        pos.x--;
        pos.y++;
        //DOWNLEFT
    }*/
    if (pos.x > nearest_sheep_pos_.x )
        pos.x --;
    if (pos.x < nearest_sheep_pos_.x )
        pos.x ++;
    if (pos.y > nearest_sheep_pos_.y )
        pos.y --;
    if (pos.y < nearest_sheep_pos_.y )
        pos.y ++;

   

    /*
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
       
         */  

}

 
    //}
    //Selection d'une direction aléatoire entre -8 et 10 de base de faisait entre -1 et 1
/*	int rand_dirX = 2* (rand()%3 - 1); // soit +1 soit -1
	int rand_dirY = 2* (rand()%3- 1);

    std::cout << "randx"<< rand_dirX << "randy : " << rand_dirY << "\n";
    std::cout << "x:" << pos.x << "y : " << pos.y << "\n";
    
    // Verifie si loup ne touche pas le bord
    if (pos.y <= 1 || pos.y >= frame_height - image_->h) {
       // std::cout << "loup touche bord Y"  << "/n";
        if (rand_dirY > 0)
            rand_dirY *=-rand_dirY;
    }
        //rand_dirY == 1 ? rand_dirY * (-1) : rand_dirY;
    
    if (pos.x <= 1 || pos.x >= frame_width - image_->w) 
    {
       std::cout << "loup touche bord X" <<"/n" ;
        if (rand_dirX > 0)
            rand_dirX *=-rand_dirX;
    }
        //rand_dirX == 1 ? rand_dirX * (-1) : rand_dirX;
     
    pos.x += rand_dirX;
    pos.y += rand_dirX;
    */