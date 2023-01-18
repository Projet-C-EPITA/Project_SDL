#include "moving.h"
#include "Project_SDL1.h"

// Getter et Setter du joueur
int moving::getX()
{
    return this->x;
}

int moving::getY()
{
    return this->y;
}

void moving::setX(int x)
{
    this->x = x;
}

void moving::setY(int y)
{
    this->y = y;
}

int moving::getDirX()
{
    return this->dirX;
}

int moving::getDirY()
{
    return this->dirY;
}
