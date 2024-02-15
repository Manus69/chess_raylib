#include "_private.h"

#define V_DFLT ((Vector2){})
#define T_DFLT (RAYWHITE)

void render_board(const Gui * gui)
{
    DrawTexturePro(gui->texture, gui->tx_layout.obj[GUI_OBJ_BOARD], gui->repr.board->rect, V_DFLT, 0, T_DFLT);
}

void render_pieces(const Gui * gui)
{
    Obj * current;

    for (int k = 0; k < gui->store.n_pieces; k ++)
    {
        current = Gui_store_get(gui, k);
        DrawTexturePro(gui->texture, gui->tx_layout.obj[current->type], current->rect, V_DFLT, 0, T_DFLT);
    }
}

void Gui_render(const Gui * gui)
{
    BeginDrawing();
    ClearBackground(BLACK);
    render_board(gui);
    render_pieces(gui);
    EndDrawing();
}