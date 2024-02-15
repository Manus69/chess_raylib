#include "_private.h"

extern const TxLayout   TXL_DFLT;

Gui * Gui_init(int ww, int wh)
{
    Gui *   gui;
    Layout  layout;

    if ((gui = calloc(1, sizeof(* gui))))
    {
        layout = Layout_default(ww, wh);
        InitWindow(layout.window.width, layout.window.height, "");

        gui->gui_layout = layout;
        gui->tx_layout = TXL_DFLT;
        gui->texture = LoadTexture(GUI_TX_PATH);
        Gui_add_board(gui);

        //
        Gui_add_piece_to_board(gui, 10, GUI_OBJ_BB);
        //

        return gui;
    }

    return NULL;
}

void Gui_kill(Gui * gui)
{
    UnloadTexture(gui->texture);
    CloseWindow();
    free(gui);
}

void Gui_set_board(Gui * gui, const char * cstr, GUI_OBJ (* translate)(char))
{
    GUI_OBJ type;

    Gui_clear_board(gui);
    for (int k = 0; k < GUI_GRID_SIZE * GUI_GRID_SIZE; k ++)
    {
        type = translate(cstr[k]);
        if (type != GUI_OBJ_NONE) Gui_add_piece_to_board(gui, k, type);
    }
}
