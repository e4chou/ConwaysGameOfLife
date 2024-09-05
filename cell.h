#ifndef CELL_H
#define CELL_H
#include "observer.h"

extern const bool ALIVE;
extern const bool DEAD;

class Board;

class Cell : public Observer {
    int x, y, live_neighbors;
    bool status, changed;	// has the cell changed status last tick?
    Board* b;

   public:
    Cell(int x, int y, bool status, Board* b);
    ~Cell();

    int getX() const;
    int getY() const;
    bool getStatus() const;
    bool getChanged() const;
    void setLiveNeighbors(int x);
    void plusLiveNeighbor();

    virtual void notify() override;
    virtual void populate();  // become alive/dead depending on # of alive neighbors
};

#endif
