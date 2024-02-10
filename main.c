#include <stdio.h>
#include <stdlib.h>
#include "./game/Game.h"

int main()
{
    // Brd brd = Brd_new_default();

    // bfd64 msk = mask_attack_mask_row_col(& brd, 0, 1);
    // dbg_mask(msk);
    // dbg_mask_numeric(msk);

    Brd brd = Brd_new_empty();
    Brd_set_row_col(& brd, 3, 3, BRD_WQ);
    Brd_set_row_col(& brd, 1, 3, BRD_WB);

    bfd64 mask = mask_attack_mask_row_col(& brd, 3, 3);
    dbg_mask(mask);

    return 0;
}