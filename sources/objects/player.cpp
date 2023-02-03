#include "objects/player.hpp"

Player::Player(b2World mWorld, std::string str, int width, int height, int left, int right)
{

    objectRectangle.width  = width;
    objectRectangle.height = height;
    objectRectangle.left   = left;
    objectRectangle.top    = right;
    objectTexture.loadFromFile(str);
    objectSprite.setTexture(objectTexture);
    objectSprite.setPosition(500, 0);

    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 4.0f);
    body = mWorld.CreateBody(&bodyDef);
    dynamicBox.SetAsBox(1.0f, 1.0f);
    fixtureDef.shape    = &dynamicBox;
    fixtureDef.density  = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);
}
