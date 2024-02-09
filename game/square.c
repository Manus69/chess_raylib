#include "Game.h"

bool square_is_white_piece(square pc)
{
    return pc >= 'a' && pc <= 'z';
}

bool square_is_black_piece(square pc)
{
    return pc >= 'A' && pc <= 'Z';
}

bool square_no_piece(square pc)
{
    return pc == SQ_ES;
}