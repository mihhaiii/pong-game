#include "VisibleGameObject.h"

VisibleGameObject::VisibleGameObject()
: _isLoaded(false)
{
    //ctor
}

VisibleGameObject::~VisibleGameObject()
{
    //dtor
}

void VisibleGameObject::Load(std::string filename)
{
    if (!_texture.loadFromFile(filename)) {
        std::cout << "Eroare la VisibleGameObject::Load" << std::endl;
        _filename="";
        _isLoaded = false;
    } else {
        _filename = filename;
        _isLoaded = true;
        _sprite.setTexture(_texture);
    }
}


void VisibleGameObject::Draw(sf::RenderWindow& window)
{
    if (!_isLoaded) return;
    window.draw(_sprite);
}

void VisibleGameObject::SetPosition(float x, float y)
{
        if (!_isLoaded) return;
        _sprite.setPosition(x,y);
}

void VisibleGameObject::Update(float elapsedTime, GameObjectManager* gom)
{
}

sf::Vector2f VisibleGameObject::GetPosition() const
{
    return _sprite.getPosition();
}

sf::Sprite& VisibleGameObject::GetSprite()
{
    return _sprite;
}

bool VisibleGameObject::IsLoaded() const {
    return _isLoaded;
}

float VisibleGameObject::GetWidth() const {
    return _sprite.getGlobalBounds().width;
}
float VisibleGameObject::GetHeight() const {
    return _sprite.getGlobalBounds().height;
}

sf::Rect<float> VisibleGameObject::GetBoundingRect() const {
    sf::Vector2f pos = _sprite.getPosition();
    sf::Vector2f sz;
    sz.x = GetWidth();
    sz.y = GetHeight();

    return sf::Rect<float> (
                        pos.x  - sz.x/2,
                        pos.y - sz.y/2,
                        sz.x,
                        sz.y
                            );
}
