#include "Gui.h"

Board Board_init(const GuiLayout * layout)
{
    Board brd = {};
    float square_size;

    square_size = layout->board.width / GUI_GRID_SIZE;

    for (int row = 0; row < GUI_GRID_SIZE; row ++)
    {
        for (int col = 0; col < GUI_GRID_SIZE; col ++)
        {
            brd.board_grid[row][col] = (Vector2)
                                        {
                                            .x = layout->board.x + col * square_size,
                                            .y = layout->board.y + row * square_size,
                                        };
        }
    }

    brd.square_size = square_size;
    
    return brd;
}

void Board_place(Board * board, int row, int col, GUI_PC piece)
{
    board->pieces[board->n_pieces ++] = (Piece)
                                        {
                                            .type = piece,
                                            .xy = board->board_grid[row][col],
                                            .xy_initial = board->board_grid[row][col],
                                        };
}

int Board_piece_hovered(const Board * board, Vector2 xy)
{
    Rectangle rect;

    for (int k = 0; k < board->n_pieces; k ++)
    {
        rect = (Rectangle) {board->pieces[k].xy.x, board->pieces[k].xy.y, board->square_size, board->square_size};
        if (CheckCollisionPointRec(xy, rect)) return k;
    }

    return NO_IDX;
}

Piece * Board_get(const Board * board, int idx)
{
    return (Piece *) & board->pieces[idx];
}