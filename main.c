#include <stdio.h>
#include <stdlib.h>
#include "./game/Game.h"

int main()
{
    Brd b = Brd_new_default();
    dbg_Brd(& b);

    bfd64 msk = mask_Brd(& b);
    dbg_mask_numeric(msk);
    dbg_mask(msk);

    msk = mask_white(& b);
    dbg_mask(msk);

    msk = mask_black(& b);
    dbg_mask(msk);

    msk = mask_attack_mask_row_col(& b, 6, 7);
    dbg_mask(msk);

    return 0;
}