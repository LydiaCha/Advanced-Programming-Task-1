#pragma once

#include <string>
#include "GameComponent.h"

using namespace std;

class DrawableGameComponent : public GameComponent
{
public:
    enum Direction : unsigned char
    {
        Left = 1,
        Right = 2,
        Up = 3,
        Down = 4
    };
    Direction direction;

    DrawableGameComponent(int x, int y);

    const int SCREEN_HEIGHT = 20;
    const int SCREEN_WIDTH = 80;

    void Update(const tm *eventTime) override;

private:
    void ChangeDirection();

    void Draw();

    int x;
    int y;

    void CurrentPosition();

    string currentDirection;
};