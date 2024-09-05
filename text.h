#ifndef TEXT_H
#define TEXT_H
#include "board.h"

class Text : public Observer {
    Board &b;

   public:
    ~Text() = default;
    Text(Board &b);
    void notify() override;
};

#endif
