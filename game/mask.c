#include "Game.h"

bfd64 mask_Brd(const Brd * brd)
{
    bfd64 msk;

    msk = 0;
    for (int k = 0; k < BRD_NSQUARES; k ++)
    {
        if (! square_no_piece(* Brd_get(brd, k))) bfd64_set(& msk, k);
    }

    return msk;
}

bfd64 mask_white(const Brd * brd)
{
    bfd64 msk;

    msk = 0;
    for (int k = 0; k < BRD_NSQUARES; k ++)
    {
        if (square_white_piece(* Brd_get(brd, k))) bfd64_set(& msk, k);
    }

    return msk;
}

bfd64 mask_black(const Brd * brd)
{
    bfd64 msk;

    msk = 0;
    for (int k = 0; k < BRD_NSQUARES; k ++)
    {
        if (square_black_piece(* Brd_get(brd, k))) bfd64_set(& msk, k);
    }

    return msk;
}

static bfd64 _mask_square(int row, int col)
{
    return Brd_row_col_valid(row, col) ? bfd64_one(Brd_row_col_idx(row, col)) : 0;
}

static bfd64 _mask_attack_wp(int row, int col)
{
    return _mask_square(row - 1, col - 1) | _mask_square(row - 1, col + 1);
}

static bfd64 _mask_attack_bp(int row, int col)
{
    return _mask_square(row + 1, col - 1) | _mask_square(row + 1, col + 1);
}

static bfd64 _mask_attack_king(int row, int col)
{
    return _mask_square(row - 1, col - 1) | _mask_square(row - 1, col) | _mask_square(row - 1, col + 1) |
            _mask_square(row, col - 1) | _mask_square(row, col + 1) |
            _mask_square(row + 1, col - 1) | _mask_square(row + 1, col) | _mask_square(row + 1, col + 1);
}

static bfd64 _mask_attack_knight(int row, int col)
{
    return _mask_square(row - 2, col - 1) | _mask_square(row - 2, col + 1) |
            _mask_square(row - 1, col - 2) | _mask_square(row - 1, col + 2) |
            _mask_square(row + 1, col - 2) | _mask_square(row + 1, col + 2) |
            _mask_square(row + 2, col - 1) | _mask_square(row + 2, col + 1);
}

#define _mask_gen_(name, row_inc, col_inc) \
static bfd64 _mask_## name(const Brd * brd, int row, int col) \
{ \
    bfd64 mask = _mask_square(row, col); \
    if (! mask) return 0; \
    if (! square_no_piece(* Brd_get_row_col(brd, row, col))) return mask; \
    return mask | _mask_## name(brd, row + row_inc, col + col_inc); \
}

_mask_gen_(up, -1, 0)
_mask_gen_(down, 1, 0)
_mask_gen_(left, 0, -1)
_mask_gen_(right, 0, 1)
_mask_gen_(lu, -1, -1)
_mask_gen_(ru, -1, 1)
_mask_gen_(dl, 1, -1)
_mask_gen_(dr, 1, 1)

static bfd64 _mask_attack_rook(const Brd * brd, int row, int col)
{
    return _mask_up(brd, row - 1, col) | _mask_down(brd, row + 1, col) |
            _mask_left(brd, row, col - 1) | _mask_right(brd, row, col + 1);
}

static bfd64 _mask_attack_bishop(const Brd * brd, int row, int col)
{
    return _mask_lu(brd, row - 1, col - 1) | _mask_ru(brd, row - 1, col + 1) |
            _mask_dl(brd, row + 1, col - 1) | _mask_dr(brd, row + 1, col + 1);
}

static bfd64 _mask_attack_queen(const Brd * brd, int row, int col)
{
    return _mask_attack_rook(brd, row, col) | _mask_attack_bishop(brd, row, col);
}

bfd64 mask_attack_row_col(const Brd * brd, int row, int col)
{
    square sqr;

    sqr = * Brd_get_row_col(brd, row, col);

    if (square_no_piece(sqr))   return 0;
    if (square_white_pawn(sqr)) return _mask_attack_wp(row, col);
    if (square_black_pawn(sqr)) return _mask_attack_bp(row, col);
    if (square_king(sqr))       return _mask_attack_king(row, col);
    if (square_rook(sqr))       return _mask_attack_rook(brd, row, col);
    if (square_knight(sqr))     return _mask_attack_knight(row, col);
    if (square_bishop(sqr))     return _mask_attack_bishop(brd, row, col);
    if (square_queen(sqr))      return _mask_attack_queen(brd, row, col);

    return 0;
}

bfd64 mask_attack(const Brd * brd, int idx)
{
    return mask_attack_row_col(brd, Brd_idx_row(idx), Brd_idx_col(idx));
}

bfd64 _mask_move_wpn(const Brd * brd, int row, int col, int n)
{
    return square_no_piece(* Brd_get_row_col(brd, row - n, col)) ? bfd64_one(Brd_row_col_idx(row - n, col)) : 0;
}

bfd64 _mask_move_bpn(const Brd * brd, int row, int col, int n)
{
    return square_no_piece(* Brd_get_row_col(brd, row + n, col)) ? bfd64_one(Brd_row_col_idx(row + n, col)) : 0;
}

bfd64 _mask_move_wp(const Brd * brd, int row, int col)
{
    bfd64 mask;

    if (row == 0) return 0;
    if (Brd_last_row(row)) return 0;

    mask = _mask_move_wpn(brd, row, col, 1);
    if (mask && (row == BRD_SIZE - 2)) return mask | _mask_move_wpn(brd, row, col, 2);

    return mask;
}

bfd64 _mask_move_bp(const Brd * brd, int row, int col)
{
    bfd64 mask;

    if (row == 0) return 0;
    if (Brd_last_row(row)) return 0;

    mask = _mask_move_bpn(brd, row, col, 1);
    if (mask && row == 1) return mask | _mask_move_bpn(brd, row, col, 2);

    return mask;
}

bfd64 mask_move_row_col(const Brd * brd, int row, int col)
{
    if (square_white_pawn(* Brd_get_row_col(brd, row, col))) return _mask_move_wp(brd, row, col);
    if (square_black_pawn(* Brd_get_row_col(brd, row, col))) return _mask_move_bp(brd, row, col);

    return mask_attack_row_col(brd, row, col);
}

bfd64 mask_move(const Brd * brd, int idx)
{
    return mask_move_row_col(brd, Brd_idx_row(idx), Brd_idx_col(idx));
}