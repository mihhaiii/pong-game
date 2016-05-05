#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>
class SplashScreen
{
    public:
        SplashScreen(std::string);
        virtual ~SplashScreen();
        void Show(sf::RenderWindow&);

    protected:

    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
        std::string _filename;
};

#endif // SPLASHSCREEN_H
