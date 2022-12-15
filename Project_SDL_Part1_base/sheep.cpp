
#include "sheep.h"

void sheep::move(){

    //bounces on the sides
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
  }                 
