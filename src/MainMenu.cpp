#include "MainMenu.h"
#include <list>
MainMenu::MainMenu(std::string filename)
{
    _filename = filename;
    if (!_texture.loadFromFile(filename)) {
        std :: cout << "Eroare la incarcarea imaginii pentru meniu din " << filename << std :: endl;
    }
    _sprite.setTexture(_texture);

    MenuItem m1;
    m1.rect.left = 350;
    m1.rect.width = 100;
    m1.rect.top = 270;
    m1.rect.height = 50;
    m1.action = Play;

    MenuItem m2;
    m2.rect.left = 350;
    m2.rect.width = 100;
    m2.rect.top = 394;
    m2.rect.height = 50;
    m2.action = Exit;

    _menuItems.push_back(m1);
    _menuItems.push_back(m2);

}

MainMenu::~MainMenu()
{
    //dtor
}

MainMenu::MenuResult MainMenu::HandleClick( int x, int y)
{
     for (std::list<MenuItem> :: iterator it = _menuItems.begin(); it!=_menuItems.end(); it++)
    {
        sf::Rect<int> rect=it->rect;
        if (rect.left <= x && x <= rect.left + rect.width && rect.top <= y && y <= rect.top + rect.height)
            return it->action;
    }
    return MainMenu::Nothing;
}

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{
    window.draw(_sprite);
    window.display();

    sf::Event event;

    while (1)
    {
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                return CloseGame;
                break;
            case sf::Event::MouseButtonPressed:
                MenuResult result = HandleClick(event.mouseButton.x,event.mouseButton.y);
                if (result != Nothing) return result;
            }
        }
    }
}
