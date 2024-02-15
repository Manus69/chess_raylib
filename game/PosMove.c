#include "_private.h"

CLR Pos_turn(const Pos * pos)
{
    return Move_is_none(pos->last_move) ? CLR_WHITE : Move_clr(pos->last_move);
}