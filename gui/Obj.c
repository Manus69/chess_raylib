#include "_private.h"

Obj Obj_new(GUI_OBJ type, Rectangle rect)
{
    return (Obj)
    {
        .type = type,
        .rect = rect,
    };
}

void Obj_center_at(Obj * obj, Vector2 xy)
{
    obj->rect.x = xy.x - obj->rect.width / 2;
    obj->rect.y = xy.y - obj->rect.height / 2;
}