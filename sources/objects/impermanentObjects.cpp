#include "objects/impermanentObjects.hpp"

ImpermanentObjects::ImpermanentObjects()
{
    horizontalSpeed = 1;
    verticalSpeed = 1;
    objectVerticalSpeed = 0;
    objectVerticalDirection = 9999;
    objectHorizontalDirection = 9999;
    objectVerticalStoper = 1;
    objectHorizontalStoper = 1;
    mGravity = 0;
}

void
ImpermanentObjects::moveChanger(int direction, bool typeOfMoveChanger,
                                bool stoper)
{
    if (typeOfMoveChanger == int(sideType::vertical))
    {
        objectVerticalSpeed += mGravity;
        objectVerticalDirection = direction;
    }
    else if (typeOfMoveChanger == int(sideType::horizontal))
    {
        objectHorizontalDirection = direction;
    }
}

void
ImpermanentObjects::moveStoper(bool flag, bool type)
{

    switch (type)
    {
        case int(sideType::vertical):
            objectVerticalStoper = flag;
            break;

        case int(sideType::horizontal):
            objectHorizontalStoper = flag;
            break;
    }
}

void
ImpermanentObjects::movingHorizontal()
{
    bool collision = 1;
    bool stop = 1;

    int mDirection = 0;
    if (objectHorizontalDirection == int(side::left))
    {
        mDirection = -1;
        if (finalCollisionIntersection(int(side::left)) == true)
        {
            collision = 0;
        }
    }
    else if (objectHorizontalDirection == int(side::right))
    {
        mDirection = 1;
        if (finalCollisionIntersection(int(side::right)) == true)
        {
            collision = 0;
        }
    }
    objectSprite.move(horizontalSpeed * mDirection * objectHorizontalStoper *
                          collision,
                      /* Time::gameTime,*/ 0);
}

void
ImpermanentObjects::movingVertical()
{
    bool collision = true;
    int mVerticalSpeed = verticalSpeed;
    if (objectVerticalStoper == 0)
    {
        mVerticalSpeed = 0;
    }

    int mDirection = 0;
    if (objectVerticalDirection == int(side::down))
    {
        mDirection = 1;
        if (finalCollisionIntersection(int(side::down)) == true)
        {
            collision = 0;
        }
    }
    else if (objectVerticalDirection == int(side::top))
    {
        mDirection = -1;
        if (finalCollisionIntersection(int(side::top)) == true)
        {
            collision = 0;
        }
    }
    objectSprite.move(
        0, (mDirection * (objectVerticalSpeed + mVerticalSpeed * collision))/* *
               Time::gameTime*/);
}

void
ImpermanentObjects::gravity()
{
}

bool
ImpermanentObjects::finalCollisionIntersection(int side)
{
    for (int i = objectIndex + 1; i < Gui::global.SpriteVector.size(); i++)
    {
        if (objectIndex != 0)
        {
            if (i == Gui::global.SpriteVector.size())
            {
                i = 0;
            }
            else if (i == objectIndex)
            {
                break;
            }
        }

        switch (side)
        {
            case int(side::left):
                if (collisionIntersection(*Gui::global.SpriteVector[i]).first ==
                    int(side::left))
                    return true;
                break;

            case int(side::right):
                if (collisionIntersection(*Gui::global.SpriteVector[i]).first ==
                    int(side::right))
                    return true;
                break;

            case int(side::top):
                if (collisionIntersection(*Gui::global.SpriteVector[i])
                        .second == int(side::top))
                    return true;
                break;

            case int(side::down):
                if (collisionIntersection(*Gui::global.SpriteVector[i])
                        .second == int(side::down))
                    return true;
                break;
            default:
                break;
        }
    }
    return false;
}

std::pair<int, int>
ImpermanentObjects::collisionIntersection(sf::Sprite s)
{

    float sL = s.getGlobalBounds().left;
    float sT = s.getGlobalBounds().top;
    float sH = s.getGlobalBounds().height;
    float sW = s.getGlobalBounds().width;

    float fL = objectSprite.getGlobalBounds().left;
    float fT = objectSprite.getGlobalBounds().top;
    float fH = objectSprite.getGlobalBounds().height;
    float fW = objectSprite.getGlobalBounds().width;

    int verticalIntersection = 9;
    int horizontalIntersection = 9;

    // intersection of the left part
    if (((fL <= sL + sW && ((fT > sT && fT < sT + sH) ||
                            (fT + fH > sT && fT + fH < sT + sH)))) ||
        ((sL + sW > fL &&
          ((sT > fT && sT < fT + fH) || (sT + sH > fT && sT + sH < fT + fH)))))
    {
        if (fL + fW > sL + sW)
            horizontalIntersection = 0;
    }

    // intersection of the right part
    if (((fL + fW >= sL &&
          ((fT > sT && fT < sT + sH) || (fT + fH > sT && fT + fH < sT + sH) ||
           (fT == sT && fT + fH == sT + sH)))) ||
        ((sL <= fL + fW &&
          ((sT > fT && sT < fT + fH) || (sT + sH > fT && sT + sH < fT + fH) ||
           (sL == fL && sL + sW == fL + fW)))))
    {
        if (fL < sL)
            horizontalIntersection = 1;
    }

    // intersection of the top part
    if (((fT <= sT + sH &&
          ((fL > sL && fL < sL + sW) || (fL + fW > sL && fL + fW < sL + sW) ||
           (fL == sL && fL + fW == sL + sW)))) ||
        ((sT + sH >= fT &&
          ((sL > fL && sL < fL + fW) || (sL + sW > fL && sL + sW < fL + fW) ||
           (sL == fL && sL + sW == fL + fW)))))
    {
        if (fT + fH > sT + sH)
        {
            verticalIntersection = 2;
        }
    }
    // intersection of the down part
    if (((fT + fH >= sT &&
          ((fL > sL && fL < sL + sW) || (fL + fW > sL && fL + fW < sL + sW) ||
           (fL == sL && fL + fW == sL + sW)))) ||
        ((sT <= fT + fH &&
          ((sL > fL && sL < fL + fW) || (sL + sW > fL && sL + sW < fL + fW) ||
           (sL == fL && sL + sW == fL + fW)))))
    {
        if (fT < sT)
        {
            verticalIntersection = 3;
        }
    }
    std::pair<int, int> b;
    b.first = horizontalIntersection;
    b.second = verticalIntersection;
    return b;
}