#include "Game.h"

mask mask_mask_Brd(const Brd * board)
{
    mask msk;

    msk = 0;
    for (int k = 0; k < BRD_NSQUARES; k ++)
    {
        if (! Brd_square_empty(board, k)) bfd64_set(& msk, k);
    }

    return msk;
}

mask mask_mask_white(const Brd * board)
{
    mask msk;

    msk = 0;
    for (int k = 0; k < BRD_NSQUARES; k ++)
    {
        if (Brd_square_white_piece(board, k)) bfd64_set(& msk, k);
    }

    return msk;
}

mask mask_mask_black(const Brd * board)
{
    mask msk;

    msk = 0;
    for (int k = 0; k < BRD_NSQUARES; k ++)
    {
        if (Brd_square_black_piece(board, k)) bfd64_set(& msk, k);
    }

    return msk;
}
