#include "sheep_dog.h"


void sheep_dog::move()
{
    
    int shepherd_x = shepherd_pos_.x;
    int shepherd_y = shepherd_pos_.y;
    angle += speed;
    if (angle >= 360)
    {
        angle = 0;
    }
    int position_x = shepherd_x + POINT_RADIUS * cos(angle * M_PI / 100.0);
    int position_y = shepherd_y + POINT_RADIUS * sin(angle * M_PI / 100.0);
    
}

void sheep_dog::get_shepherd_pos(std::vector<std::shared_ptr<shepherd>> shepherds ){
   for (auto &shepherd_ptr : shepherds)
    {
        shepherd_pos_ = shepherd_ptr->get_pos_shepherd();
        
    
    }

}