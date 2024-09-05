#include "text.h"
#include <iostream>
using namespace std;

Text::Text(Board &b) : b{b} {
    b.attach(this);
}

void Text::notify() {
    for (int i = 0; i < b.getBoardHeight(); ++i) { 
        for (int j = 0; j < b.getBoardLength(); ++j) {
            bool status = b.getCellStatus(j, i);
            if (status == ALIVE) {
                cout << "■";
            } else if (status == DEAD) {
                cout << "□";
            }
        }
        cout << endl;
    }
    cout << "Time: " << b.getTick() << endl;
    cout << "Population: " << b.getPopulation() << endl;
}
