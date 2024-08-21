#include "cell_subject.h"
#include <algorithm>

CellSubject::~CellSubject() {}

void CellSubject::notifyObservers() const {
	for (auto ob : observers) {
		ob->notify();
	}
}

void CellSubject::attach(Cell* c) { observers.emplace_back(c); }

// 2 ways to write detach:
// 1. manually
void CellSubject::detach(Cell* o) { 
	for (std::vector<Cell*>::iterator it = observers.begin(); it != observers.end(); ++it) {
		if (*it == o) {
			observers.erase(it);
			break;
		}
	}
}

// 2. using stl alogorithm
// void Subject::detach(Cell* c) {
// 	auto o_location = find(observers.begin(), observers.end(), c);
// 	observers.erase(o_location);
// }
