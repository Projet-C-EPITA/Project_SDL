#include "wolf.h"

float X_pos = rand() % frame_width + 1; //position X de l'animal (aleatoire)
float Y_pos = rand() % frame_height + 1; // position Y de lanimal

// void wolf::move(){
//     switch(rand()% dir){
//         case UPLEFT: 
//             X_pos--;     //this code moves the sheep 
//             Y_pos--;     
//             break;       
//         case UPRIGHT:
//             X_pos++;
//             Y_pos--;
//             break;
//         case DOWNLEFT:
//             X_pos--;
//             Y_pos++;
//             break;
//         case DOWNRIGHT:
//             X_pos++;
//             Y_pos++;
//             break;
//         case UP:
//             X_pos++;
//             break;
//         case DOWN:
//             X_pos--;
//             break;
//         case LEFT:
//             Y_pos++;
//             break;
//         case RIGHT:
//             Y_pos--;
//             break;
//     }
// }

wolf::~wolf(){
    SDL_FreeSurface(image_);
    std::cout << "A wolf is DEAD" << std::endl;
};
