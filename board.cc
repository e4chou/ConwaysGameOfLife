#include "board.h"
#include <iostream> 
using namespace std;

Board::Board(int length, int height, std::vector<bool> seed)
    : length{length}, height{height}, t{Tick()} {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < length; ++j) {
            cells.emplace_back(j, i, seed.at((i * length) + j), this);
        }
    }
    // attach cells to subject t later since cells is reallocating as elements are added
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < length; ++j) {
            t.attach(&cells.at((i * length) + j));
        }
    }
}

void Board::plusLiveNeighbor(int x, int y) {
    try {
        if (x < 0) { x = length + x; }
            if (y < 0) { y = height + y; }
            if (x >= length) { x = x - length; }
            if (y >= height) { y = y - height; }
        cells.at((y * length) + x).plusLiveNeighbor();
    } catch (...) {}
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
