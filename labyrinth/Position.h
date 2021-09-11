#ifndef POSITION_H
#define POSITION_H

class Position
{
    int x, y;
public:
    Position();
    Position(int x, int y);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    bool isEquals(Position obj);
};
#endif