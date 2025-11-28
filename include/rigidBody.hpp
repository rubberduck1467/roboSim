#ifndef RIGID_BODY_HPP
#define RIGID_BODY_HPP

#include <vector>
#include <iostream>
#include "Eigen/Dense"

class RigidBody_2d {
        public:
                double mass;

                Eigen::Vector2d momentum;
                Eigen::Vector2d velocity;
                Eigen::Vector2d position;

                //anti-clockwise is postive movement
                double angularMomentum;
                double angularVelocity;
                // 0 is dead right
                double angularPositon;
                double momentOfInertia;

                RigidBody_2d(double mass, double momentOfInertia);

                Eigen::Vector2d updatePos(std::vector<Eigen::Vector2d> forces, int updateRate);
};

#endif //RIGID_BODY_HPP
