#include "graphics.h"

const unsigned int PIXEL_LENGTH = 15;
const unsigned int PIXEL_HEIGHT = 15;

Graphics::~Graphics() = default;

Graphics::Graphics(Board& b)
    : b{b},
      window{Xwindow(b.getBoardLength() * PIXEL_LENGTH,
                         b.getBoardHeight() * PIXEL_HEIGHT)} {
    b.attach(this);
    draw();
}

void Graphics::draw() {
    for (int i = 0; i < b.getBoardHeight(); ++i) {
        for (int j = 0; j < b.getBoardLength(); ++j) {
            if (b.getCellChanged(j, i) == true) {
                bool status = b.getCellStatus(j, i);
                if (status == ALIVE) {
                    window.fillRectangle((j * PIXEL_LENGTH),
                                          (i * PIXEL_HEIGHT), PIXEL_LENGTH,
                                          PIXEL_HEIGHT, Xwindow::Black);
                } else if (status == DEAD) {
                    window.fillRectangle((j * PIXEL_LENGTH),
                                          (i * PIXEL_HEIGHT), PIXEL_LENGTH,
                                          PIXEL_HEIGHT, Xwindow::White);
                }
            }
        }
    }
}

void Graphics::notify() { draw(); }
