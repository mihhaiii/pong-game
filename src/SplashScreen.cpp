#include "SplashScreen.h"

SplashScreen::SplashScreen(std::string filename = "images/splash.png")
{
    this->_filename = filename;
    if (!_texture.loadFromFile(filename)) {
        std::cout << "Eroare la incarcarea SplashScreen-ului din " << _filename << std::endl;
    }
    _sprite.setTexture(_texture);
    //ctor
}

SplashScreen::~SplashScreen()
{
    //dtor
}

void SplashScreen::Show(sf::RenderWindow& window)
{
    window.clear();
    window.draw(_sprite);
    window.display();

    sf::Event event;
    while (1)
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed)
                return; // iese din functie
        }
    }
}
