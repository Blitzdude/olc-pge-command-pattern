#pragma once
#include "Actor.h"

class Player : public Actor
{
public:
    Player();
    ~Player();

    void jump(float deltaTime)      override;
    void moveLeft(float deltaTime)  override;
    void moveRight(float deltaTime) override;
    void moveUp(float deltaTime)    override;
    void moveDown(float deltaTime)  override;
};
