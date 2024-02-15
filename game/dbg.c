#include "_private.h"

#define DBG_SQUARE_EMPTY    BRD_ES
#define DBG_SQUARE_NE       'x'

void dbg_mask(bfd64 mask)
{
    for (int k = 0; k < BRD_NSQUARES; k ++)
    {
        printf("%c", bfd64_bit_is_set(mask, k) ? DBG_SQUARE_NE : DBG_SQUARE_EMPTY);
        if (k % BRD_SIZE == 7) nl_;
    }
}