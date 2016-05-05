#ifndef GAMEBALL_H
#define GAMEBALL_H

#include <iostream>
#include <string>
#include "VisibleGameObject.h"
#include "SFML/Graphics.hpp"
#include "Game.h"
#include "GameObjectManager.h"
#include "PlayerPaddle.h"
#include <cmath>
class GameBall : public VisibleGameObject
{
    public:
        GameBall();
        virtual ~GameBall();

        void Update(float,GameObjectManager*);
        int f;

        const float pi = acos(-1);

    protected:

    private:
        float _velocity;
        float _angle;
        float _elapsedTimeSinceStart;

};

#endif // GAMEBALL_H
