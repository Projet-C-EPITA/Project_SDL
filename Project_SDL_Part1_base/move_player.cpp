#include "move_player.h"
#include "Project_SDL1.h"

int move_player::get_x()
{
    return this->x;
}
int move_player::get_y()
{
    return this->y;
}

int move_player::get_dirx()
{
    return this->dirx;
}
int move_player::get_diry()
{
    return this->diry;
}

void move_player::set_x(int x)
{
    this->x = x;
}
void move_player::set_y(int y)
{
    this->y = y;
}