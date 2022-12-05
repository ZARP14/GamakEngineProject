#ifndef IMPERMANENTOBJECTS_HPP
#define IMPERMANENTOBJECTS_HPP

#include <iostream>
#include <math.h>

#include "domain/const.hpp"
#include "domain/time.hpp"

#include "objects/sfmlObjects.hpp"

class ImpermanentObjects : public SFMLObjects
{
public:
    ImpermanentObjects();
    void gravity();

    void moveChanger(int direction, bool typeOfMoveChanger, bool stoper = 0);
    void moveStoper(bool flag, bool type);
    void movingHorizontal();
    void movingVertical();

protected:
    std::pair<int, int> collisionIntersection(sf::Sprite s);
    bool finalCollisionIntersection(int side);

    int horizontalSpeed;
    int verticalSpeed;
    int objectVerticalSpeed;
    int objectVerticalDirection;
    int objectHorizontalDirection;
    bool objectVerticalStoper;
    bool objectHorizontalStoper;
    int mGravity;
};

#endif // !ALIVEOBJECTS_HPP
