#include "sheep_dog.h"


void sheep_dog::move()
{

    int x_diff = pos.x - shepherd_pos_.x;
    int y_diff = pos.y - shepherd_pos_.y;

    double distance = sqrt(x_diff * x_diff + y_diff * y_diff);

    // If the dog is close to the shepherd, rotate around it
    if (distance > POINT_RADIUS) {
        pos.x = cos(angle) * (x_diff)-sin(angle) * (y_diff) + shepherd_pos_.x;
        pos.y = sin(angle) * (x_diff) + cos(angle) * (y_diff) + shepherd_pos_.y;
        
   }
    // Else move towards the shepherd
    else {
        pos.x += speed * cos(0);
        pos.y += speed * sin(0);
    }
   
    
}

void sheep_dog::get_shepherd_pos(std::vector<std::shared_ptr<shepherd>> shepherds ){
   for (auto &shepherd_ptr : shepherds)
    {
        shepherd_pos_ = shepherd_ptr->get_pos_shepherd();
    }

}
