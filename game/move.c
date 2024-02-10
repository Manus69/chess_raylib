#include "Game.h"

int move_get_from(move mv)
{
    return mv >> __CHAR_BIT__;
}

int move_get_to(move mv)
{
    return mv & 0xFF;
}

move move_new(int from, int to)
{
    return (((move) from) << __CHAR_BIT__) | to;
}