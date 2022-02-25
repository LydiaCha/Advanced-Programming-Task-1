#include <thread>
#include "Game.h"

void Game::Add(GameComponent *gameComponent)
{
    components[componentCount++] = gameComponent;
}

Game::Game(int maxComponents){};

void Game::SetInitialise(FP init) { initialise = init; }

void Game::SetTerminate(FP term) { terminate = term; }

void Game::Run()
{
    initialise();
    for (auto &component : components)
    {
        for (int j = 0; j < componentCount; j++)
        {
            auto currentTime = chrono::system_clock::now();
            auto inTimeT = chrono::system_clock::to_time_t(currentTime);
            tm *time = localtime(&inTimeT);
            components[j]->Update(time);
        }
        this_thread::sleep_for(chrono::milliseconds(TICKS_1000MS));
    }
    terminate();
}