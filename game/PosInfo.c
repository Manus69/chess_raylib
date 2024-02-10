#include "Game.h"

PosInfo PosInfo_compute(const Pos * pos)
{
    PosInfo pi = {};
    bfd64   mask;

    for (int row = 0; row < BRD_SIZE; row ++)
    {
        for (int col = 0; col < BRD_SIZE; col ++)
        {
            mask = mask_attack_mask_row_col(& pos->brd, row, col);
            if (square_white_piece(* Brd_get_row_col(& pos->brd, row, col))) pi.w_attack_mask |= mask;
            else pi.b_attack_mask |= mask;
        }
    }

    return pi;
}