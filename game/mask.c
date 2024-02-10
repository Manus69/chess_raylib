#include "Game.h"

bfd64 mask_Brd(const Brd * board)
{
    bfd64 msk;

    msk = 0;
    for (int k = 0; k < BRD_NSQUARES; k ++)
    {
        if (! Brd_empty_square(board, k)) bfd64_set(& msk, k);
    }

    return msk;
}

bfd64 mask_white(const Brd * board)
{
    bfd64 msk;

    msk = 0;
    for (int k = 0; k < BRD_NSQUARES; k ++)
    {
        if (Brd_white_piece(board, k)) bfd64_set(& msk, k);
    }

    return msk;
}

bfd64 mask_black(const Brd * board)
{
    bfd64 msk;

    msk = 0;
    for (int k = 0; k < BRD_NSQUARES; k ++)
    {
        if (Brd_black_piece(board, k)) bfd64_set(& msk, k);
    }

    return msk;
}

static bfd64 _attack_mask_wp(const Brd * brd, int row, int col)
{
    int     left;
    int     right;
    bfd64   mask;

    (void) brd;
    if (row == 0) return 0;

    left = Brd_row_col_idx(row - 1, col - 1);
    right = Brd_row_col_idx(row - 1, col + 1);

    mask = bfd64_zeroes();
    if (col == 0) return bfd64_set(& mask, right);
    if (col == BRD_SIZE - 1) return bfd64_set(& mask, left);

    bfd64_set(& mask, left);
    bfd64_set(& mask, right);

    return mask;
}

static bfd64 _attack_mask_bp(const Brd * brd, int row, int col)
{
    int     left;
    int     right;
    bfd64   mask;

    (void) brd;
    if (row == BRD_SIZE - 1) return 0;

    left = Brd_row_col_idx(row + 1, col - 1);
    right = Brd_row_col_idx(row + 1, col + 1);

    mask = bfd64_zeroes();
    if (col == 0) return bfd64_set(& mask, right);
    if (col == BRD_SIZE - 1) bfd64_set(& mask, left);

    bfd64_set(& mask, left);
    bfd64_set(& mask, right);

    return mask;
}

bfd64 mask_attack_mask_row_col(const Brd * brd, int row, int col)
{
    if (Brd_empty_square_row_col(brd, row, col)) return bfd64_zeroes();
    if (Brd_white_pawn_row_col(brd, row, col)) return _attack_mask_wp(brd, row, col);

    return bfd64_zeroes();
}

bfd64 mask_attack_mask(const Brd * brd, int idx)
{
    return mask_attack_mask_row_col(brd, Brd_idx_row(idx), Brd_idx_col(idx));
}