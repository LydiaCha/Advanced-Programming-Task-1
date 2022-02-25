#include <iostream>
#include "DrawableGameComponent.h"

DrawableGameComponent::DrawableGameComponent(int x, int y) : GameComponent()
{
    this->x = x;
    this->y = y;
    direction = Up;
}

void DrawableGameComponent::ChangeDirection()
{
    srand(time(nullptr));
    int randomNumber = (rand() % 4) + 1;
    while (randomNumber == direction)
        randomNumber = (rand() % 4) + 1;
    direction = static_cast<Direction>(randomNumber);
};

void DrawableGameComponent::Draw()
{
    cout << currentDirection << " : "
         << "X : " << x << ", Y : " << y
         << endl;
}

void DrawableGameComponent::CurrentPosition()
{
    switch (direction)
    {
        case Left:
            x--;
            if (x < 0)
            {
                x = 0;
            }
            currentDirection = "Left";
            break;
        case Right:
            x++;
            if (x >
                SCREEN_WIDTH)
            {
                x = SCREEN_WIDTH;
            }
            currentDirection = "Right";
            break;
        case Up:
            y++;
            if (y >
                SCREEN_HEIGHT)
            {
                y = SCREEN_HEIGHT;
            }
            currentDirection = "Up";
            break;
        case Down:
            y--;
            if (y < 0)
            {
                y = 0;
            }
            currentDirection = "Down";
            break;
        default:
            break;
    }
}

void DrawableGameComponent::Update(const tm *eventTime)
{
    GameComponent::Update(eventTime);
    CurrentPosition();
    Draw();
    ChangeDirection();
}