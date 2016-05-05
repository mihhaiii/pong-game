#include "PlayerPaddle.h"
#include <iostream>
#include "Game.h"
PlayerPaddle::PlayerPaddle()
: _velocity(0), _maxVelocity(600.0f)
{
    //ctor
    Load("images/paddle.png");
//    assert(IsLoaded());

    GetSprite().setOrigin(GetSprite().getLocalBounds().width/2, GetSprite().getLocalBounds().height/2);
//    GetSprite().setOrigin(GetSprite().getLocalBounds().width/2, GetSprite().getLocalBounds().height/2);
    numberOfPaddles++;
    paddleID = numberOfPaddles;
}

PlayerPaddle::~PlayerPaddle()
{
    //dtor
}


void PlayerPaddle::Draw(sf::RenderWindow& rw)
{
    VisibleGameObject::Draw(rw);
}

float PlayerPaddle::GetVelocity() const  {
    return _velocity;
}

void PlayerPaddle::Update(float elapsedTime, GameObjectManager*)
{
  /*  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        _velocity -= 3.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _velocity += 3.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        _velocity=0;
    }

    if (_velocity > _maxVelocity) _velocity=_maxVelocity;
    if (_velocity < -_maxVelocity) _velocity=-_maxVelocity;

    sf::Vector2f pos = this->GetPosition();
    if (pos.x < GetSprite().getLocalBounds().width/2 || pos.x > Game::SCREEN_WIDTH - GetSprite().getGlobalBounds().width/2)
        _velocity = -_velocity;

    GetSprite().move(_velocity * elapsedTime, 0);*/
           float moveX=0;
    if (paddleID == 1) {


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                moveX -= 0.3f;
                _velocity = -1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                moveX += 0.3f;
                  _velocity = 1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                moveX=0;
                  _velocity = 0;
            }

    } else if (paddleID == 2) {



            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                moveX -= 0.3f;
                _velocity = -1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                moveX += 0.3f;
                  _velocity = 1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                moveX=0;
                  _velocity = 0;
            }

    }


     sf::Vector2f pos = this->GetPosition();
    if (pos.x < GetSprite().getLocalBounds().width/2 || pos.x > Game::SCREEN_WIDTH - GetSprite().getGlobalBounds().width/2)
        _velocity = -_velocity, moveX *= -1;


            GetSprite().move(moveX, 0);

}

 int PlayerPaddle:: numberOfPaddles = 0;


