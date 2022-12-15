#include "wolf.h"

void wolf::move() {
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

   if (pos.x == 1 || pos.x == frame_width -image_->w) {
          switch (lastDir) {
          case 0:
              dir = DOWNRIGHT;  
              break;           
          case 1:             
              dir = DOWNLEFT;
              break;
          case 2:
              dir = UPLEFT;
              break;
          case 3:
              dir = UPRIGHT;
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
              dir = DOWNRIGHT;  
              break;           
          case 1:             
              dir = DOWNLEFT;
              break;
          case 2:
              dir = UPLEFT;
              break;
          case 3:
              dir = UPRIGHT;
              break;
          case 4: 
              dir = DOWN; 
              break;
          case 5: 
              dir = UP;
              break; 
          }
      }
    
  // dir  = (rand()% 8) + 1;
    //std::cout << "dir" << dir << "\n" ;
      switch ((rand()% 8) + 1) {
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