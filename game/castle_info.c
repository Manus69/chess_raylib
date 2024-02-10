#include "Game.h"

#define KING    1
#define LROOK   2
#define RROOK   4

void ci_left_rook_moved(castle_info * ci)
{
    * ci |= LROOK;
}

void ci_right_rook_moved(castle_info * ci)
{
    * ci |= RROOK;
}

void ci_king_moved(castle_info * ci)
{
    * ci |= KING;
}

bool ci_can_castle_left(castle_info ci)
{
    return ! ((ci & KING) | (ci & LROOK));
}

bool ci_can_castle_right(castle_info ci)
{
    return ! ((ci & KING) | (ci & RROOK));
}

