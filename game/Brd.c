#include "Game.h"
#include "../lib/mylib.h"
#include <string.h>

int Brd_row_col_idx(int row, int col)
{
    return row * BRD_SIZE + col;
}

int Brd_idx_row(int idx)
{
    return idx / BRD_SIZE;
}

int Brd_idx_col(int idx)
{
    return idx % BRD_SIZE;
}

square * Brd_get(const Brd * brd, int idx)
{
    return (square *) brd->board + idx;
}

square * Brd_get_row_col(const Brd * brd, int row, int col)
{
    return Brd_get(brd, Brd_row_col_idx(row, col));
}

bool Brd_white_piece(const Brd * brd, int idx)
{
    return square_is_white_piece(* Brd_get(brd, idx));
}

bool Brd_white_piece_row_col(const Brd * brd, int row, int col)
{
    return Brd_white_piece(brd, Brd_row_col_idx(row, col));
}

bool Brd_black_piece(const Brd * brd, int idx)
{
    return square_is_black_piece(* Brd_get(brd, idx));
}

bool Brd_black_piece_row_col(const Brd * brd, int row, int col)
{
    return Brd_black_piece(brd, Brd_row_col_idx(row, col));
}

bool Brd_empty_square(const Brd * brd, int idx)
{
    return square_no_piece(* Brd_get(brd, idx));
}

bool Brd_empty_square_row_col(const Brd * brd, int row, int col)
{
    return Brd_empty_square(brd, Brd_row_col_idx(row, col));
}

bool Brd_white_pawn(const Brd * brd, int idx)
{
    return square_white_pawn(* Brd_get(brd, idx));
}

bool Brd_white_pawn_row_col(const Brd * brd, int row, int col)
{
    return Brd_white_pawn(brd, Brd_row_col_idx(row, col));
}

bool Brd_black_pawn(const Brd * brd, int idx)
{

}

void Brd_set(Brd * brd, int idx, square val)
{
    * Brd_get(brd, idx) = val;
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