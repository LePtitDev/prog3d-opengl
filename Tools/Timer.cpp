#include "Timer.hpp"

uTimer::uTimer() :
    active(false), current_time(0)
{

}

uTimer::uTimer(const uTimer & t) :
    active(t.active), current_time(t.current_time), start(t.start)
{

}

void uTimer::Start() {
    this->active = true;
    this->current_time = 0.0;
    this->start = clock();
}

void uTimer::Stop() {
    this->active = false;
    this->current_time += (double)this->start / CLOCKS_PER_SEC;
}

void uTimer::Resume() {
    this->active = true;
    this->start = clock();
}

double uTimer::GetTime() const {
    if (this->active)
        return this->current_time + (double)this->start / CLOCKS_PER_SEC;
    else
        return this->current_time;
}