#include <stdio.h>
#include <stdlib.h>
#include "./game/Game.h"

int main()
{
    Pos pos = Pos_new_default();
    PosInfo pi = PosInfo_compute(& pos);
    dbg_PosInfo(& pi);

    return 0;
}