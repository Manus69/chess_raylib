#include "Game.h"
#include "../lib/mylib.h"
#include <string.h>

int Brd_row_col_idx(int row, int col)
{
    return row * BRD_SIZE + col;
}

int Brd_idx_shift(int idx, int n_rows, int n_cols)
{
    if (Brd_idx_col(idx) + n_cols < 0) return NO_IDX;

    return idx + n_rows * BRD_SIZE + n_cols;
}

bool Brd_idx_valid(int idx)
{
    return idx >= 0 && idx < BRD_NSQUARES;
}

int Brd_idx_row(int idx)
{
    return idx / BRD_SIZE;
}

int Brd_idx_col(int idx)
{
    return idx % BRD_SIZE;
}

bool Brd_last_row(int row)
{
    return row == BRD_SIZE - 1;
}

bool Brd_row_margin2(int row)
{
    return row >= BRD_SIZE - 2;
}

bool Brd_last_col(int col)
{
    return col == BRD_SIZE - 1;
}

bool Brd_col_margin2(int col)
{
    return col >= BRD_SIZE - 2;
}

bool Brd_row_col_valid(int row, int col)
{
    return row >= 0 && row < BRD_SIZE && col >= 0 && col < BRD_SIZE;
}

square * Brd_get(const Brd * brd, int idx)
{
    return (square *) brd->board + idx;
}

square * Brd_get_row_col(const Brd * brd, int row, int col)
{
    return Brd_get(brd, Brd_row_col_idx(row, col));
}

void Brd_set(Brd * brd, int idx, square val)
{
    * Brd_get(brd, idx) = val;
}

void Brd_set_row_col(Brd * brd, int row, int col, square val)
{
    Brd_set(brd, Brd_row_col_idx(row, col), val);
}

void Brd_move_idx(Brd * brd, int from, int to)
{
    Brd_set(brd, to, * Brd_get(brd, from));
    Brd_set(brd, from, BRD_ES);
}

void Brd_move(Brd * brd, move mv)
{
    Brd_move_idx(brd, move_get_from(mv), move_get_to(mv));
}

Brd Brd_new_empty(void)
{
    Brd brd;

    memset(brd.board, BRD_ES, BRD_NSQUARES);
    return brd;
}

Brd Brd_from_cstr(const char * cstr)
{
    Brd brd;

    memcpy(brd.board, cstr, BRD_NSQUARES);
    return brd;
}

Brd Brd_new_default(void)
{
    return Brd_from_cstr(BRD_DFLT);
}

Brd Brd_copy(const Brd * brd)
{
    return Brd_from_cstr(brd->board);
}

Brd Brd_new_after_move(const Brd * brd, move mv)
{
    Brd new;

    new = Brd_copy(brd);
    Brd_move(& new, mv);

    return new;
}