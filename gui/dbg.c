#include "_private.h"
#include <stdio.h>

static void _dbg_obj(const Obj * obj)
{
    if (obj) printf("obj %p\nx %f y % f\n", obj, obj->rect.x, obj->rect.y);
    else printf("no obj\n");
}

static void _dbg_selection(const Gui * gui)
{
    _dbg_obj(gui->selection.obj);
    printf("idx %d\n", gui->selection.square_idx);
}

void Gui_dbg(const Gui * gui)
{
    _dbg_selection(gui);
}