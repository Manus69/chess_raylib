#include "Game.h"

Pos Pos_new_default(void)
{
    return (Pos)
    {
        .brd = Brd_new_default(),
    };
}

