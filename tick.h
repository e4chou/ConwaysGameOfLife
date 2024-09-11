#ifndef TICK_H
#define TICK_H
#include "subject.h"

class Cell;

class Tick : public Subject<Cell> {
    mutable int time;
   public:
    Tick();
    Tick(int time);
    ~Tick() = default;
    int getTick() const;
    virtual void notifyObservers() const override;
};

#endif
