#pragma once

/* Actor base class meant for inheritance*/
// TODO: Should be abstract ? = 0
class Actor
{
public:
    Actor() {};
    virtual ~Actor() {};

    virtual void jump(float deltaTime); // TODO: Not used anywhere
    virtual void move(float tX, float tY, float deltaTime);

    // player commands
    virtual void moveLeft(float deltaTime);
    virtual void moveRight(float deltaTime);
    virtual void moveUp(float deltaTime);
    virtual void moveDown(float deltaTime);

    // enemy commands
    virtual void chase();
    virtual void roam();

    // Getters/setters
    float getXPos() const { return m_xPos;};
    float getYPos() const { return m_yPos;};

    void setXPos(float val) { m_xPos = val;};
    void setYPos(float val) { m_yPos = val;};

private:
    float m_xPos;
    float m_yPos;
};
