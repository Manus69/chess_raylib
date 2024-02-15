#include "_private.h"

char * Brd_get(const Brd * brd, int idx)
{
    return (char *) & brd->cstr[idx];
}

char * Brd_get_rc(const Brd * brd, int row, int col)
{
    return Brd_get(brd, transform_rc_idx(row, col));
}

bool Brd_square_empty(const Brd * brd, int idx)
{
    return * Brd_get(brd, idx) == BRD_ES;
}

bool Brd_square_empty_rc(const Brd * brd, int row, int col)
{
    return Brd_square_empty(brd, transform_rc_idx(row, col));
}

CLR Brd_clr_at(const Brd * brd, int idx)
{
    return CLR_get(* Brd_get(brd, idx));
}

void Brd_set(Brd * brd, int idx, char val)
{
    * Brd_get(brd, idx) = val;
}

void Brd_set_rc(Brd * brd, int row, int col, char val)
{
    Brd_set(brd, transform_rc_idx(row, col), val);
}

void Brd_move_rc(Brd * brd, int from, int to)
{
    char val;

    val = * Brd_get(brd, from);
    Brd_set(brd, to, val);
    Brd_set(brd, from, BRD_ES);
}

void Brd_move(Brd * brd, Move mv)
{
    Brd_move_rc(brd, mv.from, mv.to);
}

Brd Brd_from_cstr(const char * cstr)
{
    Brd brd;

    memcpy(brd.cstr, cstr, BRD_NSQUARES);
    return brd;
}
