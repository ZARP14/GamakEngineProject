#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <box2d/box2d.h>

#include <iomanip>

#include "objects/impermanentObjects.hpp"
#include "objects/world.hpp"

class Player : public ImpermanentObjects
{
public:
    Player(b2World mWorld, std::string str = TEXTURES_PATH + "playerTexture.png", int width = 82,
           int height = 53, int left = 0, int right = 0);

    b2Body* body;

private:
    b2BodyDef bodyDef;
    b2PolygonShape dynamicBox;
    b2FixtureDef fixtureDef;
};
#endif // !PLAYER_HPP
