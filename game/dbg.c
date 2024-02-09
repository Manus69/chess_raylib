#include <stdio.h>
#include <string.h>

#include "../lib/mylib.h"
#include "Game.h"

#define DBG_SQUARE_EMPTY    SQ_ES
#define DBG_SQUARE_NE       'x'

void Brd_dbg_dump(void * target, const Brd * brd)
{
    memcpy(target, brd->board, BRD_NSQUARES);
}

static void _dbg_row(const Brd * board, int row)
{
    for (int k = 0; k < BRD_SIZE; k ++) printf("%c ", * Brd_get_row_col(board, row, k));
    nl_;
}

void dbg_Brd(const Brd * board)
{
    for (int row = 0; row < BRD_SIZE; row ++) _dbg_row(board, row);
    nl_;
}

void dbg_mask_numeric(mask msk)
{
    printf("%lx\n", msk);
    nl_;
}

static void _dbg_mask_slice(mask msk, int idx)
{
    char buff[] = {DBG_SQUARE_EMPTY, DBG_SQUARE_NE};

    for (int k = 0; k < BRD_SIZE; k ++)
    {
        printf("%c", buff[bfd64_bit_is_set(msk, idx * BRD_SIZE + k)]);
    }
}

void dbg_mask(mask msk)
{
    for (int k = 0; k < BRD_SIZE; k ++)
    {
        _dbg_mask_slice(msk, k);
        nl_;
    }
}