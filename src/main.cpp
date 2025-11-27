#include <iostream>
#include <ratio>
#include <chrono>

struct configInfo {
        int clockTickRate; // in ticks per second. Calcuated value.
        int updateRate; // in ticks per second. default is 100.

};

int main() 
{
        using Clock = std::chrono::steady_clock;

        // config
        configInfo config;
        config.clockTickRate = Clock::period::den;
        config.updateRate = 100;

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

