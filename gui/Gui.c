#include "Gui.h"
#include <stdio.h>

extern const GuiLayout  GL_DFLT;
extern const TxLayout   TXL_DFLT;

Gui Gui_init(GuiLayout gl, TxLayout txl, const char * tx_path)
{
    Gui gui;

    InitWindow(gl.window.width, gl.window.height, "");

    gui.texture = LoadTexture(tx_path);
    gui.board = Board_init(& gl);
    gui.gui_layout = gl;
    gui.tx_layout = txl;
    gui.input = (Input) {NO_IDX};

    return gui;
}

void Gui_kill(Gui * gui)
{
    UnloadTexture(gui->texture);
    CloseWindow();
}

bool Gui_board_clicked(const Gui * gui, Vector2 xy)
{
    return CheckCollisionPointRec(xy, gui->gui_layout.board);
}

static void _piece_click(Gui * gui, int idx, Vector2 xy)
{
    gui->input.active_idx = idx;
    Piece_move_center(Board_get(& gui->board, idx), xy, gui->input.active_idx);
}

static void _board_click(Gui * gui, Vector2 xy)
{
    int idx;

    if ((idx = Board_piece_hovered(& gui->board, xy)) != NO_IDX) return _piece_click(gui, idx, xy);
}

static void _click(Gui * gui, Vector2 xy)
{
    if (Gui_board_clicked(gui, xy)) _board_click(gui, xy);
}

static void _button_down(Gui * gui, Vector2 xy)
{
    if (gui->input.active_idx != NO_IDX) Piece_move_center(Board_get(& gui->board, gui->input.active_idx), xy, gui->board.square_size / 2);
}

static void _unclick(Gui * gui)
{
    gui->input.active_idx = NO_IDX;
}

static void _handle_events(Gui * gui)
{
    Vector2 xy;

    xy = GetMousePosition();

    if      (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))   _click(gui, xy);
    else if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))  _unclick(gui);
    else if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))      _button_down(gui, xy);
}

int Gui_run(void)
{
    Gui gui;
    
    gui = Gui_init(GL_DFLT, TXL_DFLT, GUI_TX_PATH);

    Board_place(& gui.board, 1, 2, GUI_PC_WK);

    while (! WindowShouldClose())
    {
        _handle_events(& gui);
        render_Gui(& gui);
    }
    
    Gui_kill(& gui);

    return 0;
}