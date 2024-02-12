#include "Gui.h"

#define V_DFLT ((Vector2){})
#define T_DFLT (RAYWHITE)

void render_board(const Gui * gui)
{
    DrawTexturePro(gui->texture, gui->tx_layout.board, gui->gui_layout.board, V_DFLT, 0, T_DFLT);
}

static void _render_piece(const Gui * gui, int idx)
{
    Piece *     pc;
    Rectangle   rect;

    pc = Board_get(& gui->board, idx);
    rect = (Rectangle) {pc->xy.x, pc->xy.y, gui->board.square_size, gui->board.square_size};

    DrawTexturePro(gui->texture, gui->tx_layout.piece[pc->type], rect, V_DFLT, 0, T_DFLT);
}

void render_pieces(const Gui * gui)
{
    for (int k = 0; k < gui->board.n_pieces; k ++)
    {
        _render_piece(gui, k);
    }
}

void render_Gui(const Gui * gui)
{
    BeginDrawing();
    ClearBackground(BLACK);
    render_board(gui);
    render_pieces(gui);
    EndDrawing();
}