#include "_private.h"
#include <stdio.h>

static void _select(Gui * gui, Obj * obj, int idx)
{
    gui->selection.obj = obj;
    gui->selection.initial_rect = obj->rect;
    gui->selection.square_idx = idx;
}

static void _unselect(Gui * gui)
{
    gui->selection.obj = NULL;
    gui->selection.square_idx = NO_IDX;
    gui->selection.initial_rect = (Rectangle) {};
}

static void _restore_piece(Gui * gui)
{
    gui->selection.obj->rect = Repr_get_grid_rect(gui, gui->selection.square_idx);
}

static GuiSts _square_click(Gui * gui, int idx, Vector2 xy)
{
    Obj * obj;

    obj = Repr_get_grid_obj(gui, idx);
    if (! obj) return GuiSts_no_move();

    _select(gui, obj, idx);
    Obj_center_at(gui->selection.obj, xy);

    return GuiSts_no_move();
}

static GuiSts _click(Gui * gui, Vector2 xy)
{
    int idx;

    // Gui_dbg(gui);
    //

    idx = Repr_grid_hovered(gui, xy);
    if (idx != NO_IDX) return _square_click(gui, idx, xy);

    return GuiSts_no_move();
}

static GuiSts _button_down(Gui * gui, Vector2 xy)
{
    // Gui_dbg(gui);
    //

    if (gui->selection.obj)
    {
        Obj_center_at(gui->selection.obj, xy);
    }

    return GuiSts_no_move();
}

static GuiSts _unclick(Gui * gui, Vector2 xy)
{
    int     idx;
    GuiSts  sts;

    // Gui_dbg(gui);
    //
    if (! gui->selection.obj) return GuiSts_no_move();

    idx = Repr_grid_hovered(gui, xy);
    if (idx == NO_IDX)
    {
        _restore_piece(gui);
        sts = GuiSts_no_move();
    }
    else
    {
        sts = GuiSts_move(gui->selection.square_idx, idx);
    }

    _unselect(gui);

    return sts;
}

GuiSts Gui_handle_events(Gui * gui)
{
    Vector2 xy;

    xy = GetMousePosition();

    if      (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))   return _click(gui, xy);
    else if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))  return _unclick(gui, xy);
    else if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))      return _button_down(gui, xy);

    return GuiSts_no_move();
}