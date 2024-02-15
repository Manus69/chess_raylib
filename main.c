#include "./game/chess.h"
#include "./gui/Gui.h"

#include <stdlib.h>
#include <stdio.h>

static GUI_OBJ _translate(char x)
{
    if (x == BRD_BP) return GUI_OBJ_BP;
    if (x == BRD_BR) return GUI_OBJ_BR;
    if (x == BRD_BN) return GUI_OBJ_BN;
    if (x == BRD_BB) return GUI_OBJ_BB;
    if (x == BRD_BQ) return GUI_OBJ_BQ;
    if (x == BRD_BK) return GUI_OBJ_BK;
    if (x == BRD_WP) return GUI_OBJ_WP;
    if (x == BRD_WR) return GUI_OBJ_WR;
    if (x == BRD_WN) return GUI_OBJ_WN;
    if (x == BRD_WB) return GUI_OBJ_WB;
    if (x == BRD_WQ) return GUI_OBJ_WQ;
    if (x == BRD_WK) return GUI_OBJ_WK;

    return GUI_OBJ_NONE;
}

static int _gui(void)
{
    Gui *   gui;
    GuiSts  sts;
    Pos     pos;
    
    pos = Pos_from_cstr(BRD_DFLT);
    gui = Gui_init(1000, 800);
    Gui_set_board(gui, Pos_Brd_get_cstr(& pos), _translate);

    while (! WindowShouldClose())
    {
        Gui_render(gui);
        sts = Gui_handle_events(gui);
    }

    Gui_kill(gui);

    return 0;
}

static int _test()
{
    printf("%zu\n", sizeof(Pos));
    return 0;
}

int main()
{
    // return _test();
    return _gui();
}