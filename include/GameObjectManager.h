#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H

#include <map>
#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "VisibleGameObject.h"
class VisibleGameObject;
class GameObjectManager
{
    public:
        GameObjectManager();
        virtual ~GameObjectManager();

        void Add(std::string,VisibleGameObject*);
        void Remove(std::string);
        int GetObjectCount();
        VisibleGameObject* Get(std::string);

        void DrawAll(sf::RenderWindow& window);
        void UpdateAll();

    protected:

    private:
        sf::Clock clock;

        std::map<std::string,VisibleGameObject*> _gameObjects;
};

#endif // GAMEOBJECTMANAGER_H
