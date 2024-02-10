#include "Game.h"

bool square_white_piece(square sqr)
{
    return char_is_lower(sqr);
}

bool square_black_piece(square sqr)
{
    return char_is_upper(sqr);
}

bool square_no_piece(square sqr)
{
    return sqr == BRD_ES;
}

bool square_white_pawn(square sqr)
{
    return sqr == BRD_WP;
}

bool square_white_rook(square sqr)
{
    return sqr == BRD_WR;
}

bool square_white_knight(square sqr)
{
    return sqr == BRD_WN;
}

bool square_white_bishop(square sqr)
{
    return sqr == BRD_WB;
}

bool square_white_queen(square sqr)
{
    return sqr == BRD_WQ;
}

bool square_white_king(square sqr)
{
    return sqr == BRD_WK;
}

bool square_black_pawn(square sqr)
{
    return sqr == BRD_BP;
}

bool square_black_rook(square sqr)
{
    return sqr == BRD_BR;
}

bool square_black_knight(square sqr)
{
    return sqr == BRD_BN;
}

bool square_black_bishop(square sqr)
{
    return sqr == BRD_BB;
}

bool square_black_queen(square sqr)
{
    return sqr == BRD_BQ;
}

bool square_black_king(square sqr)
{
    return sqr == BRD_BK;
}

bool square_rook(square sqr)
{
    return square_white_rook(sqr) || square_black_rook(sqr);
}

bool square_knight(square sqr)
{
    return square_white_knight(sqr) || square_black_knight(sqr);
}

bool square_bishop(square sqr)
{
    return square_white_bishop(sqr) || square_black_bishop(sqr);
}

bool square_queen(square sqr)
{
    return square_white_queen(sqr) || square_black_queen(sqr);
}

bool square_king(square sqr)
{
    return square_white_king(sqr) || square_black_king(sqr);
}
