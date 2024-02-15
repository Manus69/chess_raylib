#include "_private.h"

Move Move_new(int from, int to)
{
    return (Move) {from, to};
}

Move Move_none(void)
{
    return Move_new(NO_IDX, NO_IDX);
}

bool Move_is_none(Move mv)
{
    return mv.from == NO_IDX;
}

CLR Move_clr(Move mv)
{
    return CLR_get(mv.to);
}