#include "_private.h"

#define VAL_PAWN    (1)
#define VAL_ROOK    (5)
#define VAL_KNIGHT  (3)
#define VAL_BISHOP  (3)
#define VAL_QUEEN   (9)

bool is_pawn(char x)
{
    return x == BRD_WP || x == BRD_BP;
}

bool is_rook(char x)
{
    return x == BRD_WR || x == BRD_BR;
}

bool is_knight(char x)
{
    return x == BRD_WN || x == BRD_BN;
}

bool is_bishop(char x)
{
    return x == BRD_WB || x == BRD_BB;
}

bool is_queen(char x)
{
    return x == BRD_WQ || x == BRD_BQ;
}

bool is_king(char x)
{
    return x == BRD_WK || x == BRD_BK;
}

char piece_val(char x)
{
    return  is_pawn(x) * VAL_PAWN + 
            is_rook(x) * VAL_ROOK + 
            is_knight(x) * VAL_KNIGHT +
            is_bishop(x) * VAL_BISHOP +
            is_queen(x) * VAL_QUEEN;
}