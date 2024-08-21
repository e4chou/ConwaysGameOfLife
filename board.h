#ifndef BOARD_H
#define BOARD_H
#include <vector>

#include "cell.h"
#include "subject.h"
#include "tick.h"

class Board : public Subject {
    std::vector<Cell*> cells;
    int length, height;
	Tick t;
    void plusLiveNeighbor(int x, int y);
    friend class Cell;

   public:
    Board(int length, int height, std::vector<bool> seed);
	~Board();
	
	bool getCellStatus(int x, int y);
	bool getCellChanged(int x, int y);
	int getBoardLength() const;
	int getBoardHeight() const;
	void printBoard() const;
	int getPopulation() const;
	int getTick() const;
	void tick();
};

#endif