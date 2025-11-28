#include "rigidBody.hpp"

RigidBody_2d::RigidBody_2d(double mass, double momentOfInertia)
{
        this->mass = mass;
        Eigen::Vector2d zeroInit(0,0);
        this->momentum = zeroInit;
        this->velocity = zeroInit;
        this->position = zeroInit;

        this->angularMomentum = 0;
        this->angularVelocity = 0;
        this->angularPosition = 0;
        this->momentOfInertia = 0;
}


Eigen::Vector2d RigidBody_2d::updatePos(std::vector<Eigen::Vector2d> forces, int updateRate)
{
        Eigen::Vector2d forceVector(0,0);
        for (Eigen::Vector2d force : forces)
        {
                forceVector += force;
        }
        this->momentum += forceVector;
        this->velocity = this->momentum / this->mass;
        this->position += velocity/updateRate;
        return this->position;
}
