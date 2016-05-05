#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include <string>
#include <list>
#include "SFML/Graphics.hpp"

class MainMenu
{
    public:
        MainMenu(std::string);
        virtual ~MainMenu();

        enum MenuResult { Play, Exit, Nothing, CloseGame };
        struct MenuItem
        {
            sf::Rect<int> rect;
            MenuResult action;
        };

        MenuResult Show(sf::RenderWindow&);

    protected:

    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
        std::string _filename;
        std::list<MenuItem> _menuItems;

        MenuResult HandleClick(int,int);
};

#endif // MAINMENU_H
