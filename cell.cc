#include "cell.h"

#include "board.h"

bool ALIVE = true;
bool DEAD = false;

Cell::Cell(int x, int y, bool status, Board* b)
    : x{x}, y{y}, live_neighbors{0}, status{status}, changed{true}, b{b} {}
Cell::~Cell() { b->detach(this); }

int Cell::getX() const { return x; }
int Cell::getY() const { return y; }
bool Cell::getStatus() const { return status; }
bool Cell::getChanged() const { return changed; }
void Cell::setLiveNeighbors(int x) { live_neighbors = x; }
void Cell::plusLiveNeighbor() { ++live_neighbors; }

void Cell::notify() {
    if (status == DEAD)
        return;
    else if (status == ALIVE) {
        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j < 2; ++j) {
                if (!((i == 0) && (j == 0))) {
                    b->plusLiveNeighbor(x + i, y + j);
                }
            }
        }
    }
}

// population rules, for # of live neighbors n:
// if cell is alive:
//          n < 2 : dead
//    2 <= n <= 3 : alive
// 	        n > 3 : dead
// if cell is dead:
//			n = 3 : alive
//			 else : dead
void Cell::populate() {
    if (status == ALIVE) {
        if (live_neighbors < 2 || live_neighbors > 3) {
            status = DEAD;
			changed = true;
        } else {
			changed = false;
		}
    } else if (status == DEAD) {
        if (live_neighbors == 3) {
            status = ALIVE;
			changed = true;
        } else {
			changed = false;
		}
    }
}
