#include <unistd.h>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "graphics.h"
#include "text.h"

using namespace std;

int main(int argc, char* argv[]) {
    int x, y;
    bool status;
    vector<bool> seed;
    cin >> x >> y;
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            cin >> status;
            seed.emplace_back(status);
        }
    }

    Board canvas = Board(x, y, seed);

	vector<Observer*> observers;
    observers.emplace_back(new Text(&canvas));
    if ((argc > 1) && (string(argv[1]) == "-graphics")) {
        observers.emplace_back(new Graphics(&canvas));
    }

    char cmd;
    while (cin >> cmd) {
        if (cmd == 'p') {
            canvas.printBoard();
        }
        if (cmd == 't') {
            string s;
            getline(cin, s);
            istringstream iss{s};
            int n = 1;
            iss >> n;
            for (int i = 0; i < n; ++i) {
                canvas.tick();
				sleep(1);
            }
        }
        if (cmd == 's') {
            // dangerous, only stops on CTRL + C
            while (true) {
                canvas.tick();
                sleep(1);
            }
        }
    }

	for (auto obs:observers) {
		delete obs;
	}
}
