#include "sheep_dog.h"


void sheep_dog::move()
{
    
    int x_diff = pos.x - shepherd_pos_.x;
    int y_diff = pos.y - shepherd_pos_.y;
    double distance = sqrt(x_diff * x_diff + y_diff * y_diff);

    // Calculate the angle between the dog and the shepherd
    angle = atan2(y_diff, x_diff);

    // If the dog is close to the shepherd, rotate around it
    if (distance > POINT_RADIUS) {
        pos.x = shepherd_pos_.x + POINT_RADIUS * cos(angle);
        pos.y = shepherd_pos_.y + POINT_RADIUS * sin(angle);
    }
    // Else move towards the shepherd
    else {
        pos.x += speed * cos(angle);
        pos.y += speed * sin(angle);
    }
   /* angle += speed;
    if (angle >= 360)
    {
        angle = 0;
    }
    int position_x = shepherd_x + POINT_RADIUS * cos(angle * M_PI / 100.0);
    int position_y = shepherd_y + POINT_RADIUS * sin(angle * M_PI / 100.0);
    */
    
}

void sheep_dog::get_shepherd_pos(std::vector<std::shared_ptr<shepherd>> shepherds ){
   for (auto &shepherd_ptr : shepherds)
    {
        shepherd_pos_ = shepherd_ptr->get_pos_shepherd();
        
        
    
    }

}