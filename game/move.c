#include "Game.h"

brd_idx move_from(move mv)
{
    return mv >> __CHAR_BIT__;
}

brd_idx move_to(move mv)
{
    return mv & 0xFF;
}

move move_new(brd_idx from, brd_idx to)
{
    return (from << __CHAR_BIT__) | to;
}