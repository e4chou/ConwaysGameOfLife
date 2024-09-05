#include "tick.h"
#include "cell.h"

Tick::Tick() : time{0} {}
Tick::Tick(int time) : time{time} {
    for (int i = 0; i < time; ++i) {
        notifyObservers();
    }
}

int Tick::getTick() const { return time; } 

void Tick::notifyObservers() const {
    for (auto o:observers) {
        Cell* c = dynamic_cast<Cell*>(o);
        c->setLiveNeighbors(0);
    }
    for (auto o:observers) {
        Cell* c = dynamic_cast<Cell*>(o);
        c->notify();
    }
    for (auto o:observers) {
        Cell* c = dynamic_cast<Cell*>(o);
        c->populate();
    }
    ++time;
}
