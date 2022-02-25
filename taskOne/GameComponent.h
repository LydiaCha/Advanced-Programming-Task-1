#pragma once

#include <ctime>

using namespace std;

class GameComponent
{
public:
    GameComponent();

    virtual void Update(const tm *time);

private:
    static int instances;

protected:
    int id;
};