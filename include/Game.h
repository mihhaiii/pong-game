#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include "SplashScreen.h"
#include "MainMenu.h"
#include "GameObjectManager.h"
#include "PlayerPaddle.h"
#include "GameBall.h"
class Game
{
    public:
        Game();
        virtual ~Game();
        void Start();

        enum GameStates { Uninitialized, Playing, Paused, ShowingSplash, ShowingMenu, Exiting };

        bool IsExiting();

        const static int SCREEN_WIDTH = 800;
        const static int SCREEN_HEIGHT = 600;
    protected:

    private:
        void GameLoop();
        void ShowSplash();
        void ShowMenu();

        GameStates _gameState;
        sf::RenderWindow _mainWindow;

        GameObjectManager _gameObjectManager;
};

#endif // GAME_H
