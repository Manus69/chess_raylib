#include "_private.h"

#define _amask_gen_(dir, drow, dcol) \
static bfd64 _am_ ## dir(const Brd * brd, int row, int col) \
{ \
    bfd64 mask = 0;  \
    bfd64 current; \
 \
    while (true) \
    { \
        row += drow; \
        col += dcol; \
        current = _mask_empty_square(brd, row, col); \
        mask |= current; \
 \
        if (! current) return mask |= _mask_square(row, col); \
    } \
}

static bfd64 _mask_square(int row, int col)
{
    if (row_valid(row) && col_valid(col)) return bfd64_one(transform_rc_idx(row, col));

    return 0;
}

static bfd64 _mask_empty_square(const Brd * brd, int row, int col)
{
    return Brd_square_empty_rc(brd, row, col) ? _mask_square(row, col) : 0;
}

_amask_gen_(up, -1, 0)
_amask_gen_(down, 1, 0)
_amask_gen_(left, 0, -1)
_amask_gen_(right, 0, 1)
_amask_gen_(ul, -1, -1)
_amask_gen_(ur, -1, 1)
_amask_gen_(dl, 1, -1)
_amask_gen_(dr, 1, 1)

static bfd64 _b_pawn_am(int row, int col)
{
    return _mask_square(row + 1, col - 1) | _mask_square(row + 1, col + 1);
}

static bfd64 _w_pawn_am(int row, int col)
{
    return _mask_square(row - 1, col - 1) | _mask_square(row - 1, col + 1);
}

static bfd64 _pawn_am(const Brd * brd, int row, int col)
{
    return CLR_get(* Brd_get_rc(brd, row, col)) == CLR_WHITE ? _w_pawn_am(row, col) : _b_pawn_am(row, col);
}

static bfd64 _king_am(int row, int col)
{
    return _mask_square(row - 1, col - 1) | _mask_square(row - 1, col) | _mask_square(row - 1, col + 1) |
            _mask_square(row, col - 1) | _mask_square(row, col + 1) |
            _mask_square(row + 1, col - 1) | _mask_square(row + 1, col) | _mask_square(row + 1, col + 1);
}

static bfd64 _knight_am(int row, int col)
{
    return _mask_square(row - 1, col - 2) | _mask_square(row - 2, col - 1) | 
            _mask_square(row - 2, col + 1) | _mask_square(row - 1, col + 2) |
            _mask_square(row + 1, col - 2) | _mask_square(row + 2, col - 1) |
            _mask_square(row + 2, col - 1) | _mask_square(row + 1, col + 2);
}

static bfd64 _bishop_am(const Brd * brd, int row, int col)
{
    return _am_ul(brd, row, col) | _am_ur(brd, row, col) | _am_dl(brd, row, col) | _am_dr(brd, row, col);
}

static bfd64 _rook_am(const Brd * brd, int row, int col)
{
    return _am_up(brd, row, col) | _am_down(brd, row, col) | _am_left(brd, row, col) | _am_right(brd, row, col);
}

static bfd64 _queen_am(const Brd * brd, int row, int col)
{
    return _rook_am(brd, row, col) | _bishop_am(brd, row, col);
}

bfd64 Brd_get_square_attack_mask_rc(const Brd * brd, int row, int col)
{
    char square;

    square = * Brd_get_rc(brd, row, col);

    if (square == BRD_ES) return 0;
    if (square == BRD_WP) return _w_pawn_am(row, col);
    if (square == BRD_BP) return _b_pawn_am(row, col);
    if (square == BRD_WK) return _king_am(row, col);
    if (square == BRD_BK) return _king_am(row, col);
    if (square == BRD_WN) return _knight_am(row, col);
    if (square == BRD_BN) return _knight_am(row, col);
    if (square == BRD_WR) return _rook_am(brd, row, col);
    if (square == BRD_BR) return _rook_am(brd, row, col);
    if (square == BRD_WB) return _bishop_am(brd, row, col);
    if (square == BRD_BB) return _bishop_am(brd, row, col);
    if (square == BRD_WQ) return _queen_am(brd, row, col);
    if (square == BRD_BQ) return _queen_am(brd, row, col);

    return 0;
}

bfd64 Brd_get_square_attack_mask(const Brd * brd, int idx)
{
    return Brd_get_square_attack_mask_rc(brd, transform_idx_row(idx), transform_idx_col(idx));
}
