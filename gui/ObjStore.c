#include "_private.h"
#include <string.h>

Obj * Gui_store_current(const Gui * gui)
{
    return (Obj *) & gui->store.pieces[gui->store.n_pieces];
}

Obj * Gui_store_get(const Gui * gui, int idx)
{
    return (Obj *) & gui->store.pieces[idx];
}

void Gui_add_board(Gui * gui)
{
    gui->store.board = Obj_new(GUI_OBJ_BOARD, gui->gui_layout.board);
    gui->repr.board = & gui->store.board;
}

void Gui_add_piece_to_board(Gui * gui, int idx, GUI_OBJ type)
{
    Obj *       current;
    Rectangle   rect;

    rect = Repr_get_grid_rect(gui, idx);
    current = Gui_store_current(gui);

    * current = Obj_new(type, rect);
    gui->repr.grid[idx] = current;
    gui->store.n_pieces ++;
}

void Gui_clear_board(Gui * gui)
{
    memset(gui->repr.grid, 0, sizeof(gui->repr.grid));
    gui->store.n_pieces = 0;
}