#include "GameBall.h"
#include <time.h>
#include <cmath>
#include <iostream>
#include "AIPaddle.h"
GameBall::GameBall()
 :_velocity(240.0f),
  _elapsedTimeSinceStart(0.0f)
{
    //ctor
    Load("images/ball.png");
    GetSprite().setOrigin(15,15);

    srand (time(NULL));
    int r = rand() % 360;
    _angle=(float)r;

    f=0;
}


GameBall::~GameBall()
{
    //dtor
}

void GameBall::Update(float elapsedTime, GameObjectManager* gom) {
        _elapsedTimeSinceStart += elapsedTime;
        // delay game from starting until 3 seconds have passed
        if (_elapsedTimeSinceStart < 3.0f)
            return;

        float moveAmount = _velocity * elapsedTime;

        float moveX = moveAmount * cos(_angle * pi / 180);
        float moveY = -moveAmount * sin(_angle * pi / 180);

        // coliziuni cu partea dreapta si stanga a ecranului
        if (GetPosition().x + GetWidth()/2 + moveX >= Game::SCREEN_WIDTH
            || GetPosition().x - GetWidth()/2 + moveX <= 0)
             {
                if (_angle <= 180) _angle = 180 - _angle;
                    else _angle = 540 - _angle;
                _velocity += 30.0f;
            }

        // coliziuni cu partea de sus a ecranului
        if (GetPosition().y - GetHeight()/2 + moveY <= 0) {
            _angle = 360 - _angle;
                            _velocity += 5.0f;

        }
        if (GetPosition().y + GetHeight()/2 + moveY >= Game::SCREEN_HEIGHT)
        {
         /*   GetSprite().setPosition(Game::SCREEN_WIDTH/2,Game::SCREEN_HEIGHT/2);
            srand(time(NULL));
            int r=rand() % 360;
            _angle = (float)r;
            _elapsedTimeSinceStart = 0;
            return;*/
            _angle = 360 - _angle;
                            _velocity += 5.0f;

        }

        PlayerPaddle* p1  = dynamic_cast<PlayerPaddle*> (gom->Get("Player1"));
        if (p1 != NULL)
        {
                sf::Rect<float> p1bb= p1->GetBoundingRect();
                if (p1bb.intersects(GetBoundingRect()))
                {
                    _angle = 360 - _angle;
                    _velocity += 5.0f;

                    if (GetBoundingRect().top + GetBoundingRect().height >= p1bb.top)
                    {
                        SetPosition(GetPosition().x,p1bb.top - GetHeight()/2-1);
                    }
                    // Now add "English" based on the players velocity.
                      float playerVelocity = p1->GetVelocity();

                      if(playerVelocity < 0)
                      {
                        // moving left
                        _angle -= 20.0f;
                        if(_angle < 0 ) _angle = 360.0f - _angle;
                      }
                      else if(playerVelocity > 0)
                      {
                        _angle += 20.0f;
                        if(_angle > 360.0f) _angle = _angle - 360.0f;
                      }
                }
        }

        AIPaddle* p2  = dynamic_cast<AIPaddle*> (gom->Get("Comp"));
        if (p2 != NULL)
        {
                sf::Rect<float> p2bb= p2->GetBoundingRect();
                if (p2bb.intersects(GetBoundingRect()))
                {
                    _angle = 360 - _angle;
                    _velocity += 5.0f;

                    if (GetBoundingRect().top <= p2bb.top + p2bb.height)
                    {
                        SetPosition(GetPosition().x,p2bb.top + p2bb.height + GetHeight()/2+1);
                    }
                    // Now add "English" based on the players velocity.
                      float playerVelocity = p2->GetVelocity();

                      if(playerVelocity < 0)
                      {
                        // moving left
                        _angle -= 20.0f;
                        if(_angle < 0 ) _angle = 360.0f - _angle;
                      }
                      else if(playerVelocity > 0)
                      {
                        _angle += 20.0f;
                        if(_angle > 360.0f) _angle = _angle - 360.0f;
                      }
                }
        }


      if (f==0) f=1,  std::cout << _angle;
        moveX = moveAmount * cos(_angle * pi / 180);
        moveY = -moveAmount * sin(_angle * pi / 180);

        GetSprite().move(moveX,moveY);

}

