#include "_private.h"

CLR CLR_get(char x)
{
    if (char_is_lower(x)) return CLR_WHITE;
    if (char_is_upper(x)) return CLR_BLACK;

    return CLR_COUNT;
}

bool CLR_same(char lhs, char rhs)
{
    return CLR_get(lhs) == CLR_get(rhs);
}