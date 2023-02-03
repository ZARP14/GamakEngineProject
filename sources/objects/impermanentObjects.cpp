#include "objects/impermanentObjects.hpp"

ImpermanentObjects::ImpermanentObjects()
{
    horizontalSpeed           = 0.2;
    verticalSpeed             = 5;
    objectVerticalSpeed       = 0;
    objectHorizontalDirection = 9999;
    objectVerticalStoper      = 0;
    objectHorizontalStoper    = 0;
    mGravity                  = 0;
    moving                    = 0;
    leftStop                  = false;
    rightStop                 = false;
}
