#include "sheep.h"

//float X_pos = rand() % frame_width + 1; //position X de l'animal (aleatoire)
//float Y_pos = rand() % frame_height + 1; // position Y de lanimal

void sheep::move(){

    //bounces on the sides
    if (X_pos == 1 || X_pos == frame_width) {
        switch (lastDir) {
        case 0:
            dir = UPRIGHT;   //this code checks if the sheep is right next to a wall 
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
    if (Y_pos == 1 || Y_pos == frame_height) {
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
            X_pos--;     //this code moves the sheep 
            Y_pos--;     
            break;       
        case UPRIGHT:
            X_pos++;
            Y_pos--;
            break;
        case DOWNLEFT:
            X_pos--;
            Y_pos++;
            break;
        case DOWNRIGHT:
            X_pos++;
            Y_pos++;
            break;
        case UP:
            X_pos++;
            break;
        case DOWN:
            X_pos--;
            break;
        case LEFT:
            Y_pos++;
            break;
        case RIGHT:
            Y_pos--;
            break;
    }
    lastDir = dir; //it saves the last direction
}                 


sheep::~sheep(){
    SDL_FreeSurface(image_);
    std::cout << "A sheep was eaten" << std::endl;
};
