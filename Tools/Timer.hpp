#ifndef PROG3D_MAIN_HPP
#include "../main.hpp"

#else

#ifndef PROG3D_TIMER_HPP
#define PROG3D_TIMER_HPP

class uTimer {

    bool active;
    double current_time;
    std::chrono::steady_clock::time_point start;

public:

    uTimer();
    uTimer(const uTimer&);

    void Start();
    void Stop();
    void Resume();

    double GetTime() const;

};

#endif //PROG3D_TIMER_HPP

#endif