#ifndef WORLD_HPP
#define WORLD_HPP

#include <SFML/Graphics.hpp>

#include "domain/definiki.hpp"

#include "box2d/box2d.h"
#include "gui/gui.hpp"

class World
{
public:
    World();
    b2World mB2dWorld;

private:
    b2BodyDef groundBoxDef;
    b2Vec2 gravity;
    b2Body* groundBox;
    b2PolygonShape groundBoxShape;

    sf::Texture groundboxTexture;
    sf::IntRect groundBoxRect;
    sf::Sprite groundBoxSprite;
};

#endif // !WORLD_HPP