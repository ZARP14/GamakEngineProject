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

    auto g = horizontalSpeed * mDirection * (collision ? 1 : 0) *
             (objectHorizontalStoper ? 1 : 0) * Time::me.getTime();

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
    float g = (mDirection *
               (objectVerticalSpeed + mVerticalSpeed * (collision ? 1 : 0))) *
              Time::me.getTime();
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
    bool canD = fT < fT;

    int verticalIntersection   = 9;
    int horizontalIntersection = 9;

    // intersection of the left part
    if (((fL <= sR && (fTbetweenStSd || fDbetweenStSd || horizontalEquals)) ||
         (sR > fL && (sTbetweenFtFd || sDbetweenFtFd || horizontalEquals))) &&
        canL)
        horizontalIntersection = 0;

    // intersection of the right part
    if (((fR >= sL && (fTbetweenStSd || fDbetweenStSd || horizontalEquals)) ||
         (sL <= fR && (sTbetweenFtFd || sDbetweenFtFd || horizontalEquals))) &&
        canR)
        horizontalIntersection = 1;

    // intersection of the top part
    if (((fT <= sD && (fLbetweenSlSr || fRbetweenSlSr || verticalEquals)) ||
         (sD >= fT && (sLbetweenFlFr || sRbetweenFlFr || verticalEquals))) &&
        canT)
        verticalIntersection = 2;

    // intersection of the down part
    if (((fD >= sT && (fLbetweenSlSr || fRbetweenSlSr || verticalEquals)) ||
         (sT <= fD && (sLbetweenFlFr || sRbetweenFlFr || verticalEquals))) &&
        canD)
        verticalIntersection = 3;

    std::pair<int, int> b;
    b.first  = horizontalIntersection;
    b.second = verticalIntersection;
    return b;
}