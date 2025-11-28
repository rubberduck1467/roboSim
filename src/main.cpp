#include <iostream>
#include <ratio>
#include <chrono>
#include <cstring>
#include <cstdlib>

#include "Eigen/Dense"
#include "Eigen/src/Core/Matrix.h"
#include "rigidBody.hpp"

struct configInfo {
        int clockTickRate; // in ticks per second. Calcuated value.
        int updateRate; // in ticks per second. default is 100.

};

int main(int argc, char **argv) 
{
        using Clock = std::chrono::steady_clock;

        // config
        configInfo config;

        config.clockTickRate = Clock::period::den;
        config.updateRate = 100;

        for (int iii = 0; iii < argc; iii++)
        {
                if (!strcmp("--updateRate", argv[iii]))
                {
                        config.updateRate = atoi(argv[++iii]);
                }
        }
        

        RigidBody_2d testBody(1,1);
        int testCounter = 0;
        //main loop
        auto lastTime = Clock::now().time_since_epoch().count();
        std::vector testForces ={Eigen::Vector2d(1,0)};
        testBody.updatePos(testForces, config.updateRate);

        while (true) 
        {
                auto newTime = Clock::now().time_since_epoch().count();
                // do an update if enough time has passed
                if ((config.updateRate*(newTime - lastTime)/config.clockTickRate) == 1)
                {
                        testBody.updatePos({},config.updateRate);
                        std::cout << testBody.position(0) << "," << testBody.position(1) << "\n";

                        lastTime = Clock::now().time_since_epoch().count();
                }
        }
        return 0;
}

