#include "board.h"
#include <iostream>

using namespace std;

Board::Board(int length, int height, std::vector<bool> seed)
    : length{length}, height{height}, t{Tick()} {
    // instantiate Cells
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < length; ++j) {
            cells.emplace_back(j, i, seed.at((i * length) + j), this);
        }
    }
    // attach cells to Tick t and its Cell neighbors post-instantiation, since vector 
    // is reallocating size as elements are added
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < length; ++j) {
            t.attach(&cells.at((i * length) + j));  // attach to tick
            for (int m = -1; m < 2; ++m) {          // attach to neighbors
                for (int n = -1; n < 2; ++n) {
                    int x = j + m;
                    int y = i + n;
                    if (x < 0) x = length + x;      // wrap around board if on board edge
                    if (y < 0) y = height + y;
                    if (x >= length) x = x - length;
                    if (y >= height) y = y - height;
                    if (!((m == 0) && (n == 0))) {  // exclude itself
                        cells.at((i*length) + j).attach(&cells.at((y*length) + x));
                    }
                }
            }
        }
    }
}

bool Board::getCellStatus(int x, int y) const {
    return (cells.at((y * length) + x)).getStatus();
}
bool Board::getCellChanged(int x, int y) const {
        return (cells.at((y * length) + x)).getChanged();
}

int Board::getBoardHeight() const { return height; }
int Board::getBoardLength() const { return length; }
void Board::printBoard() const { notifyObservers(); }
int Board::getTick() const { return t.getTick(); }

int Board::getPopulation() const {
    int pop = 0;
    for (auto cell:cells) {
        if (cell.getStatus() == ALIVE) {
            ++pop;
        }
    }
    return pop;
}

void Board::tick() {
    t.notifyObservers();
    notifyObservers();
}
