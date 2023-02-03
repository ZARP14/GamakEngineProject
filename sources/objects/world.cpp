#include "world.hpp"

World::World() : gravity(0.0f, -10.0f), mB2dWorld(gravity), groundBoxRect(0, 0, 1713, 53)
{
    groundBoxDef.position.Set(0.0f, -10.0f);
    groundBox = mB2dWorld.CreateBody(&groundBoxDef);
    groundBoxShape.SetAsBox(50.0f, 10.0f);
    groundBox->CreateFixture(&groundBoxShape, 0.0f);

    groundboxTexture.loadFromFile(TEXTURES_PATH + "flor.png");
    groundBoxSprite.setTexture(groundboxTexture);
    groundBoxSprite.setPosition(0, 500);
    Gui::global.vectorInput(groundBoxSprite);
}