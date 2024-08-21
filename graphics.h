#ifndef GRAPHICS_H
#define GRAPHICS_H
#include "board.h"
#include "observer.h"
#include "window.h"

class Graphics : public Observer {
    Board* b;
    Xwindow* window;
    void draw() const;

   public:
    ~Graphics();
    Graphics(Board* b);
    void notify() override;
};

#endif
