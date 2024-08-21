#ifndef TICK_H
#define TICK_H
#include "cell_subject.h"

class Tick : public CellSubject {
    mutable int time;
   public:
    Tick();
	Tick(int time);
	~Tick();
	int getTick() const;
	virtual void notifyObservers() const override;
};

#endif
