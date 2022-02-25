#include <iostream>
#include "Game.h"
#include "GameComponent.h"
#include "DrawableGameComponent.h"

void Initialise()
{
    cout << "Initialising game" << endl;
}

void Terminate()
{
    cout << "Terminating game" << endl;
}

int main()
{
    Game game(1);

    game.SetInitialise(Initialise);

    game.SetTerminate(Terminate);

    game.Add(new GameComponent());

    game.Add(new DrawableGameComponent(0, 0));

    game.Run();
}