#include "Game.h"

static BrdInfo _init(void)
{
    return (BrdInfo)
    {
        .b_king_idx = NO_IDX,
        .w_knig_idx = NO_IDX,
    };
}

BrdInfo BrdInfo_compute(const Brd * brd)
{
    BrdInfo bi;
    square  sqr;
    bfd64   mask;

    bi = _init();
    for (int k = 0; k < BRD_NSQUARES; k ++)
    {
        sqr = * Brd_get(brd, k);
        mask = mask_attack(brd, k);

        if (square_white_piece(sqr))
        {
            bi.w_attack_mask |= mask;
            if (square_white_king(sqr)) bi.w_knig_idx = k;    
        }
        else if (square_black_piece(sqr))
        {
            bi.b_attack_mask |= mask;
            if (square_black_king(sqr)) bi.b_king_idx = k;
        }
    }

    return bi;
}

bool BrdInfo_square_attacked_by_white(const BrdInfo * bi, int idx)
{
    return bfd64_bit_is_set(bi->w_attack_mask, idx);
}

bool BrdInfo_square_attacked_by_black(const BrdInfo * bi, int idx)
{
    return bfd64_bit_is_set(bi->b_attack_mask, idx);
}

bool BrdInfo_white_in_check(const BrdInfo * bi)
{
    return BrdInfo_square_attacked_by_black(bi, bi->w_knig_idx);
}

bool BrdInfo_black_in_check(const BrdInfo * bi)
{
    return BrdInfo_square_attacked_by_white(bi, bi->b_king_idx);
}
