#include "Game.h"

bool square_is_white_piece(square pc)
{
    return char_is_lower(pc);
}

bool square_is_black_piece(square pc)
{
    return char_is_upper(pc);
}

bool square_no_piece(square pc)
{
    return pc == BRD_ES;
}

bool square_white_pawn(square pc)
{
    return pc == BRD_WP;
}