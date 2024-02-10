#include "../mylib.h"

bfd64 bfd64_zeroes(void)
{
    return 0;
}

bfd64 bfd64_ones(void)
{
    return ~ 0ul;
}

bfd64 bfd64_one(int idx)
{
    return 1ul << idx;
}

bfd64 bfd64_from_hex(u64 x)
{
    return x;
}

bool bfd64_bit_is_set(bfd64 bfd, int idx)
{
    return bfd & (1ul << idx);
}

bfd64 bfd64_set(bfd64 * bfd, int idx)
{
    return * bfd |= (1ul << idx);
}

bfd64 bfd64_clear(bfd64 * bfd, int idx)
{
    return * bfd &= ~(1ul << idx);
}

bfd64 bfd64_toggle(bfd64 * bfd, int idx)
{
    return * bfd ^= (1ul << idx);
}

bfd64 bfd64_shift_left(bfd64 * bfd, int shift)
{
    return * bfd >>= shift;
}

bfd64 bfd64_shift_right(bfd64 * bfd, int shift)
{
    return * bfd <<= shift;
}

bfd64 bfd64_union(bfd64 lhs, bfd64 rhs)
{
    return lhs | rhs;
}