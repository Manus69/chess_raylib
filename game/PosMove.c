#include "_private.h"

CLR Pos_turn(const Pos * pos)
{
    return pos->turn;
}

static bool _check_turn(const Pos * pos, Move mv)
{
    return Pos_turn(pos) == Move_clr_from(mv);
}

Rslt_Pos Pos_try_move(const Pos * pos, Move mv)
{
    char piece;

    piece = Pos_at(pos, mv.from);

    if (is_empty(piece))        return Rslt_Pos_fucked();
    if (! _check_turn(pos, mv)) return Rslt_Pos_fucked();
}