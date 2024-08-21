#ifndef CELL_SUBJECT_H
#define CELL_SUBJECT_H
#include <vector>
#include "cell.h"

class CellSubject {
   protected:
    std::vector<Cell*> observers;
   public:
    virtual ~CellSubject() = 0;
    virtual void notifyObservers() const;
	void attach(Cell* c);
	void detach(Cell* c);
};

#endif
