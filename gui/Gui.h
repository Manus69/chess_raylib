#ifndef GUI_H
#define GUI_H

#include <raylib.h>
#include "../lib/mylib.h"

typedef struct Gui      Gui;
typedef struct GuiSts   GuiSts;
typedef enum    GUI_OBJ     GUI_OBJ;

enum GUI_OBJ
{
    GUI_OBJ_NONE,
    GUI_OBJ_BOARD,
    GUI_OBJ_WR,
    GUI_OBJ_WN,
    GUI_OBJ_WB,
    GUI_OBJ_WQ,
    GUI_OBJ_WK,
    GUI_OBJ_WP,
    GUI_OBJ_BR,
    GUI_OBJ_BN,
    GUI_OBJ_BB,
    GUI_OBJ_BQ,
    GUI_OBJ_BK,
    GUI_OBJ_BP,
    GUI_OBJ_COUNT,
};

struct GuiSts
{
    char from;
    char to;
    bool move;
};

Gui *   Gui_init(int ww, int wh);
void    Gui_kill(Gui * gui);
void    Gui_render(const Gui * gui);
GuiSts  Gui_handle_events(Gui * gui);
void    Gui_dbg(const Gui * gui);
void    Gui_set_board(Gui * gui, const char * cstr, GUI_OBJ (* translate)(char));

#endif