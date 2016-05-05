#ifndef AIPADDLE_H
#define AIPADDLE_H


#include "VisibleGameObject.h"
#include "GameObjectManager.h"
class AIPaddle:
    public VisibleGameObject
{
    public:
        AIPaddle();
        virtual ~AIPaddle();

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
