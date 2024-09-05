#ifndef TICK_H
#define TICK_H
#include "subject.h"

class Tick : public Subject {
    mutable int time;
   public:
    Tick();
    Tick(int time);
    ~Tick() = default;
    int getTick() const;
    virtual void notifyObservers() const override;
};

#endif
