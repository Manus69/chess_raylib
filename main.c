#include <stdio.h>
#include <stdlib.h>
#include "./game/Game.h"

int main()
{
    Brd b = Brd_new_default();
    dbg_Brd(& b);

    mask msk = mask_mask_Brd(& b);
    dbg_mask_numeric(msk);
    dbg_mask(msk);

    msk = mask_mask_white(& b);
    dbg_mask(msk);

    msk = mask_mask_black(& b);
    dbg_mask(msk);

    return 0;
}