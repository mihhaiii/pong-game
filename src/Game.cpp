#include "Game.h"
Game::Game()
{
    //ctor
    _gameState = Uninitialized;
}

Game::~Game()
{
    //dtor
}

void Game::Start()
{
    if (_gameState != Uninitialized)
        return;

    _mainWindow.create(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,32),"BananaGame");
    _gameState = ShowingSplash;


    PlayerPaddle* pl1 = new PlayerPaddle();
    pl1->SetPosition(SCREEN_WIDTH/2,530);
     PlayerPaddle* pl2 = new PlayerPaddle();
    pl2->SetPosition(SCREEN_WIDTH/2,50);

    AIPaddle* comp = new  AIPaddle();
    comp->SetPosition(SCREEN_WIDTH/2,50);


    GameBall* ball = new GameBall();
    ball->SetPosition(SCREEN_WIDTH/2,SCREEN_HEIGHT/2);

    _gameObjectManager.Add("Player1",pl1);
 //  _gameObjectManager.Add("Player2",pl2);
    _gameObjectManager.Add("Comp",comp);
    _gameObjectManager.Add("Ball",ball);

    while (!IsExiting()) {
        GameLoop();
    }
    _mainWindow.close();
}
bool Game::IsExiting() {
    if (_gameState == Exiting) return true;
    return false;
}




void Game::ShowSplash() {

    SplashScreen ss("images/splash.png");
    ss.Show(_mainWindow);

    _gameState = ShowingMenu;
}
void Game::ShowMenu() {
    MainMenu mm("images/menu.png");
    MainMenu::MenuResult mr = mm.Show(_mainWindow);

    switch (mr)
    {
    case MainMenu::Play:
        _gameState = Playing;
        break;
    case MainMenu::Exit:
        _gameState = ShowingSplash;
        break;
    case MainMenu::CloseGame:
        _gameState = Exiting;
    }
}







void Game::GameLoop() {

    switch(_gameState)
    {
    case ShowingSplash:
        ShowSplash();
        break;
    case ShowingMenu:
        ShowMenu();
        break;
    case Playing:
        _mainWindow.clear(sf::Color::Black);

        _gameObjectManager.UpdateAll();
        _gameObjectManager.DrawAll(_mainWindow);
        _mainWindow.display();

        sf::Event gameEvent;

        while (_mainWindow.pollEvent(gameEvent))
        {
            switch (gameEvent.type)
            {
            case sf::Event::KeyPressed:
                if (gameEvent.key.code == sf::Keyboard::Escape) _gameState = ShowingMenu;
            break;
            case sf::Event::Closed:
            _gameState = Exiting;
            break;
            break;
            }
        }

        break;
    }

}

