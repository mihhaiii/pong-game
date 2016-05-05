#ifndef VISIBLEGAMEOBJECT_H
#define VISIBLEGAMEOBJECT_H
#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "GameObjectManager.h"
class GameObjectManager;
class VisibleGameObject
{
    public:
        VisibleGameObject();
        virtual ~VisibleGameObject();

        virtual void Load(std::string);
        virtual void Draw(sf::RenderWindow&);
        virtual void Update(float, GameObjectManager*);

        virtual void SetPosition(float x, float y);
        virtual  sf::Vector2f GetPosition() const;
        virtual bool IsLoaded() const;

        virtual float GetWidth() const;
        virtual float GetHeight() const;
        sf::Rect<float> GetBoundingRect() const;
    protected:
        sf::Sprite&  GetSprite();
    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
        std::string _filename;
        bool _isLoaded;
};

#endif // VISIBLEGAMEOBJECT_H
