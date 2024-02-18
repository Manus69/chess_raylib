#include "_private.h"

PosAnal PosAnal_compute(const Brd * brd)
{
    PosAnal pa = {};
    CLR     clr;
    char    piece;

    for (int k = 0; k < BRD_NSQUARES; k ++)
    {
        piece = * Brd_get(brd, k);
        if ((clr = CLR_get(piece)) == CLR_COUNT) continue ;

        if (is_king(piece)) pa.king_idx[clr] = k;

        bfd64_set(& pa.pos_mask[clr], k);
        pa.attack_mask[clr] |= Brd_get_square_attack_mask(brd, k);
        pa.material[clr] += piece_val(piece);
    }

    return pa;
}