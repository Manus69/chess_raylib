#include "Gui.h"

bool Piece_no_piece(const Piece * piece)
{
    return piece->type == GUI_PC_NONE;
}

void Piece_reset(Piece * piece)
{
    piece->xy = piece->xy_initial;
}

void Piece_shift(Piece * piece, float dx, float dy)
{
    piece->xy.x += dx;
    piece->xy.y += dy;
}

void Piece_move(Piece * piece, Vector2 xy)
{
    piece->xy = xy;
}

void Piece_move_center(Piece * piece, Vector2 xy, float radius)
{
    piece->xy.x = xy.x - radius;
    piece->xy.y = xy.y - radius;
}
