#include "_private.h"

bool Repr_board_hovered(const Gui * gui, Vector2 xy)
{
    return CheckCollisionPointRec(xy, gui->repr.board->rect);
}

int Repr_grid_hovered(const Gui * gui, Vector2 xy)
{
    int row, col;

    if (Repr_board_hovered(gui, xy))
    {
        row = (xy.y - gui->repr.board->rect.y) / gui->gui_layout.square_size;
        col = (xy.x - gui->repr.board->rect.x) / gui->gui_layout.square_size;

        return transform_rc_idx(row, col);
    }

    return NO_IDX;
}

Obj * Repr_get_grid_obj(const Gui * gui, int idx)
{
    return (Obj *) gui->repr.grid[idx];
}

Rectangle Repr_get_grid_rect(const Gui * gui, int idx)
{
    int row, col;

    row = transform_idx_row(idx);
    col = transform_idx_col(idx);

    return (Rectangle)
    {
        .x = gui->repr.board->rect.x + gui->gui_layout.square_size * col,
        .y = gui->repr.board->rect.y + gui->gui_layout.square_size * row,
        .height = gui->gui_layout.square_size,
        .width = gui->gui_layout.square_size,
    };
}