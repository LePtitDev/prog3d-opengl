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
    this->start = std::chrono::steady_clock::now();
}

void uTimer::Stop() {
    this->active = false;
    this->current_time += std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::steady_clock::now() - this->start).count();
}

void uTimer::Resume() {
    this->active = true;
    this->start = std::chrono::steady_clock::now();
}

double uTimer::GetTime() const {
    if (this->active)
        return this->current_time + std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::steady_clock::now() - this->start).count();
    else
        return this->current_time;
}