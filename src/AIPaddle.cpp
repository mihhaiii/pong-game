#include "AIPaddle.h"
#include <iostream>
#include "Game.h"
#include "GameBall.h"

AIPaddle::AIPaddle()
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

AIPaddle::~AIPaddle()
{
    //dtor
}


void AIPaddle::Draw(sf::RenderWindow& rw)
{
    VisibleGameObject::Draw(rw);
}

float AIPaddle::GetVelocity() const  {
    return _velocity;
}

void AIPaddle::Update(float elapsedTime, GameObjectManager* gom)
{

    GameBall* ball = dynamic_cast<GameBall*>(gom->Get("Ball"));

    if (ball->GetPosition().x < this->GetPosition().x)  _velocity -= 3.0f;
        else  _velocity += 3.0f;

    if (_velocity > _maxVelocity) _velocity=_maxVelocity;
    if (_velocity < -_maxVelocity) _velocity=-_maxVelocity;

    sf::Vector2f pos = this->GetPosition();
    if (pos.x < GetSprite().getLocalBounds().width/2 || pos.x > Game::SCREEN_WIDTH - GetSprite().getGlobalBounds().width/2)
        _velocity = -_velocity;

    GetSprite().move(_velocity * elapsedTime, 0);


}

 int AIPaddle:: numberOfPaddles = 0;


