#ifndef PLAYERPADDLE_H
#define PLAYERPADDLE_H


#include "VisibleGameObject.h"
#include "GameObjectManager.h"
class PlayerPaddle:
    public VisibleGameObject
{
    public:
        PlayerPaddle();
        virtual ~PlayerPaddle();

        void Update(float,GameObjectManager*);
        void Draw(sf::RenderWindow&);

        float GetVelocity() const;

        static  int numberOfPaddles;
        int paddleID;

    protected:

    private:
        float _velocity;
        float _maxVelocity;
};

#endif // PLAYERPADDLE_H
