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
        RigidBody_2d testBody(1, 1); 
        Eigen::Vector2d vec1(0,10);
        Eigen::Vector2d vec2(10,0);
        testBody.updatePos({vec1, vec2});
        return 0;
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
        
        //main loop
        auto lastTime = Clock::now().time_since_epoch().count();
        while (true) 
        {
                auto newTime = Clock::now().time_since_epoch().count();
                // do an update if enough time has passed
                if ((config.updateRate*(newTime - lastTime)/config.clockTickRate) == 1)
                {
                        std::cerr << "I did an update!\n";
                        lastTime = Clock::now().time_since_epoch().count();
                }
        }
        return 0;
}

