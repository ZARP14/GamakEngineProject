#include "objects/impermanentObjects.hpp"

ImpermanentObjects::ImpermanentObjects()
{
    horizontalSpeed           = 0.1;
    verticalSpeed             = 0.2;
    objectVerticalSpeed       = 0;
    objectVerticalDirection   = 9999;
    objectHorizontalDirection = 9999;
    objectVerticalStoper      = 1;
    objectHorizontalStoper    = 1;
    mGravity                  = 0;
}

void
ImpermanentObjects::moveChanger(int direction, bool typeOfMoveChanger, bool stoper)
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
    bool stop      = 1;

    float mDirection = 0;
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

    double g = 0;
    if (collision)
    {
        g = horizontalSpeed * mDirection * (objectHorizontalStoper ? 1 : 0) * Time::me.getTime();
    }
    else
    {
        float v = minimalMoving(objectHorizontalDirection);
        if (v > 0)
        {
            g = v * mDirection * (objectHorizontalStoper ? 1 : 0);
        }
        else
        {
            g = 0;
        }
    }

    objectSprite.move(g, 0);
}

void
ImpermanentObjects::movingVertical()
{
    bool collision       = true;
    float mVerticalSpeed = verticalSpeed;
    if (objectVerticalStoper == 0)
    {
        mVerticalSpeed = 0;
    }

    float mDirection = 0;
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

    double g = 0;
    if (collision)
    {
        g = (mDirection * (objectVerticalSpeed + mVerticalSpeed * (collision ? 1 : 0))) *
            Time::me.getTime();
    }
    else
    {
        float v = minimalMoving(objectVerticalDirection);
        if (v > 0)
        {
            g = mDirection * v;
        }
        else
        {
            g = 0;
        }
    }

    objectSprite.move(0, g);
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
                if (collisionIntersection(*Gui::global.SpriteVector[i]).first == int(side::left))
                    return true;
                break;

            case int(side::right):
                if (collisionIntersection(*Gui::global.SpriteVector[i]).first == int(side::right))
                    return true;
                break;

            case int(side::top):
                if (collisionIntersection(*Gui::global.SpriteVector[i]).second == int(side::top))
                    return true;
                break;

            case int(side::down):
                if (collisionIntersection(*Gui::global.SpriteVector[i]).second == int(side::down))
                    return true;
                break;
            default:
                break;
        }
    }
    return false;
}

float
ImpermanentObjects::minimalMoving(int side)
{
    float sL = mSprite.getGlobalBounds().left;
    float sT = mSprite.getGlobalBounds().top;
    float sH = mSprite.getGlobalBounds().height;
    float sW = mSprite.getGlobalBounds().width;
    float sD = sT + sH;
    float sR = sL + sW;

    float fL = objectSprite.getGlobalBounds().left;
    float fT = objectSprite.getGlobalBounds().top;
    float fH = objectSprite.getGlobalBounds().height;
    float fW = objectSprite.getGlobalBounds().width;
    float fD = fT + fH;
    float fR = fL + fW;

    float horizontalDistance = 0;
    float verticalDistance   = 0;

    switch (side)
    {
        case 0:
            if (fL - sR > 0) horizontalDistance = fL - sR;
            break;
        case 1:
            if (sL - fR > 0) horizontalDistance = sL - fR;
            break;
        case 2:
            if (fT - sD > 0) verticalDistance = fT - sD;
            break;
        case 3:
            if (sT - fD > 0) verticalDistance = sT - fD;
            break;
    }

    if (side == 0 || side == 1)
    {
        return horizontalDistance;
    }
    else
    {
        return verticalDistance;
    }
}

std::pair<int, int>
ImpermanentObjects::collisionIntersection(sf::Sprite s)
{

    float sL = s.getGlobalBounds().left;
    float sT = s.getGlobalBounds().top;
    float sH = s.getGlobalBounds().height;
    float sW = s.getGlobalBounds().width;
    float sD = sT + sH;
    float sR = sL + sW;

    float fL = objectSprite.getGlobalBounds().left;
    float fT = objectSprite.getGlobalBounds().top;
    float fH = objectSprite.getGlobalBounds().height;
    float fW = objectSprite.getGlobalBounds().width;
    float fD = fT + fH;
    float fR = fL + fW;

    bool fTbetweenStSd = fT > sT && fT < sD;
    bool fDbetweenStSd = fD > sT && fD < sD;
    bool sTbetweenFtFd = sT > fT && sT < fD;
    bool sDbetweenFtFd = sD > fT && sD < fD;

    bool fLbetweenSlSr = fL > sL && fL < sR;
    bool fRbetweenSlSr = fR > sL && fR < sR;
    bool sLbetweenFlFr = sL > fL && sL < fR;
    bool sRbetweenFlFr = sR > fL && sR < fR;

    bool horizontalEquals = sT == fT && sD == fD;
    bool verticalEquals   = sL == fL && sR == fR;

    bool canL = fR > sR;
    bool canR = fL < sL;
    bool canT = fD > sD;
    bool canD = fT < sT;

    int verticalIntersection   = 9;
    int horizontalIntersection = 9;

    float mHorizontalSpeed = horizontalSpeed * Time::me.getTime();
    float mVerticalSpeed   = (verticalSpeed + objectVerticalSpeed) * Time::me.getTime();

    // intersection of the left part
    if (((fL - mHorizontalSpeed <= sR && (fTbetweenStSd || fDbetweenStSd || horizontalEquals)) ||
         (sR > fL + mHorizontalSpeed && (sTbetweenFtFd || sDbetweenFtFd || horizontalEquals))) &&
        canL)
        horizontalIntersection = 0;

    // intersection of the right part
    if (((fR + mHorizontalSpeed >= sL && (fTbetweenStSd || fDbetweenStSd || horizontalEquals)) ||
         (sL <= fR + mHorizontalSpeed && (sTbetweenFtFd || sDbetweenFtFd || horizontalEquals))) &&
        canR)
        horizontalIntersection = 1;

    // intersection of the top part
    if (((fT - mVerticalSpeed <= sD && (fLbetweenSlSr || fRbetweenSlSr || verticalEquals)) ||
         (sD >= fT + mVerticalSpeed && (sLbetweenFlFr || sRbetweenFlFr || verticalEquals))) &&
        canT)
        verticalIntersection = 2;

    // intersection of the down part
    if (((fD + mVerticalSpeed >= sT && (fLbetweenSlSr || fRbetweenSlSr || verticalEquals)) ||
         (sT <= fD + mVerticalSpeed && (sLbetweenFlFr || sRbetweenFlFr || verticalEquals))) &&
        canD)
        verticalIntersection = 3;

    std::pair<int, int> b;
    b.first  = horizontalIntersection;
    b.second = verticalIntersection;
    mSprite  = s;
    return b;
}