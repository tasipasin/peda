#include "Position.h"
#include <sstream>

Position::Position()
{
}

Position::Position(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Position::getX()
{
    return this->x;
}

int Position::getY()
{
    return this->y;
}

void Position::setX(int x)
{
    this->x = x;
}

void Position::setY(int y)
{
    this->y = y;
}

bool Position::isEquals(Position obj)
{
    return (obj.getX() == this->x) && (obj.getY() == this->y);
}